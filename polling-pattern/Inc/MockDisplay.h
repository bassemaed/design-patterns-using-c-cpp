#ifndef __MOCK_DISPLAY_H__
#define __MOCK_DISPLAY_H__

struct MockDisplay {
    // No specific data members needed for this example
};

void MockDisplay_Init(struct MockDisplay* const me);
void MockDisplay_Cleanup(struct MockDisplay* const me);
void MockDisplay_showValue1(struct MockDisplay* const me, int data);
void MockDisplay_showValue2(struct MockDisplay* const me, int data);
void MockDisplay_showValue3(struct MockDisplay* const me, int data);

#endif