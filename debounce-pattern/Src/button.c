#include "button.h"

void Button_Init(Button *const me) {
    me->deviceState = 0;
}

unsigned char Button_getState(const Button *const me) {
    return me->deviceState;
}

void Button_setState(Button *const me, unsigned char state) {
    me->deviceState = state;
}
Button *Button_Create(void)
{
    Button *button = (Button *)malloc(sizeof(Button));
    if (button != NULL)
    {
      printf("Button created\n");
      button->deviceState = 0;
    }
    return button;
}

void Button_Destroy(Button *button)
{
    free(button);
}
