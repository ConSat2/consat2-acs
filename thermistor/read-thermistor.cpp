#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include "shakespeare.h"

#define DEBUG_THERMISTOR 1

#define filename "read-Thermistor"

const char* ADDRESS= "BB-W1:00A0";
const char* PATH = "/sys/devices/bone_capemgr.9/slots";
const string LOGS_FOLDER("/home/logs/");
FILE* g_fp_log = NULL;

bool enable_sensor() {
  g_fp_log = Shakespeare::open_log (LOGS_FOLDER, filename);
  printf("enabling sensor\n");
  int fd = open(PATH, O_NONBLOCK | O_WRONLY);
  int retval = write(fd,ADDRESS,strlen(ADDRESS));
  if (retval == -1) {
    return false;
  }
  close(fd);
  printf("thermistor enabled\n");
  return true;
}

int main()
{
  const char* w1= "/sys/bus/w1/devices/28-00000560a53e/w1_slave";

  char buffer[100];
  int i;
  printf("Starting job\n");
  enable_sensor();
  char* Temp = (char*) malloc (sizeof(char)*16);
  Shakespeare::log(g_fp_log, Shakespeare::NOTICE, "Sensor", "Starting");
  while(true) {
    // TODO: read last 6 bytes only
    FILE* fp = fopen(w1,"r");
    if(fp != NULL) {
      size_t bytes_read = fread(buffer,1, 75, fp);
      float temperature = atoi(buffer+69) / 1000.0;
      printf("temperature = %.3f degrees\n", temperature);
      if (g_fp_log != NULL) {
        sprintf(Temp,"%.2f",temperature);
        Shakespeare::log(g_fp_log, Shakespeare::NOTICE, filename, Temp);
        if (DEBUG_THERMISTOR) {
            printf("%s\n", Temp);
        }
      }
      fclose(fp);
    }
  }

  return 0;
}
