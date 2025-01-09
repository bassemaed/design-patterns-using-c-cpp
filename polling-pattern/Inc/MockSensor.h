#ifndef __BREATHING_SENSOR__
#define __BREATHING_SENSOR__

struct MockSensor {
    int data;
    int state;
};

void MockSensor_Init(struct MockSensor* const me);
void MockSensor_CleanUp(struct MockSensor* const me);
int MockSensor_getData(const struct MockSensor* const me);
int MockSensor_getState(const struct MockSensor* const me);
void MockSensor_setData(struct MockSensor* const me, int data);
void MockSensor_setState(struct MockSensor* const me, int state);

#endif