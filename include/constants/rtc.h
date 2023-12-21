#ifndef GUARD_CONSTANTS_RTC_H
#define GUARD_CONSTANTS_RTC_H

// unused in favor of my own times
// //Morning and evening don't exist in Gen 3
// #if OW_TIMES_OF_DAY == GEN_3
//     #define MORNING_HOUR_BEGIN 0
//     #define MORNING_HOUR_END   0

//     #define DAY_HOUR_BEGIN     12
//     #define DAY_HOUR_END       HOURS_PER_DAY

//     #define EVENING_HOUR_BEGIN 0
//     #define EVENING_HOUR_END   0

//     #define NIGHT_HOUR_BEGIN   0
//     #define NIGHT_HOUR_END     12
// //Evening doesn't exist in Gen 4
// #elif OW_TIMES_OF_DAY == GEN_4
//     #define MORNING_HOUR_BEGIN 4
//     #define MORNING_HOUR_END   10

//     #define DAY_HOUR_BEGIN     10
//     #define DAY_HOUR_END       20

//     #define EVENING_HOUR_BEGIN 0
//     #define EVENING_HOUR_END   0

//     #define NIGHT_HOUR_BEGIN   20
//     #define NIGHT_HOUR_END     4
// //Gen 5 currently not included as the seasons change the times of day
// #elif OW_TIMES_OF_DAY <= GEN_6
//     #define MORNING_HOUR_BEGIN 4
//     #define MORNING_HOUR_END   11

//     #define DAY_HOUR_BEGIN     11
//     #define DAY_HOUR_END       18

//     #define EVENING_HOUR_BEGIN 18
//     #define EVENING_HOUR_END   21

//     #define NIGHT_HOUR_BEGIN   21
//     #define NIGHT_HOUR_END     4
// //These are the Sun/Ultra Sun times
// #elif OW_TIMES_OF_DAY == GEN_7
//     #define MORNING_HOUR_BEGIN 6
//     #define MORNING_HOUR_END   10

//     #define DAY_HOUR_BEGIN     10
//     #define DAY_HOUR_END       17

//     #define EVENING_HOUR_BEGIN 17
//     #define EVENING_HOUR_END   18

//     #define NIGHT_HOUR_BEGIN   18
//     #define NIGHT_HOUR_END     6
// #elif OW_TIMES_OF_DAY >= GEN_8
//     #define MORNING_HOUR_BEGIN 6
//     #define MORNING_HOUR_END   10

//     #define DAY_HOUR_BEGIN     10
//     #define DAY_HOUR_END       19

//     #define EVENING_HOUR_BEGIN 19
//     #define EVENING_HOUR_END   20

//     #define NIGHT_HOUR_BEGIN   20
//     #define NIGHT_HOUR_END     6
// #endif

#define MORNING_HOUR_BEGIN 8
#define MORNING_HOUR_END   12

#define DAY_HOUR_BEGIN     12
#define DAY_HOUR_END       18

#define EVENING_HOUR_BEGIN 18
#define EVENING_HOUR_END   20

#define NIGHT_HOUR_BEGIN   20
#define NIGHT_HOUR_END     8

#define TIME_MORNING           0
#define TIME_DAY               1
#define TIME_EVENING           2
#define TIME_NIGHT             3

#endif // GUARD_CONSTANTS_RTC_H