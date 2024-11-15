#include <stdio.h>
#include <stddef.h>
#include "gasSensor.h"
#include "displayClient.h"

int main(void)
{
    // Create a GasSensor instance
    GasSensor *gasSensor = GasSensor_Create();
    if (!gasSensor)
    {
        printf("Failed to create GasSensor instance.\n");
        return -1;
    }

    // Create a DisplayClient instance
    DisplayClient *displayClient = DisplayClient_Create();
    if (!displayClient)
    {
        printf("Failed to create DisplayClient instance.\n");
        GasSensor_Destroy(gasSensor);
        return -1;
    }
    DisplayClient *displayClient2 = DisplayClient_Create();
    if (!displayClient2)
    {
        printf("Failed to create DisplayClient instance.\n");
        GasSensor_Destroy(gasSensor);
        return -1;
    }

    // Associate the DisplayClient with the GasSensor
    DisplayClient_setItsGasSensor(displayClient, gasSensor);
    DisplayClient_register(displayClient);

    DisplayClient_setItsGasSensor(displayClient2, gasSensor);
    DisplayClient_register(displayClient2);

    // Simulate new gas data from the sensor
    printf("Simulating new gas data...\n");
    GasSensor_newData(gasSensor, 500, 78, 21); // flowRate=500, N2Conc=78, O2Conc=21

    // Dump the registered observers
    printf("\nDumping observer list:\n");
    GasSensor_dumpList(gasSensor);

    // Simulate another set of gas data
    printf("\nSimulating another set of gas data...\n");
    GasSensor_newData(gasSensor, 600, 76, 23); // flowRate=600, N2Conc=76, O2Conc=23

    // Clean up resources
    printf("\nCleaning up resources...\n");
    DisplayClient_Destroy(displayClient);
    DisplayClient_Destroy(displayClient2);
    GasSensor_Destroy(gasSensor);

    return 0;
}
