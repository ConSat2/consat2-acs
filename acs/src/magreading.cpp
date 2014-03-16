#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <iostream>
#include <sys/ioctl.h>
#include <sys/fcntl.h>
using namespace std;

const char* mag_x = "/sys/bus/i2c/devices/1-001e/iio:device0/in_magn_x_raw";
const char* mag_y = "/sys/bus/i2c/devices/1-001e/iio:device0/in_magn_y_raw";
const char* mag_z = "/sys/bus/i2c/devices/1-001e/iio:device0/in_magn_z_raw";
const char* mag_range = "/sys/bus/i2c/devices/1-001e/iio:device0/in_magn_range";
const char* mag_scale = "/sys/bus/i2c/devices/1-001e/iio:device0/in_magn_scale";

int main()
{

  FILE* hmc_fp;
  char buffer[15];

  /************************************************************/
  /*********************HMC5883L X axis Raw********************/
  /************************************************************/
  hmc_fp = fopen(mag_x,"r");
  if (hmc_fp !=NULL)
  {
    size_t bytes_read = fread(buffer, 1, 4, hmc_fp);
    fclose(hmc_fp);
  }
  else
  {
    strncpy(buffer,"Failed to open fp for magnetometer\n",9);
  }
  printf("Magnetometer X: %s\n", buffer);

  /************************************************************/
  /*********************HMC5883L Y axis Raw********************/
  /************************************************************/
  hmc_fp = fopen(mag_y,"r");
  if (hmc_fp !=NULL)
  {
    size_t bytes_read = fread(buffer, 1, 4, hmc_fp);
    fclose(hmc_fp);
  }
  else
  {
    strncpy(buffer,"Failed to open fp for magnetometer\n",9);
  }

  printf("Magnetometer Y: %s\n", buffer);

  /************************************************************/
  /*********************HMC5883L Z axis Raw********************/
  /************************************************************/
  hmc_fp = fopen(mag_z,"r");
  if (hmc_fp !=NULL)
  {
    size_t bytes_read = fread(buffer, 1, 4, hmc_fp);
    fclose(hmc_fp);
  }
  else
  {
    strncpy(buffer,"Failed to open fp for magnetometer\n",9);
  }

  printf("Magnetometer Z: %s\n", buffer);

  /************************************************************/
  /***********************HMC5883L Range***********************/
  /************************************************************/

  hmc_fp = fopen(mag_range,"r");
  if (hmc_fp !=NULL)
  {
    size_t bytes_read = fread(buffer, 1, 4, hmc_fp);
    fclose(hmc_fp);
  }
  else
  {
    strncpy(buffer,"Failed to open fp for magnetometer\n",9);
  }

  printf("Magnetometer range: %s\n", buffer);

  /************************************************************/
  /***********************HMC5883L Scale***********************/
  /************************************************************/

  hmc_fp = fopen(mag_scale,"r");
  if (hmc_fp !=NULL)
  {
    size_t bytes_read = fread(buffer, 1, 11, hmc_fp);
    fclose(hmc_fp);
  }
  else
  {
    strncpy(buffer,"Failed to open fp for magnetometer\n",9);
  }


  printf("Magnetometer scale: %s\n", buffer);

  return 0;
}
