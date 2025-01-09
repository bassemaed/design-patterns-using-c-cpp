#ifndef __TIMER_H__
#define __TIMER_H__

#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

typedef void (*TimerCallback)(void); // Callback function type

typedef struct Timer {
    uint32_t interval;          // Timer interval in milliseconds
    bool isRunning;             // Flag to control the timer
    TimerCallback callback;     // Callback function to call when the timer elapses
    pthread_t thread;           // Thread for the timer
} Timer;

void Timer_Init(Timer* const me, uint32_t interval, TimerCallback callback);
void Timer_Start(Timer* const me);
void Timer_Stop(Timer* const me);
void Timer_Cleanup(Timer* const me);

#endif