#ifndef __PAYLOAD_H__
#define __PAYLOAD_H__

// TODO:
// Benchmark payload response time
// Check analog reads

#define PAYLOAD_POWER "P9_16" // GPIO_51
#define REGULAR_EXPERIMENT "P9_13" // GPIO_31
#define HEALING_EXPERIMENT "P9_11" // GPIO_30
#define COMPARATOR "P9_15" // GPIO_48
#define SH_LOAD_CELL "P9_37" // AIN2
#define SH_PHOTODIODE "P9_33"  // AIN4
#define SH_THERMISTOR "P8_7" // GPIO_66
#define R_THERMISTOR "P8_9" // GPIO_69
#define EXT_THERMISTOR "P8_11" // GPIO_45
#define R_LOAD_CELL "P9_39" // AIN0
#define R_PHOTODIODE "P9_35" // AIN6
#define SH_HEATER "P9_41" // GPIO_20
#define R_HEATER "P8_8" // GPIO_67

// Initilizes payload experiments
// Init specifically per experiment?
void payload_init();

// Selects the experiment to run
void payload_start_experiment(uint8_t experiment_number);

// Terminate given experiment
void payload_end_experiment(uint8_t experiment_number);

// Turns on the power for the payload board
void payload_set_power(uint8_t value);

// Read analog outputs(voltages) of the load cell (force applied to the material)
float payload_read_load_cell(uint8_t experiment_number);

// Read analog output(voltages) of the photodiode (resulted strain)
float payload_read_photodiode(uint8_t experiment_number);

// Read digital output(degrees) of the thermistor (temperature of the heaters)
float payload_read_temperature(uint8_t experiment_number);

// Handles upon input received from the comparator
void payload_handle_comparator();

// Turn the heaters on/off for a given experiment
void payload_set_heaters(uint8_t experiment_number, uint8_t value);

#endif
