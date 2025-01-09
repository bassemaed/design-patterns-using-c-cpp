#include "PeriodicPoller.h"
#include "MockSensor.h"
#include "MockDisplay.h"
#include "timer.h"

static int isPolling = 0; // Global flag to control polling

void PeriodicPoller_Init(PeriodicPoller* const me) {
    me->pollTime = DEFAULT_POLL_TIME;
    for (int i = 0; i < 3; i++) {
        me->itsSensors[i] = NULL;
    }
    me->istMockDisplay = NULL;
}

void PeriodicPoller_Cleanup(PeriodicPoller* const me) {
    // Cleanup if needed
}

void PeriodicPoller_poll(PeriodicPoller* const me) {
    int state, data;
    if (me->itsSensors[0]) {
        data = MockSensor_getData(me->itsSensors[0]);
        MockDisplay_showValue1(me->istMockDisplay, data);
    }
    if (me->itsSensors[1]) {
        data = MockSensor_getData(me->itsSensors[1]);
        state = MockSensor_getState(me->itsSensors[1]);
        MockDisplay_showValue2(me->istMockDisplay, data);
    }
    if (me->itsSensors[2]) {
        data = MockSensor_getData(me->itsSensors[2]);
        MockDisplay_showValue3(me->istMockDisplay, data);
    }
}

void PeriodicPoller_setPollTime(PeriodicPoller* const me, unsigned long t) {
    me->pollTime = t;
}

void PeriodicPoller_startPolling(PeriodicPoller* const me) {
    isPolling = 1;
    while (isPolling) {
        PeriodicPoller_poll(me);
    }
}

void PeriodicPoller_stopPolling(PeriodicPoller* const me) {
    isPolling = 0;
}

int PeriodicPoller_getItsSensor(const PeriodicPoller* const me) {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        if (me->itsSensors[i]) {
            count++;
        }
    }
    return count;
}

void PeriodicPoller_addItsSensor(PeriodicPoller* const me, struct MockSensor * p_Sensor) {
    for (int i = 0; i < 3; i++) {
        if (!me->itsSensors[i]) {
            me->itsSensors[i] = p_Sensor;
            break;
        }
    }
}

void PeriodicPoller_removeItsSensor(PeriodicPoller* const me, struct MockSensor * p_Sensor) {
    for (int i = 0; i < 3; i++) {
        if (me->itsSensors[i] == p_Sensor) {
            me->itsSensors[i] = NULL;
        }
    }
}

void PeriodicPoller_clearItsSensor(PeriodicPoller* const me) {
    for (int i = 0; i < 3; i++) {
        me->itsSensors[i] = NULL;
    }
}

struct MockDisplay* PeriodicPoller_getItsDisplay(const PeriodicPoller* const me) {
    return me->istMockDisplay;
}

void PeriodicPoller_setItsDisplay(PeriodicPoller* const me, struct MockDisplay* p_MockDisplay) {
    me->istMockDisplay = p_MockDisplay;
}

PeriodicPoller * PeriodicPoller_Create(void) {
    PeriodicPoller* me = (PeriodicPoller*)malloc(sizeof(PeriodicPoller));
    if (me != NULL) {
        PeriodicPoller_Init(me);
    }
    return me;
}

void PeriodicPoller_Destroy(PeriodicPoller* const me) {
    if (me != NULL) {
        PeriodicPoller_Cleanup(me);
    }
    free(me);
}