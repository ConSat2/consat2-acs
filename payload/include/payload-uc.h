#ifndef __PAYLOAD_UC_H__
#define __PAYLOAD_UC_H__

void setHeater(int value);
void setPower(int value);
void startExperiment(int value);
void handle_comparator(void);
void handle_bbb_power(void);
void handle_bbb_set_experiment(int experiment);

#endif
