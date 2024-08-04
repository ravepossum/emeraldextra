#include "graphics/gimmicks.h"

// Gimmick data

const struct GimmickInfo gGimmicksInfo[GIMMICKS_COUNT] =
{
    [GIMMICK_NONE] = {0},
    [GIMMICK_MEGA] = 
    {
        .triggerSheet = &sSpriteSheet_MegaTrigger,
        .triggerPal = &sSpritePalette_MegaTrigger,
        .triggerPal_dark = &sSpritePalette_MegaTrigger_dark,
        .triggerTemplate = &sSpriteTemplate_GimmickTrigger,
        .indicatorSheet = &sSpriteSheet_MegaIndicator,
        .indicatorPal = &sSpritePalette_MegaIndicator,
        .indicatorPal_dark = &sSpritePalette_MegaIndicator_dark,
        .CanActivate = CanMegaEvolve,
        .ActivateGimmick = ActivateMegaEvolution,
    },
    [GIMMICK_Z_MOVE] = 
    {
        .triggerSheet = &sSpriteSheet_ZMoveTrigger,
        .triggerPal = &sSpritePalette_ZMoveTrigger,
        .triggerPal_dark = &sSpritePalette_ZMoveTrigger,
        .triggerTemplate = &sSpriteTemplate_GimmickTrigger,
        .CanActivate = CanUseZMove,
        .ActivateGimmick = ActivateZMove,
    },
    [GIMMICK_ULTRA_BURST] = 
    {
        .triggerSheet = &sSpriteSheet_BurstTrigger,
        .triggerPal = &sSpritePalette_BurstTrigger,
        .triggerPal_dark = &sSpritePalette_BurstTrigger,
        .triggerTemplate = &sSpriteTemplate_GimmickTrigger,
        .CanActivate = CanUltraBurst,
        .ActivateGimmick = ActivateUltraBurst,
    },
    [GIMMICK_DYNAMAX] = 
    {
        .triggerSheet = &sSpriteSheet_DynamaxTrigger,
        .triggerPal = &sSpritePalette_DynamaxTrigger,
        .triggerPal_dark = &sSpritePalette_DynamaxTrigger,
        .triggerTemplate = &sSpriteTemplate_GimmickTrigger,
        .indicatorSheet = &sSpriteSheet_DynamaxIndicator,
        .indicatorPal = &sSpritePalette_MiscIndicator,
        .indicatorPal_dark = &sSpritePalette_MiscIndicator,
        .CanActivate = CanDynamax,
        .ActivateGimmick = ActivateDynamax,
    },
    [GIMMICK_TERA] =
    {
        .triggerSheet = &sSpriteSheet_TeraTrigger,
        .triggerPal = &sSpritePalette_TeraTrigger,
        .triggerPal_dark = &sSpritePalette_TeraTrigger,
        .triggerTemplate = &sSpriteTemplate_GimmickTrigger,
        .indicatorSheet = NULL, // handled separately
        .indicatorPal = &sSpritePalette_TeraIndicator,
        .indicatorPal_dark = &sSpritePalette_TeraIndicator,
        .CanActivate = CanTerastallize,
        .ActivateGimmick = ActivateTera,
    }
};
