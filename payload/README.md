#Payload

Basic flow of events:
1. CDH turns on the Power (switch on Power board)
2. CDH sends signal to uController to turn on Payload Power
3. CDH sends choice of the experimental setup to uController (Payload PCB)
4. CDH starts to read analog outputs (voltages): V0 (load cell) reflects the applied force, V1 (photodiode) corresponds to resulted strain, and V2 (thermistor attached to thermal actuator) corresponds to temperature on the heater.
5. CDH checks the uController status (each 0.5 sec or 1 sec) during the experiment
(if uController is not working turn off the switch)
6. CDH sends signal to uController to switch off the  power (payload has no power)
7. CDH turns off switch on Power PCB
8. 1-3 hours period between the experiments
9. CDH turns switch on (repeat procedure)

Note: Please refer to the Space wiki for additional details, such as the schematics and the design
