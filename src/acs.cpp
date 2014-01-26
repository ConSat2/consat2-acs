// TODO: Change i2c_read() & i2c_write() to follow the library

#include "../include/i2c.h"
#include <string.h>
#include <iostream>
#include <types>
#include <poll>

// Define device address
// 0x53 0x68 0x1e
#define  ADXL345_ADDRESS (0x53 >> 1)
#define ADXL345_REGISTER_XLSB (0x32)
#define ADXL_REGISTER_PWRCTL (0x2D)
#define ADXL_PWRCTL_MEASURE (1 << 3)

#define ITG3200_ADDRESS (0x53 >> 1)
#define ITG3200_REGISTER_XMSB (0x1D)
#define ITG3200_REGISTER_DLPF_FS (0x16)
#define ITG3200_FULLSCALE (0x03 << 3)
#define ITG3200_42HZ (0x03)

#define HMC5843_ADDRESS (0x53 >> 1)
#define HMC5843_REGISTER_XMSB (0x03)
#define HMC5843_REGISTER_MEASMODE (0x02)
#define HMC5843_MEASMODE_CONT (0x00)

int accelerometer_data[3];
int gyro_data[3];
int magnetometer_data[3];
char c;

using namespace std;
void init_adxl345();
void init_hmc5843();
void init_itg3200();

void read_adxl345();
void read_hmc5843();
void read_itg3200();

void i2c_read(myI2C *i2cptr, int address, uint8_t reg, int count, uint8_t* data);
void i2c_write(myI2C *i2cptr, int address, uint8_t reg, uint8_t data);

int main(){
  // Instantiate the I2c Object at i2c-1
  myI2C *i2cptr = new myI2C();

  int value = 10;

  i2cptr->Send_I2C_Byte(DEVICE_ADDR,CTRL_REG1,value); // Example send data

  value = i2cptr->Read_I2C_Byte(DEVICE_ADDR, STATUS_REG); // Read single byte

  i2cptr->Read_Multi_Byte(DEVICE_ADDR, 0x80 | STATUS_REG);  // Example read multiple data
  // Output data will be stored in i2cptr->I2C_RD_Buf. Check i2c.cpp for more details

  return 0;
}

void i2c_read(myI2C *i2cptr, int address, uint8_t reg, int count, uint8_t* data)
{
  i2cptr->i2cSetAddress(address);
  if(write(i2cptr->g_i2cFile, &reg, 1) != 1) {
    perror("Error writing i2c\n");
  }

  i2cptr->i2cSetAddress(address);
  if(read(i2cptr->g_i2cFile, data, count) != count){
    perror("Error reading i2c\n");
  }

  // poll
  struct pollfd fds;
  fds.fd = i2cptr->g_i2cFile;
  fds.events = POLLIN;
  while(poll(&fds, 1, 5))
  {
    i2cptr->i2cSetAddress(address);
    if(write(i2cptr->g_i2cFile, &reg, 1) != 1) {
      perror("Error writing i2c\n");
    }

    i2cptr->i2cSetAddress(address);
    if(read(i2cptr->g_i2cFile, c, 1) != 1){
      perror("Error reading i2c\n");
    }
  }

  data[i] = c;
  i++;
}

void i2c_write(myI2C *i2cptr, int address, uint8_t reg, uint8_t data)
{


void init_adxl345() {
  uint8_t data = 0;

  i2c_write(ADXL345_ADDRESS, ADXL_REGISTER_PWRCTL, ADXL_PWRCTL_MEASURE);

  i2c_read(ADXL345_ADDRESS, ADXL_REGISTER_PWRCTL, 1, &data);
  printf("%d",(uint8_t)data);
}

void read_adxl345() {
 uint8_t bytes[6];
 memset(bytes,0,6);

 i2c_read(ADXL345_ADDRESS, ADXL345_REGISTER_XLSB, 6, bytes);

 for (int i=0;i<3;++i) {
 accelerometer_data[i] = (int)bytes[2*i] + (((int)bytes[2*i + 1]) << 8);
 }
}

void init_itg3200() {
  uint8_t data = 0;

  i2c_write(ITG3200_ADDRESS, ITG3200_REGISTER_DLPF_FS, ITG3200_FULLSCALE | ITG3200_42HZ);

  i2c_read(ITG3200_ADDRESS, ITG3200_REGISTER_DLPF_FS, 1, &data);

  printf("%d\n",(uint8_t)data);
}

void read_itg3200() {
  uint8_t bytes[6];
  memset(bytes,0,6);

  i2c_read(ITG3200_ADDRESS, ITG3200_REGISTER_XMSB, 6, bytes);
  for (int i=0;i<3;++i) {
  gyro_data[i] = (int)bytes[2*i + 1] + (((int)bytes[2*i]) << 8);
  }
}

void init_hmc5843() {
  uint8_t data = 0;

  i2c_write(HMC5843_ADDRESS, HMC5843_REGISTER_MEASMODE, HMC5843_MEASMODE_CONT);

  i2c_read(HMC5843_ADDRESS, HMC5843_REGISTER_MEASMODE, 1, &data);
  printf("%d",(uint8_t)data);
}

void read_hmc5843() {
 uint8_t bytes[6];
 memset(bytes,0,6);

 i2c_read(HMC5843_ADDRESS, HMC5843_REGISTER_XMSB, 6, bytes);

 for (int i=0;i<3;++i) {
 magnetometer_data[i] = (int)bytes[2*i + 1] + (((int)bytes[2*i]) << 8);
 }
}
