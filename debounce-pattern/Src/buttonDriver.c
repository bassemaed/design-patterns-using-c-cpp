#include "buttonDriver.h"
#include <stddef.h>
#include "button.h"
#include "timer.h"

static void cleanUpRelations(ButtonDriver *const me);
void ButtonDriver_Init(ButtonDriver *const me)
{
  me->oldState = 0;
  me->toggleOn = 0;
  me->itsButton = NULL;
  me->itsTimer = NULL;
}
void ButtonDriver_Cleanup(ButtonDriver *const me)
{
  cleanUpRelations(me);
}
void ButtonDriver_eventReceive(ButtonDriver *const me)
{
  Timer_delay(DEBOUNCE_TIME);
  if (Button_getState(me->itsButton) != me->oldState)
  {
    /* must be a valid button event */
    me->oldState = Button_getState(me->itsButton);
    if (!me->oldState)
    {
      me->toggleOn = !me->toggleOn; // Toggle the state
      /* must be a button release, so update toggle value */
      if (me->toggleOn)
      {
        printf("Button toggled ON\n");
      }
      else
      {
        printf("Button toggled OFF\n");
      }
    }
    /* if it’s not a button release, then it must
    be a button push, which we ignore.
    */
  }
}
struct Button *ButtonDriver_getItsButton(const ButtonDriver *const me)
{
  return (struct Button *)me->itsButton;
}
struct Timer *ButtonDriver_getItsTimer(const ButtonDriver *const me)
{
  return (struct Timer *)me->itsTimer;
}
void ButtonDriver_setItsTimer(ButtonDriver *const me, struct Timer *p_Timer)
{
  me->itsTimer = p_Timer;
}
ButtonDriver *ButtonDriver_Create(void)
{
  ButtonDriver *me = (ButtonDriver *)
      malloc(sizeof(ButtonDriver));
  if (me != NULL)
  {
    printf("Button Driver created\n");
    ButtonDriver_Init(me);
  }
  return me;
}
void ButtonDriver_Destroy(ButtonDriver *const me)
{
  if (me != NULL)
  {
    ButtonDriver_Cleanup(me);
  }
  free(me);
}
static void cleanUpRelations(ButtonDriver *const me)
{
  if (me->itsButton != NULL)
  {
    me->itsButton = NULL;
  }
  if (me->itsTimer != NULL)
  {
    me->itsTimer = NULL;
  }
}
void ButtonDriver_setItsButton(ButtonDriver *const me, struct Button *p_Button)
{
  me->itsButton = p_Button;
}
void ButtonDriver_clearItsButton(ButtonDriver *const me)
{
  me->itsButton = NULL;
}