#ifndef __PAYLOAD_UC_H__
#define __PAYLOAD_UC_H__

void set_heater(uint8_t value);
void set_power(uint8_t value);
void start_experiment(uint8_t value);
void handle_comparator(void);
void handle_bbb_power(void);
void handle_bbb_set_experiment(uint8_t experiment);

#endif
