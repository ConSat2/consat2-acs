#ifndef __WATCHDOG_H__
#define __WATCHDOG_H__

void watchdog_force_cpu_rest(void);
void watchdog_enable(uint32_t seconds);
void watchdog_disable(void);
void watchdog_init(void);
void watchdog_set_period(uint32_t period);

#endif
