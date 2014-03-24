#ifndef __PAYLOAD_H__
#define __PAYLOAD_H__

#define EXPERIMENT_TOTAL_LENGTH 5

void payload_start_experiment(uint8_t experiment_number);
void payload_end_experiment(uint8_t experiment_number);
void payload_set_power(uint8_t value);
float payload_read_load_cell(uint8_t experiment_number);
float payload_read_photodiode(uint8_t experiment_number);
float payload_read_temperature(uint8_t experiment_number);

#endif
