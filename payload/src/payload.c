#include <inttypes.h>
#include <stdio.h>
#include "../include/payload.h"
#include "../include/bbb.h"

void payload_init()
{
  // Enable all GPIO's and set direction
  bbb_enableGpio(bbb_getGpio(bbb_getIndexByStr(REGULAR_EXPERIMENT)));
  bbb_enableGpio(bbb_getGpio(bbb_getIndexByStr(HEALING_EXPERIMENT)));
  bbb_enableGpio(bbb_getGpio(bbb_getIndexByStr(SH_HEATER)));
  bbb_enableGpio(bbb_getGpio(bbb_getIndexByStr(R_HEATER)));
  bbb_enableGpio(bbb_getGpio(bbb_getIndexByStr(PAYLOAD_POWER)));
  bbb_enableGpio(bbb_getGpio(bbb_getIndexByStr(COMPARATOR)));

  bbb_setGpioDirection(bbb_getGpio(bbb_getIndexByStr(REGULAR_EXPERIMENT)), 1);
  bbb_setGpioDirection(bbb_getGpio(bbb_getIndexByStr(HEALING_EXPERIMENT)), 1);
  bbb_setGpioDirection(bbb_getGpio(bbb_getIndexByStr(SH_HEATER)), 1);
  bbb_setGpioDirection(bbb_getGpio(bbb_getIndexByStr(R_HEATER)), 1);
  bbb_setGpioDirection(bbb_getGpio(bbb_getIndexByStr(PAYLOAD_POWER)), 1);
  bbb_setGpioDirection(bbb_getGpio(bbb_getIndexByStr(COMPARATOR)), 0);

  // Enable ADC
  bbb_enableADC();

}

// Set digital HIGH to payload GPIO
void payload_start_experiment(uint8_t experiment_number)
{
  // Set digital signal to start experiment
  switch(experiment_number)
  {
    case 0:
      bbb_setGpioValue(bbb_getGpio(bbb_getIndexByStr(REGULAR_EXPERIMENT)), 1);
      break;
    case 1:
      bbb_setGpioValue(bbb_getGpio(bbb_getIndexByStr(HEALING_EXPERIMENT)), 1);
      break;
    default:
      break;
  }
}

// Sets experiment switch LOW
void payload_end_experiment(uint8_t experiment_number)
{
  // Set digital signal to start experiment
  switch(experiment_number)
  {
    case 0:
      bbb_setGpioValue(bbb_getGpio(bbb_getIndexByStr(REGULAR_EXPERIMENT)), 0);
      bbb_disableGpio(bbb_getGpio(bbb_getIndexByStr(REGULAR_EXPERIMENT)));
      break;
    case 1:
      bbb_setGpioValue(bbb_getGpio(bbb_getIndexByStr(HEALING_EXPERIMENT)), 0);
      bbb_disableGpio(bbb_getGpio(bbb_getIndexByStr(HEALING_EXPERIMENT)));
      break;
    default:
      break;
  }
}

// Sets power switch HIGH/LOW
void payload_set_power(uint8_t value)
{
  switch(value)
  {
    case 0:
      bbb_setGpioValue(bbb_getGpio(bbb_getIndexByStr(PAYLOAD_POWER)), 0);
      break;
    case 1:
      bbb_setGpioValue(bbb_getGpio(bbb_getIndexByStr(PAYLOAD_POWER)), 1);
      break;
    default:
      break;
  }
}

// Set heaters switch HIGH/LOW
void payload_set_heaters(uint8_t experiment_number, uint8_t value)
{
  switch(experiment_number)
  {
    case 0:
      bbb_setGpioValue(bbb_getGpio(bbb_getIndexByStr(SH_HEATER)), value);
      break;
    case 1:
      bbb_setGpioValue(bbb_getGpio(bbb_getIndexByStr(R_HEATER)), value);
      break;
    default:
      break;
  }
}

float payload_read_load_cell(uint8_t experiment_number);
float payload_read_photodiode(uint8_t experiment_number);
float payload_read_temperature(uint8_t experiment_number);
void payload_handle_comparator();
