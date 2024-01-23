#include "global.h"
#include "battle_pyramid.h"
#include "bg.h"
#include "event_data.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "main.h"
#include "menu.h"
#include "map_name_popup.h"
#include "palette.h"
#include "region_map.h"
#include "rtc.h"
#include "start_menu.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "constants/battle_frontier.h"
#include "constants/layouts.h"
#include "constants/region_map_sections.h"
#include "constants/rtc.h"
#include "constants/weather.h"

// static functions
static void Task_MapNamePopUpWindow(u8 taskId);
static void ShowMapNamePopUpWindow(void);
static void LoadMapNamePopUpWindowBgs(void);

static const u16 sMapPopUp_Palette[16] = INCBIN_U16("graphics/interface/map_popup_palette.gbapal");
static const u8 sPopUpWindow_Tiles_Primary[] = INCBIN_U8("graphics/interface/map_popup_primary.4bpp");
static const u8 sPopUpWindow_Tiles_Secondary[] = INCBIN_U8("graphics/interface/map_popup_secondary.4bpp");
static const u8 sPopUpWindow_Tiles_Secondary_Night[] = INCBIN_U8("graphics/interface/map_popup_secondary_night.4bpp");

static const u8 sText_PyramidFloor1[] = _("Pyramid Floor 1");
static const u8 sText_PyramidFloor2[] = _("Pyramid Floor 2");
static const u8 sText_PyramidFloor3[] = _("Pyramid Floor 3");
static const u8 sText_PyramidFloor4[] = _("Pyramid Floor 4");
static const u8 sText_PyramidFloor5[] = _("Pyramid Floor 5");
static const u8 sText_PyramidFloor6[] = _("Pyramid Floor 6");
static const u8 sText_PyramidFloor7[] = _("Pyramid Floor 7");
static const u8 sText_Pyramid[] = _("Pyramid");

static const u8 *const sBattlePyramid_MapHeaderStrings[FRONTIER_STAGES_PER_CHALLENGE + 1] =
{
    sText_PyramidFloor1,
    sText_PyramidFloor2,
    sText_PyramidFloor3,
    sText_PyramidFloor4,
    sText_PyramidFloor5,
    sText_PyramidFloor6,
    sText_PyramidFloor7,
    sText_Pyramid,
};

static bool8 UNUSED StartMenu_ShowMapNamePopup(void)
{
    HideStartMenu();
    ShowMapNamePopup();
    return TRUE;
}

// States and data defines for Task_MapNamePopUpWindow
enum {
    STATE_SLIDE_IN,
    STATE_WAIT,
    STATE_SLIDE_OUT,
    STATE_UNUSED,
    STATE_ERASE,
    STATE_END,
    STATE_PRINT, // For some reason the first state is numerically last.
};

#define POPUP_OFFSCREEN_Y  24
#define POPUP_SLIDE_SPEED  2

#define tState         data[0]
#define tOnscreenTimer data[1]
#define tYOffset       data[2]
#define tIncomingPopUp data[3]
#define tPrintTimer    data[4]

void ShowMapNamePopup(void)
{
    if (FlagGet(FLAG_HIDE_MAP_NAME_POPUP) != TRUE)
    {
        if (!FuncIsActiveTask(Task_MapNamePopUpWindow))
        {
            gPopupTaskId = CreateTask(Task_MapNamePopUpWindow, 100);

            if (MAPPOPUP_ALPHA_BLEND && 
                gWeatherPtr->currWeather != WEATHER_FOG_HORIZONTAL && 
                gWeatherPtr->currWeather != WEATHER_UNDERWATER_BUBBLES)
                SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND);

            gTasks[gPopupTaskId].tState = STATE_PRINT;
            gTasks[gPopupTaskId].tYOffset = POPUP_OFFSCREEN_Y;
        }
        else
        {
            // There's already a pop up window running.
            // Hurry the old pop up offscreen so the new one can appear.
            if (gTasks[gPopupTaskId].tState != STATE_SLIDE_OUT)
                gTasks[gPopupTaskId].tState = STATE_SLIDE_OUT;
            gTasks[gPopupTaskId].tIncomingPopUp = TRUE;
        }
    }
}

static void Task_MapNamePopUpWindow(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case STATE_PRINT:
        // Wait, then create and print the pop up window
        if (++task->tPrintTimer > 30)
        {
            task->tState = STATE_SLIDE_IN;
            task->tPrintTimer = 0;
            ShowMapNamePopUpWindow();
            EnableInterrupts(INTR_FLAG_HBLANK);
            SetHBlankCallback(HBlankCB_DoublePopupWindow);

        }
        break;
    case STATE_SLIDE_IN:
        // Slide the window onscreen.
        task->tYOffset -= POPUP_SLIDE_SPEED;
        if (task->tYOffset <= 0 )
        {
            task->tYOffset = 0;
            task->tState = STATE_WAIT;
            gTasks[gPopupTaskId].tOnscreenTimer = 0;
        }
        break;
    case STATE_WAIT:
        // Wait while the window is fully onscreen.
        if (++task->tOnscreenTimer > 120)
        {
            task->tOnscreenTimer = 0;
            task->tState = STATE_SLIDE_OUT;
        }
        break;
    case STATE_SLIDE_OUT:
        // Slide the window offscreen.
        task->tYOffset += POPUP_SLIDE_SPEED;
        if (task->tYOffset >= POPUP_OFFSCREEN_Y)
        {
            task->tYOffset = POPUP_OFFSCREEN_Y;
            if (task->tIncomingPopUp)
            {
                // A new pop up window is incoming,
                // return to the first state to show it.
                task->tState = STATE_PRINT;
                task->tPrintTimer = 0;
                task->tIncomingPopUp = FALSE;
            }
            else
            {
                task->tState = STATE_ERASE;
                return;
            }
        }
        break;
    case STATE_ERASE:
        ClearStdWindowAndFrame(GetPrimaryPopUpWindowId(), TRUE);
        ClearStdWindowAndFrame(GetSecondaryPopUpWindowId(), TRUE);
        task->tState = STATE_END;
        break;
    case STATE_END:
        HideMapNamePopUpWindow();
        return;
    }
}

void HideMapNamePopUpWindow(void)
{
    if (FuncIsActiveTask(Task_MapNamePopUpWindow))
    {
        ClearStdWindowAndFrame(GetPrimaryPopUpWindowId(), TRUE);
        ClearStdWindowAndFrame(GetSecondaryPopUpWindowId(), TRUE);
        RemovePrimaryPopUpWindow();
        RemoveSecondaryPopUpWindow();
        DisableInterrupts(INTR_FLAG_HBLANK);
        SetHBlankCallback(NULL);
        SetGpuReg_ForcedBlank(REG_OFFSET_BG0VOFS, 0);

        if (MAPPOPUP_ALPHA_BLEND && 
            gWeatherPtr->currWeather != WEATHER_FOG_HORIZONTAL && 
            gWeatherPtr->currWeather != WEATHER_UNDERWATER_BUBBLES)
        {
            SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ);
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_EFFECT_BLEND);
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(8, 10));
        }

        DestroyTask(gPopupTaskId);
    }
}

static void ShowMapNamePopUpWindow(void)
{
    u8 mapDisplayHeader[24];
    u8 *withoutPrefixPtr;
    u8 mapNameX, timeX, mapNameY, timeY, mapNamePopUpWindowId, weatherPopUpWindowId;
    const u8 *mapDisplayHeaderSource;

    mapNameX = 8;
    mapNameY = 2;
    timeX = 5;
    timeY = 8;

    if (MAPPOPUP_ALPHA_BLEND && 
        gWeatherPtr->currWeather != WEATHER_FOG_HORIZONTAL && 
        gWeatherPtr->currWeather != WEATHER_UNDERWATER_BUBBLES)
        SetGpuRegBits(REG_OFFSET_WININ, WININ_WIN0_CLR);

    mapNamePopUpWindowId = AddMapNamePopUpWindow();
    weatherPopUpWindowId = AddWeatherPopUpWindow();

    LoadMapNamePopUpWindowBgs();
    LoadPalette(sMapPopUp_Palette, BG_PLTT_ID(14), 32);

    if (InBattlePyramid())
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP)
        {
            withoutPrefixPtr = &(mapDisplayHeader[3]);
            mapDisplayHeaderSource = sBattlePyramid_MapHeaderStrings[FRONTIER_STAGES_PER_CHALLENGE];
        }
        else
        {
            withoutPrefixPtr = &(mapDisplayHeader[3]);
            mapDisplayHeaderSource = sBattlePyramid_MapHeaderStrings[gSaveBlock2Ptr->frontier.curChallengeBattleNum];
        }
        StringCopy(withoutPrefixPtr, mapDisplayHeaderSource);
    }
    else
    {
        withoutPrefixPtr = &(mapDisplayHeader[3]);
        GetMapName(withoutPrefixPtr, gMapHeader.regionMapSectionId, 0);
    }

    mapDisplayHeader[0] = EXT_CTRL_CODE_BEGIN;
    mapDisplayHeader[1] = EXT_CTRL_CODE_HIGHLIGHT;
    mapDisplayHeader[2] = TEXT_COLOR_TRANSPARENT;

    AddTextPrinterParameterized(mapNamePopUpWindowId, FONT_SHORT, mapDisplayHeader, mapNameX, mapNameY, TEXT_SKIP_DRAW, NULL);

    FormatDecimalTimeWithoutSeconds(withoutPrefixPtr, gLocalTime.hours, gLocalTime.minutes, FALSE);

    AddTextPrinterParameterized(weatherPopUpWindowId, FONT_SMALL, mapDisplayHeader, GetStringRightAlignXOffset(FONT_SMALL, mapDisplayHeader, DISPLAY_WIDTH) - timeX, timeY, TEXT_SKIP_DRAW, NULL);

    CopyWindowToVram(mapNamePopUpWindowId, COPYWIN_FULL);
    CopyWindowToVram(weatherPopUpWindowId, COPYWIN_FULL);
}

static void LoadMapNamePopUpWindowBgs(void)
{
    u8 mapNamePopUpWindowId = GetPrimaryPopUpWindowId();
    u8 weatherPopUpWindowId = GetSecondaryPopUpWindowId();
    u16 regionMapSectionId = gMapHeader.regionMapSectionId;

    if (regionMapSectionId >= KANTO_MAPSEC_START)
    {
        if (regionMapSectionId > KANTO_MAPSEC_END)
            regionMapSectionId -= KANTO_MAPSEC_COUNT;
        else
            regionMapSectionId = 0; // Discard kanto region sections;
    }


    CopyToWindowPixelBuffer(mapNamePopUpWindowId, sPopUpWindow_Tiles_Primary, sizeof(sPopUpWindow_Tiles_Primary), 0);
    
    if (GetTimeOfDay() == TIME_NIGHT)
    {
        CopyToWindowPixelBuffer(weatherPopUpWindowId, sPopUpWindow_Tiles_Secondary_Night, sizeof(sPopUpWindow_Tiles_Secondary_Night), 0);
    }
    else
    {
        CopyToWindowPixelBuffer(weatherPopUpWindowId, sPopUpWindow_Tiles_Secondary, sizeof(sPopUpWindow_Tiles_Secondary), 0);
    }

    PutWindowTilemap(mapNamePopUpWindowId);
    PutWindowTilemap(weatherPopUpWindowId);
}
