#ifndef __BUTTON_H__
#define __BUTTON_H__

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Button
{
  unsigned char deviceState; // 0: released, 1: pressed
} Button;

void Button_Init(Button *const me);
unsigned char Button_getState(const Button *const me);
void Button_setState(Button *const me, unsigned char state);
Button *Button_Create(void);
void Button_Destroy(Button *button);

#endif
