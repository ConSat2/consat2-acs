#ifndef __THERMAL_H__
#define __THERMAL_H__

typedef enum thermal_sensors_e {
  THERMAL_SENSOR_MECH1 = 0;
  THERMAL_SENSOR_MECH2 = 1;
  THERMAL_SENSOR_MECH3 = 2;
  THERMAL_SENSOR_MECH4 = 3;
  THERMAL_SENSOR_MECH5 = 4;
  THERMAL_SENSOR_MECH6 = 5;
  THERMAL_SENSOR_MECH7 = 6;
  THERMAL_SENSOR_MECH8 = 7;
  THERMAL_SENSOR_MECH9 = 8;
  THERMAL_SENSOR_MECH10 = 9;
  THERMAL_SENSOR_PAYLOAD1 = 10;
  THERMAL_SENSOR_PAYLOAD2 = 10;
};

bool thermal_get_temperature(thermal_sensors_e sensor, int32_t *temperature);

#endif /* __THERMAL_H__ */
