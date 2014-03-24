// Notes: the address used here is 0x40 for the ina219. This can be modified by configuring A0 and A1 of the device. They are both to ground.
// The shunt resistor is assumed to be 10 mOhms

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <iostream>
#include <sys/ioctl.h>
#include <sys/fcntl.h>
#include "shakespeare.h"
// TODO:
// Check how many bytes to read
// Test on Beaglebone with board
// Configure the calibration registers for current and power readings

using namespace std;

#define DEBUG_MAG 1
#define filename "read-power"

const string LOGS_FOLDER("/home/logs/");
const char* current = "/sys/bus/i2c/devices/1-0040/curr1_input"; // current through shunt resistor
const char* shunt_voltage = "/sys/bus/i2c/devices/1-0040/in0_input"; // voltage across shunt resistor
const char* bus_voltage = "/sys/bus/i2c/devices/1-0040/in1_input"; // voltage from bus to gnd
const char* power = "/sys/bus/i2c/devices/1-0040/power1_input"; // power through shunt resistor

int main()
{

  FILE* ina219_fp;
  char buffer[18];
  char measure[32];
  FILE* g_fp_log = Shakespeare::open_log (LOGS_FOLDER, filename);
  printf("%s",measure);
  /************************************************************/
  /*********************INA219 Current*************************/
  /************************************************************/
  ina219_fp = fopen(current,"r");
  if (ina219_fp !=NULL) {
    size_t bytes_read = fread(buffer, 1, 4, ina219_fp);
    fclose(ina219_fp);
  } else {
    strncpy(buffer,"Failed to open fp for ina219\n",9);
  }
  printf("Current: %smA\n", buffer);
  strcpy (measure,"I(mA): ");
  strcat (measure, buffer);
  Shakespeare::log(g_fp_log, Shakespeare::NOTICE, filename, measure);

  /************************************************************/
  /********************INA219 Shunt Voltage********************/
  /************************************************************/
  ina219_fp = fopen(shunt_voltage,"r");
  if (ina219_fp !=NULL) {
    size_t bytes_read = fread(buffer, 1, 4, ina219_fp);
    fclose(ina219_fp);
  } else {
    strncpy(buffer,"Failed to open fp for magnetometer\n",9);
  }

  printf("Shunt Voltage: %sV\n", buffer);
  strcpy (measure,"Shunt V(V): ");
  strcat (measure, buffer);
  Shakespeare::log(g_fp_log, Shakespeare::NOTICE, filename, measure);

  /************************************************************/
  /*********************INA219 Bus Voltage*********************/
  /************************************************************/
  ina219_fp = fopen(bus_voltage,"r");
  if (ina219_fp !=NULL) {
    size_t bytes_read = fread(buffer, 1, 4, ina219_fp);
    fclose(ina219_fp);
  } else {
    strncpy(buffer,"Failed to open fp for magnetometer\n",9);
  }

  printf("Bus Voltage: %sV\n", buffer);
  strcpy (measure,"Bus V(V): ");
  strcat (measure, buffer);
  Shakespeare::log(g_fp_log, Shakespeare::NOTICE, filename, measure);

  /************************************************************/
  /***********************HMC5883L Range***********************/
  /************************************************************/

  ina219_fp = fopen(power,"r");
  if (ina219_fp !=NULL) {
    size_t bytes_read = fread(buffer, 1, 4, ina219_fp);
    fclose(ina219_fp);
  } else {
    strncpy(buffer,"Failed to open fp for magnetometer\n",9);
  }

  printf("Power: %suW\n", buffer);
  strcpy (measure,"P(uW): ");
  strcat (measure, buffer);
  Shakespeare::log(g_fp_log, Shakespeare::NOTICE, filename, measure);

  return 0;
}
