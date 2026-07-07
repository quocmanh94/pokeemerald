#ifndef GUARD_CONSTANTS_TIME_OF_DAY_H
#define GUARD_CONSTANTS_TIME_OF_DAY_H

// Real-time (RTC) schedule for overworld palette tinting.
// Each twilight window is one hour; full night/day fill the remaining hours.
//
// Hour (24h) │ Period
// ───────────┼────────────────────────────
//  0 –  4    │ Night (full)
//  5 –  6    │ Morning twilight (tint night → twilight; gTimeOfDay = night)
//  6 –  7    │ Morning twilight (tint twilight → day;   gTimeOfDay = day)
//  7 – 16    │ Day (full)
// 17 – 18    │ Evening twilight (tint day → twilight;   gTimeOfDay = day)
// 18 – 19    │ Evening twilight (tint twilight → night; gTimeOfDay = night)
// 19 – 23    │ Night (full)

#define TIME_NIGHT_END_HOUR                 5  // Full night ends; morning twilight begins
#define TIME_MORNING_DAY_START_HOUR         6  // gTimeOfDay becomes day during morning twilight
#define TIME_MORNING_TWILIGHT_END_HOUR      7  // Day tint fully reached
#define TIME_DAY_END_HOUR                  17  // Full day ends; evening twilight begins
#define TIME_EVENING_NIGHT_START_HOUR      18  // gTimeOfDay becomes night during evening twilight
#define TIME_NIGHT_START_HOUR              19  // Full night begins

// Overworld palette refresh rate (frames between UpdateTimeOfDay calls).
#define TIME_OF_DAY_UPDATE_INTERVAL        60

// Street light schedule (RTC, 24-hour). Independent of palette tint transitions.
// Lights are on from LIGHT_TURN_ON_HOUR through midnight until LIGHT_TURN_OFF_HOUR.
#define LIGHT_TURN_ON_HOUR                 18  // 6:00 PM
#define LIGHT_TURN_OFF_HOUR                 6  // 6:00 AM

#endif // GUARD_CONSTANTS_TIME_OF_DAY_H
