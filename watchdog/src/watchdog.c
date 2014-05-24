#include <stdio.h>
#include "../../lib-bbb/bbb.h"

#define WATCHDOG_PERIOD "1Hz"
#define WATCHDOG_DUTY 90

void watchdog_init() {
  bbb_enablePwm(9, 21);
  bbb_setPwmHz(9, 21, WATCHDOG_PERIOD);
  bbb_setPwmPercent(9, 21, WATCHDOG_DUTY);
  while(bbb_getPwmPeriod(9, 21) != 1000000000) {
    bbb_setPwmHz(9, 21, WATCHDOG_PERIOD);
    bbb_setPwmPercent(9, 21, WATCHDOG_DUTY);
  }
}

int main(int argc, char** argv)
{
  watchdog_init();

  return 0;
}
