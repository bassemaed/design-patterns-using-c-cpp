#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "PeriodicPoller.h"
#include "MockSensor.h"
#include "MockDisplay.h"
#include "timer.h"

PeriodicPoller* poller;
void PollCallback(void) {
    PeriodicPoller_poll(poller);
}
int main() {
    // Create the poller
    poller = PeriodicPoller_Create();

    // Create and initialize the sensors
    struct MockSensor sensor1, sensor2, sensor3;
    MockSensor_Init(&sensor1);
    MockSensor_Init(&sensor2);
    MockSensor_Init(&sensor3);

    // Set initial values for the sensors
    MockSensor_setData(&sensor1, 50);
    MockSensor_setState(&sensor1, 1);

    MockSensor_setData(&sensor2, 30);
    MockSensor_setState(&sensor2, 1);

    MockSensor_setData(&sensor3, 100);
    MockSensor_setState(&sensor3, 1);

    // Add sensors to the poller
    PeriodicPoller_addItsSensor(poller, &sensor1);
    PeriodicPoller_addItsSensor(poller, &sensor2);
    PeriodicPoller_addItsSensor(poller, &sensor3);

    // Create and initialize the display
    struct MockDisplay display;
    MockDisplay_Init(&display);
    PeriodicPoller_setItsDisplay(poller, &display);

    // Create and initialize the timer
    Timer timer;
    Timer_Init(&timer, 5000, PollCallback); // 10-second interval
    Timer_Start(&timer);

    // Run for 1 minute (60 seconds)
    printf("Starting polling...\n");
    time_t startTime = time(NULL); // Get the current time
    while (difftime(time(NULL), startTime) < 30) { // Run for 60 seconds
        // Check if 10 seconds have passed to update sensor values
        if ((int)difftime(time(NULL), startTime) % 10 == 0) {
            printf("Updating sensor values...\n");
            MockSensor_setData(&sensor1, rand() % 100);
            MockSensor_setData(&sensor2, rand() % 100);
            MockSensor_setData(&sensor3, rand() % 200);
        }

        // Sleep for 1 second to avoid busy-waiting
        sleep(1);
    }

    // Stop the timer
    Timer_Stop(&timer);
    printf("Stopping polling...\n");

    // Clean up
    PeriodicPoller_Destroy(poller);
    Timer_Cleanup(&timer);

    return 0;
}