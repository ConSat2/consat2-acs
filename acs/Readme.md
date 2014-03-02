#ACS

Using Sparkfun's 9DOF Sensor Stick

3 sensors: accelerometer, magnetometer, gyroscope

Tested (possible issues):
- loaded adxl34x
root@beaglebone:~/code# dmesg | grep 'adxl'
[ 1247.119920] i2c i2c-1: new_device: Instantiated device adxl34x at 0x53
[ 1247.155043] adxl34x 1-0053: no IRQ?

for working device:
root@beaglebone:~/code# dmesg | grep 'hmc'
[ 1444.165828] i2c i2c-1: new_device: Instantiated device hmc5883 at 0x1e
[ 1444.186834] hmc5843: module is from the staging directory, the quality is unknown, you have been warned.
[ 1444.195939] hmc5883 initialized
[ 1678.919394] i2c i2c-1: delete_device: Deleting device hmc5883 at 0x1e

To read:
** http://lxr.free-electrons.com/source/drivers/input/misc/?a=arm
** http://wiki.analog.com/resources/tools-software/linux-drivers/input-misc/adxl345

## References
1. https://github.com/cagdasc/BeagleBoneBlack-I2C
2. https://github.com/ajaykumarkannan/Beaglebone-I2C
3. https://github.com/justjoheinz/beagleboneIO
4. https://github.com/prpplague/Userspace-Arduino
5. http://robotosh.blogspot.ca/2012/03/sparkfun-9dof-imu-sensor-stick.html
6. https://github.com/ptrbrtz/razor-9dof-ahrs/wiki/Tutorial
