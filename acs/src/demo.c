// TODO: Calibrate ACS sensor


#include <ncurses.h>
#include <unistd.h>

#include "adxl345.h"

int main(){
  float x = 0;
  float y = 0;
  float z = 0;

  if(accelerometer_init() == 0)
    return 1;

  if(measure_mode() == 0)
    return 1;

  while(true){
    get_data_x(&x);
    get_data_y(&y);
    get_data_z(&z);

    printf("X: %1.3f ",x);
    printf("Y: %1.3f ",y);
    printf("Z: %1.3f\n",z);

    //Wait
    usleep (100000) ;
  }

  return 0;
}
