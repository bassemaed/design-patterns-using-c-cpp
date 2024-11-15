#include <stdlib.h>
#include "gasNotificationHandle.h"

// Function to create a new GasNotificationHandle instance
GasNotificationHandle *GasNotificationHandle_Create(void) {
    // Allocate memory for the new GasNotificationHandle
    GasNotificationHandle *newHandle = (GasNotificationHandle *)malloc(sizeof(GasNotificationHandle));
    
    // Check if memory allocation was successful
    if (newHandle != NULL) {
        newHandle->instancePtr = NULL;    // Initialize instance pointer
        newHandle->acceptorPtr = NULL;    // Initialize acceptor function pointer
    }
    return newHandle;
}

// Function to destroy a GasNotificationHandle instance
void GasNotificationHandle_Destroy(GasNotificationHandle *const me) {
    if (me != NULL) {
        // Clean up any resources or references if necessary
        me->instancePtr = NULL;
        me->acceptorPtr = NULL;
        free(me); // Free the allocated memory
    }
}
