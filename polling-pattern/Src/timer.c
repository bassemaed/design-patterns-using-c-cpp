#include "../Inc/timer.h"
#include <unistd.h> // For usleep
#include <stdio.h>

static void* Timer_ThreadFunction(void* arg) {
    Timer* timer = (Timer*)arg;
    while (timer->isRunning) {
        usleep(timer->interval * 1000); // Convert milliseconds to microseconds
        if (timer->isRunning && timer->callback) {
            timer->callback(); // Call the callback function
        }
    }
    return NULL;
}

void Timer_Init(Timer* const me, uint32_t interval, TimerCallback callback) {
    me->interval = interval;
    me->isRunning = false;
    me->callback = callback;
}

void Timer_Start(Timer* const me) {
    if (!me->isRunning) {
        me->isRunning = true;
        pthread_create(&me->thread, NULL, Timer_ThreadFunction, me);
    }
}

void Timer_Stop(Timer* const me) {
    if (me->isRunning) {
        me->isRunning = false;
        pthread_join(me->thread, NULL); // Wait for the thread to finish
    }
}

void Timer_Cleanup(Timer* const me) {
    Timer_Stop(me);
}