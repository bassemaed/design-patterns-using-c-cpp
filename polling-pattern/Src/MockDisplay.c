#include <stdio.h>
#include "MockDisplay.h"

void MockDisplay_Init(struct MockDisplay* const me) {
    // Initialization if needed
}

void MockDisplay_Cleanup(struct MockDisplay* const me) {
    // Cleanup if needed
}

void MockDisplay_showValue1(struct MockDisplay* const me, int data) {
    printf("Value 1 Sample: %d\n", data);
}

void MockDisplay_showValue2(struct MockDisplay* const me, int data) {
    printf("Value 2 Sample: %d\n", data);
}

void MockDisplay_showValue3(struct MockDisplay* const me, int data) {
    printf("Value 3 Sample: %d\n", data);
}