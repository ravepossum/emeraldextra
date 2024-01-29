#include "global.h"
#include "rtc.h"
#include "constants/rtc.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"

// iwram bss
//static u16 sErrorStatus;
static struct SiiRtcInfo sRtc;
static u16 sSavedIme;

// iwram common
struct Time gLocalTime;

void RtcDisableInterrupts(void)
{
    sSavedIme = REG_IME;
    REG_IME = 0;
}

void RtcRestoreInterrupts(void)
{
    REG_IME = sSavedIme;
}

struct Time* GetFakeRtc(void)
{
    return &gSaveBlock2Ptr->fakeRTC;
}

u16 RtcGetDayCount(struct SiiRtcInfo *rtc)
{
    return rtc->day;
}

void RtcInit(void)
{

}

u16 RtcGetErrorStatus(void)
{
    return 0;
}

void RtcGetInfo(struct SiiRtcInfo *rtc)
{
    struct Time* time = GetFakeRtc();
    rtc->second = time->seconds;
    rtc->minute = time->minutes;
    rtc->hour = time->hours;
    rtc->day = time->days;
}

void RtcGetStatus(struct SiiRtcInfo *rtc)
{
    RtcDisableInterrupts();
    SiiRtcGetStatus(rtc);
    RtcRestoreInterrupts();
}


u16 RtcCheckInfo(struct SiiRtcInfo *rtc)
{
    return 0;
}

void RtcReset(void)
{
    memset(GetFakeRtc(), 0, sizeof(struct Time));
}

void RtcCalcTimeDifference(struct SiiRtcInfo *rtc, struct Time *result, struct Time *t)
{
    u16 days = RtcGetDayCount(rtc);
    result->seconds = rtc->second - t->seconds;
    result->minutes = rtc->minute - t->minutes;
    result->hours = rtc->hour - t->hours;
    result->days = days - t->days;

    if (result->seconds < 0)
    {
        result->seconds += SECONDS_PER_MINUTE;
        --result->minutes;
    }

    if (result->minutes < 0)
    {
        result->minutes += MINUTES_PER_HOUR;
        --result->hours;
    }

    if (result->hours < 0)
    {
        result->hours += HOURS_PER_DAY;
        --result->days;
    }
}

void RtcCalcLocalTime(void)
{
    RtcGetInfo(&sRtc);
    RtcCalcTimeDifference(&sRtc, &gLocalTime, &gSaveBlock2Ptr->localTimeOffset);
}

bool8 IsBetweenHours(s32 hours, s32 begin, s32 end)
{
    if (end < begin)
        return hours >= begin || hours < end;
    else
        return hours >= begin && hours < end;
}

u8 GetTimeOfDay(void)
{
    RtcCalcLocalTime();
    if (IsBetweenHours(gLocalTime.hours, MORNING_HOUR_BEGIN, MORNING_HOUR_END))
        return TIME_MORNING;
    else if (IsBetweenHours(gLocalTime.hours, EVENING_HOUR_BEGIN, EVENING_HOUR_END))
        return TIME_EVENING;
    else if (IsBetweenHours(gLocalTime.hours, NIGHT_HOUR_BEGIN, NIGHT_HOUR_END))
        return TIME_NIGHT;
    return TIME_DAY;
}

void RtcInitLocalTimeOffset(s32 hour, s32 minute)
{
    RtcCalcLocalTimeOffset(0, hour, minute, 0);
}

void RtcCalcLocalTimeOffset(s32 days, s32 hours, s32 minutes, s32 seconds)
{
    gLocalTime.days = days;
    gLocalTime.hours = hours;
    gLocalTime.minutes = minutes;
    gLocalTime.seconds = seconds;
    RtcGetInfo(&sRtc);
    RtcCalcTimeDifference(&sRtc, &gSaveBlock2Ptr->localTimeOffset, &gLocalTime);
}

void CalcTimeDifference(struct Time *result, struct Time *t1, struct Time *t2)
{
    result->seconds = t2->seconds - t1->seconds;
    result->minutes = t2->minutes - t1->minutes;
    result->hours = t2->hours - t1->hours;
    result->days = t2->days - t1->days;

    if (result->seconds < 0)
    {
        result->seconds += SECONDS_PER_MINUTE;
        --result->minutes;
    }

    if (result->minutes < 0)
    {
        result->minutes += MINUTES_PER_HOUR;
        --result->hours;
    }

    if (result->hours < 0)
    {
        result->hours += HOURS_PER_DAY;
        --result->days;
    }
}

u32 RtcGetMinuteCount(void)
{
    RtcGetInfo(&sRtc);
    return (HOURS_PER_DAY * MINUTES_PER_HOUR) * RtcGetDayCount(&sRtc) + MINUTES_PER_HOUR * sRtc.hour + sRtc.minute;
}

u32 RtcGetLocalDayCount(void)
{
    return RtcGetDayCount(&sRtc);
}

void RtcAdvanceTime(u32 hours, u32 minutes, u32 seconds)
{
    struct Time* time = GetFakeRtc();
    seconds += time->seconds;
    minutes += time->minutes;
    hours += time->hours;

    while(seconds >= SECONDS_PER_MINUTE)
    {
	    minutes++;
	    seconds -= SECONDS_PER_MINUTE;	
    }

    while(minutes >= MINUTES_PER_HOUR)
    {
	    hours++;
	    minutes -= MINUTES_PER_HOUR;
    }

    while(hours >= HOURS_PER_DAY)
    {
	    time->days++;
	    hours -= HOURS_PER_DAY;
    }

    time->seconds = seconds;
    time->minutes = minutes;
    time->hours = hours;
}

void RtcAdvanceTimeTo(u32 hour, u32 minute, u32 second)
{
    struct Time diff, target;
    RtcCalcLocalTime();
    
    target.hours = hour;
    target.minutes = minute;
    target.seconds = second;
    target.days = gLocalTime.days;
    
    CalcTimeDifference(&diff, &gLocalTime, &target);
    RtcAdvanceTime(diff.hours, diff.minutes, diff.seconds);
}

void FormatDecimalTimeWithoutSeconds(u8 *txtPtr, s8 hour, s8 minute, bool8 is24Hour)
{
    switch (is24Hour)
    {
    case TRUE:
        txtPtr = ConvertIntToDecimalStringN(txtPtr, hour, STR_CONV_MODE_LEADING_ZEROS, 2);
        *txtPtr++ = CHAR_COLON;
        txtPtr = ConvertIntToDecimalStringN(txtPtr, minute, STR_CONV_MODE_LEADING_ZEROS, 2);
        break;
    case FALSE:
        if (hour == 0)
            txtPtr = ConvertIntToDecimalStringN(txtPtr, 12, STR_CONV_MODE_LEADING_ZEROS, 2);
        else if (hour < 13)
            txtPtr = ConvertIntToDecimalStringN(txtPtr, hour, STR_CONV_MODE_LEADING_ZEROS, 2);
        else
            txtPtr = ConvertIntToDecimalStringN(txtPtr, hour - 12, STR_CONV_MODE_LEADING_ZEROS, 2);

        *txtPtr++ = CHAR_COLON;
        txtPtr = ConvertIntToDecimalStringN(txtPtr, minute, STR_CONV_MODE_LEADING_ZEROS, 2);
        txtPtr = StringAppend(txtPtr, gText_Space);
        if (hour < 12)
            txtPtr = StringAppend(txtPtr, gText_AM);
        else
            txtPtr = StringAppend(txtPtr, gText_PM);
        break;
    }

    *txtPtr++ = EOS;
    *txtPtr = EOS;
}