#include <stdio.h>
#include "/home/root/lib-bbb/bbb.h"

#define DEPLOYMENT_PIN 44

void setup()
{
  bbb_enableGpio(DEPLOYMENT_PIN);
  bbb_setGpioDirection(DEPLOYMENT_PIN, 1);
}


int main(int argc, char** argv)
{
  setup();
  sleep(60);
  bbb_setGpioValue(DEPLOYMENT_PIN, 1);
  return 0;
}
