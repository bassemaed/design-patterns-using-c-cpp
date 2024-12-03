#include <stdio.h>
#include "buttonDriver.h"
#include "button.h"
#include "timer.h"
#include <stdio.h>

int main()
{
  // Initialize components
  ButtonDriver *buttonDriver = ButtonDriver_Create();
  Button *button = Button_Create();
  Timer *timer = Timer_Create();

  Button_Init(button);
  ButtonDriver_Init(buttonDriver);

  ButtonDriver_setItsButton(buttonDriver, button);
  ButtonDriver_setItsTimer(buttonDriver, timer);

  int userInput;
  printf("Press 1 to simulate button press, 0 to release, or -1 to exit:\n");

  while (1)
  {
    printf("Enter button state: ");
    scanf("%d", &userInput);

    if (userInput == -1)
    {
      break; // Exit loop
    }

    if (userInput == 0 || userInput == 1)
    {
      Button_setState(button, (unsigned char)userInput);
      ButtonDriver_eventReceive(buttonDriver);
    }
    else
    {
      printf("Invalid input. Enter 0, 1, or -1.\n");
    }
  }

  ButtonDriver_Cleanup(buttonDriver);
  printf("Exiting...\n");
  return 0;
}
