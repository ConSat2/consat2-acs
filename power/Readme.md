#Power Sensor (INA 219)
http://www.ti.com/product/ina219

The INA219 is a high-side current shunt and power monitor with an I2C interface. The INA219 monitors both shunt drop and supply voltage, with programmable conversion times and filtering. A programmable calibration value, combined with an internal multiplier, enables direct readouts in amperes. An additional multiplying register calculates power in watts. The I2C interface features 16 programmable addresses.

note: for now we assume the ina2xx driver has already been instantiated
ina219 is hardwired to:

bus: i2c-1

address: 0x40

The data values can be read from the dev system if the existing module is loaded and instantiated

DEV_FILES:

/sys/bus/i2c/devices/1-0040/curr1_input :: current through Rsens

/sys/bus/i2c/devices/1-0040/in0_input :: voltage across Rsens

/sys/bus/i2c/devices/1-0040/in1_input :: voltage from Bus to Gnd

/sys/bus/i2c/devices/1-0040/power1_input :: power through Rsens
