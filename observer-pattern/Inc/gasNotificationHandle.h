#ifndef GAS_NOTIFICATION_HANDLE_H
#define GAS_NOTIFICATION_HANDLE_H

// Forward declaration of GasData to avoid circular dependency
struct GasData;

// Define the type for the acceptor function pointer
typedef void (*gasDataAcceptorPtr)(void *instancePtr, struct GasData *g);

// Define the GasNotificationHandle structure
typedef struct GasNotificationHandle {
    void *instancePtr;               // Pointer to the observer instance (e.g., DisplayClient)
    gasDataAcceptorPtr acceptorPtr;  // Function pointer to the observer's accept function
} GasNotificationHandle;

// Function prototypes
GasNotificationHandle *GasNotificationHandle_Create(void);
void GasNotificationHandle_Destroy(GasNotificationHandle *const me);

#endif // GAS_NOTIFICATION_HANDLE_H
