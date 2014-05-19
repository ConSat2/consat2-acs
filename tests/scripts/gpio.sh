# Payload power switch
echo 51 > "/sys/class/gpio/export" 
echo out > "/sys/class/gpio/export/gpio51/direction" # Set as output
# echo 1 > "/sys/class/gpio/gpio51/value" # set GPIO to HIGH

# Regular material experiment (Set #1) switch
echo 31 > "/sys/class/gpio/export" 
echo out > "/sys/class/gpio/export/gpio31/direction" 
# echo 1 > "/sys/class/gpio/gpio51/value"

# Self-healing material experiment (Set #2) switch
echo 30 > "/sys/class/gpio/export" 
echo out > "/sys/class/gpio/export/gpio30/direction" 
# echo 1 > "/sys/class/gpio/gpio51/value"

# Heater for self-healing material switch
echo 20 > "/sys/class/gpio/export" 
echo out > "/sys/class/gpio/export/gpio20/direction" 
# echo 1 > "/sys/class/gpio/gpio51/value"

# Heater for regular material switch
echo 67 > "/sys/class/gpio/export" 
echo out > "/sys/class/gpio/export/gpio67/direction" 
# echo 1 > "/sys/class/gpio/gpio51/value"

# Deployment switch (P8_44)
echo 44 > "/sys/class/gpio/export" 
echo out > "/sys/class/gpio/export/gpio44/direction" 
# echo 1 > "/sys/class/gpio/gpio51/value"
