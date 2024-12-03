#ifndef __TIMER_H__
#define __TIMER_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


typedef struct Timer {
    uint32_t defaultDelay;
    // No fields are required for this example.
    // A real implementation might have hardware-specific fields.
} Timer;

void Timer_delay(int milliseconds);
Timer *Timer_Create(void);
void Timer_Destroy(Timer *timer);

#endif
