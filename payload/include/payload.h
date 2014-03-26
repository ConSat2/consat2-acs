#ifndef __PAYLOAD_H__
#define __PAYLOAD_H__

// TODO:
// Verify pins
// Benchmark payload response time
// Check analog reads

#define PAYLOAD_POWER "P9_11"
#define REGULAR_EXPERIMENT "P9_12"
#define HEALING_EXPERIMENT "P9_13"
#define COMPARATOR "P9_14"
#define EXP1_LOAD_CELL "P9_15"
#define EXP1_PHOTODIODE "P9_16"
#define EXP1_THERMISTOR "P9_17"
#define EXP2_LOAD_CELL "P9_18"
#define EXP2_PHOTODIODE "P9_19"
#define EXP1_HEATER "P9_20"
#define EXP2_HEATER "P9_21"

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
