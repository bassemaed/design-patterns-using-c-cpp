#ifndef __PERIODIC_POLLER_H__
#define __PERIODIC_POLLER_H__

#include <stdlib.h>
#include <stdio.h>
#include "timer.h"

typedef int deviceData;

#define MAX_POLL_DEVICES (10)
#define DEFAULT_POLL_TIME (10000)

struct MockSensor;
struct MockDisplay;

typedef struct PeriodicPoller {
    unsigned long pollTime;
    struct MockSensor *itsSensors[3];
    struct MockDisplay* istMockDisplay;
} PeriodicPoller;

void PeriodicPoller_Init(PeriodicPoller* const me);
void PeriodicPoller_Cleanup(PeriodicPoller* const me);
void PeriodicPoller_poll(PeriodicPoller* const me);
void PeriodicPoller_setPollTime(PeriodicPoller* const me, unsigned long t);
void PeriodicPoller_startPolling(PeriodicPoller* const me);
void PeriodicPoller_stopPolling(PeriodicPoller* const me);
int PeriodicPoller_getItsSensor(const PeriodicPoller* const me);
void PeriodicPoller_addItsSensor(PeriodicPoller* const me, struct MockSensor * p_Sensor);
void PeriodicPoller_removeItsSensor(PeriodicPoller* const me, struct MockSensor * p_Sensor);
void PeriodicPoller_clearItsSensor(PeriodicPoller* const me);
struct MockDisplay* PeriodicPoller_getItsDisplay(const PeriodicPoller* const me);
void PeriodicPoller_setItsDisplay(PeriodicPoller* const me, struct MockDisplay* p_MockDisplay);
PeriodicPoller * PeriodicPoller_Create(void);
void PeriodicPoller_Destroy(PeriodicPoller* const me);

#endif