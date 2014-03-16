#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <iostream>
#include <sys/ioctl.h>
#include <sys/fcntl.h>
#include "shakespeare.h"

using namespace std;

#define DEBUG_MAG 1
#define filename "read-magnetometer"

const string LOGS_FOLDER("/home/logs/");
const char* mag_x = "/sys/bus/i2c/devices/1-001e/iio:device0/in_magn_x_raw";
const char* mag_y = "/sys/bus/i2c/devices/1-001e/iio:device0/in_magn_y_raw";
const char* mag_z = "/sys/bus/i2c/devices/1-001e/iio:device0/in_magn_z_raw";
const char* mag_range = "/sys/bus/i2c/devices/1-001e/iio:device0/in_magn_range";
const char* mag_scale = "/sys/bus/i2c/devices/1-001e/iio:device0/in_magn_scale";

int main()
{

  FILE* hmc_fp;
  char buffer[18];
  char measure[32];
  FILE* g_fp_log = Shakespeare::open_log (LOGS_FOLDER, filename);
  printf("%s",measure);
  /************************************************************/
  /*********************HMC5883L X axis Raw********************/
  /************************************************************/
  hmc_fp = fopen(mag_x,"r");
  if (hmc_fp !=NULL) {
    size_t bytes_read = fread(buffer, 1, 4, hmc_fp);
    fclose(hmc_fp);
  } else {
    strncpy(buffer,"Failed to open fp for magnetometer\n",9);
  }
  printf("Magnetometer X: %s\n", buffer);
  strcpy (measure,"X: ");
  strcat (measure, buffer);
  Shakespeare::log(g_fp_log, Shakespeare::NOTICE, filename, measure);

  /************************************************************/
  /*********************HMC5883L Y axis Raw********************/
  /************************************************************/
  hmc_fp = fopen(mag_y,"r");
  if (hmc_fp !=NULL) {
    size_t bytes_read = fread(buffer, 1, 4, hmc_fp);
    fclose(hmc_fp);
  } else {
    strncpy(buffer,"Failed to open fp for magnetometer\n",9);
  }

  printf("Magnetometer Y: %s\n", buffer);
  strcpy (measure,"Y: ");
  strcat (measure, buffer);
  Shakespeare::log(g_fp_log, Shakespeare::NOTICE, filename, measure);

  /************************************************************/
  /*********************HMC5883L Z axis Raw********************/
  /************************************************************/
  hmc_fp = fopen(mag_z,"r");
  if (hmc_fp !=NULL) {
    size_t bytes_read = fread(buffer, 1, 4, hmc_fp);
    fclose(hmc_fp);
  } else {
    strncpy(buffer,"Failed to open fp for magnetometer\n",9);
  }

  printf("Magnetometer Z: %s\n", buffer);
  strcpy (measure,"Z: ");
  strcat (measure, buffer);
  Shakespeare::log(g_fp_log, Shakespeare::NOTICE, filename, measure);

  /************************************************************/
  /***********************HMC5883L Range***********************/
  /************************************************************/

  hmc_fp = fopen(mag_range,"r");
  if (hmc_fp !=NULL) {
    size_t bytes_read = fread(buffer, 1, 4, hmc_fp);
    fclose(hmc_fp);
  } else {
    strncpy(buffer,"Failed to open fp for magnetometer\n",9);
  }

  printf("Magnetometer range: %s\n", buffer);
  strcpy (measure,"R: ");
  strcat (measure, buffer);
  Shakespeare::log(g_fp_log, Shakespeare::NOTICE, filename, measure);

  /************************************************************/
  /***********************HMC5883L Scale***********************/
  /************************************************************/
  hmc_fp = fopen(mag_scale,"r");
  if (hmc_fp !=NULL) {
    size_t bytes_read = fread(buffer, 1, 11, hmc_fp);
    fclose(hmc_fp);
  } else {
    strncpy(buffer,"Failed to open fp for magnetometer\n",9);
  }

  printf("Magnetometer scale: %s\n", buffer);
  strcpy (measure,"S: ");
  strcat (measure, buffer);
  Shakespeare::log(g_fp_log, Shakespeare::NOTICE, filename, measure);

  return 0;
}
