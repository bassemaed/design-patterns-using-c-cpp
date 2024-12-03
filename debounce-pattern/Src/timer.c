#include "timer.h"

void Timer_delay(int milliseconds)
{
  nanosleep(milliseconds); // Convert to microseconds
}

Timer *Timer_Create(void)
{
  Timer *timer = (Timer *)malloc(sizeof(Timer));
  if (timer != NULL)
  {
    printf("Timer created\n");
    timer->defaultDelay = 0u;
  }
  return timer; // Empty struct, no initialization needed for now
}

void Timer_Destroy(Timer *timer)
{
  free(timer);
}