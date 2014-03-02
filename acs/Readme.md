#ACS

Using Sparkfun's 9DOF Sensor Stick

3 sensors: accelerometer, magnetometer, gyroscope

##Option 1 to enable all devices:
note: for now we assume the ina2xx driver has already been instantiated
hmc 5883 is hardwired to:

bus: i2c-1

address: 0x1e

echo hmc5883 0x1e > /sys/bus/i2c/devices/i2c-1/new_device (same as modprobe hmc5843)

The data values can be read from the dev system if the existing module is loaded and instantiated

DEV_FILES:

*/sys/bus/i2c/devices/1-001e/iio\:device2/in_magn_x_raw

*/sys/bus/i2c/devices/1-001e/iio\:device2/in_magn_y_raw

*/sys/bus/i2c/devices/1-001e/iio\:device2/in_magn_z_raw

*/sys/bus/i2c/devices/1-001e/iio\:device2/in_magn_raneg

*/sys/bus/i2c/devices/1-001e/iio\:device2/in_magn_scale

##Option 2 to enable all devices:

*bbb --enable-i2c-device 1 --address 0x53 --module adxl34x

*bbb --enable-i2c-device 1 --address 0x1e --module hmc5883

*bbb --enable-i2c-device 1 --address 0x68 --module st_gyro

##Tested (possible issues):
loaded adxl34x, but could not initialize

root@beaglebone:~/code# dmesg | grep 'adxl'

[ 1247.119920] i2c i2c-1: new_device: Instantiated device adxl34x at 0x53

[ 1247.155043] adxl34x 1-0053: no IRQ?

for working device:

root@beaglebone:~/code# dmesg | grep 'hmc'

[ 1444.165828] i2c i2c-1: new_device: Instantiated device hmc5883 at 0x1e

[ 1444.186834] hmc5843: module is from the staging directory, the quality is unknown, you have been warned.

[ 1444.195939] hmc5883 initialized

To read:

http://lxr.free-electrons.com/source/drivers/input/misc/?a=arm

http://wiki.analog.com/resources/tools-software/linux-drivers/input-misc/adxl345

http://lxr.free-electrons.com/source/drivers/iio/gyro/

## References
1. https://github.com/cagdasc/BeagleBoneBlack-I2C
2. https://github.com/ajaykumarkannan/Beaglebone-I2C
3. https://github.com/justjoheinz/beagleboneIO
4. https://github.com/prpplague/Userspace-Arduino
5. http://robotosh.blogspot.ca/2012/03/sparkfun-9dof-imu-sensor-stick.html
6. https://github.com/ptrbrtz/razor-9dof-ahrs/wiki/Tutorial
