#ifndef __ButtonDriver_H__
#define __ButtonDriver_H__

#define LOOPS_PER_MS (1000)
#define DEBOUNCE_TIME (40)

#include <stdlib.h>
#include <stdio.h>

struct Button;
struct MicrowaveEmitter;
struct Timer;
typedef struct ButtonDriver ButtonDriver;
struct ButtonDriver
{
  unsigned char oldState;
  unsigned char toggleOn;
  struct Button *itsButton;
  struct Timer *itsTimer;
};

void ButtonDriver_Init(ButtonDriver *const me);
void ButtonDriver_Cleanup(ButtonDriver *const me);
/* Operations */ void ButtonDriver_eventReceive(ButtonDriver *const me);
struct Timer *ButtonDriver_getItsTimer(const ButtonDriver *const me);
void ButtonDriver_setItsTimer(ButtonDriver *const me, struct Timer *p_Timer);
ButtonDriver *ButtonDriver_Create(void);
void ButtonDriver_Destroy(ButtonDriver *const me);
void ButtonDriver_setItsButton(ButtonDriver *const me, struct Button *p_Button);
void ButtonDriver_clearItsButton(ButtonDriver *const me);
#endif