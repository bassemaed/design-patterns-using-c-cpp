#include "MockSensor.h"

void MockSensor_Init(struct MockSensor* const me) {
    me->data = 0;
    me->state = 0;
}

void MockSensor_CleanUp(struct MockSensor* const me) {
    // Cleanup if needed
}

int MockSensor_getData(const struct MockSensor* const me) {
    return me->data;
}

int MockSensor_getState(const struct MockSensor* const me) {
    return me->state;
}

void MockSensor_setData(struct MockSensor* const me, int data) {
    me->data = data;
}

void MockSensor_setState(struct MockSensor* const me, int state) {
    me->state = state;
}