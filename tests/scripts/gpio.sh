# Payload power switch (P9_16)
echo 51 > "/sys/class/gpio/export" 
echo out > "/sys/class/gpio/export/gpio51/direction" # Set as output
# echo 1 > "/sys/class/gpio/gpio51/value" # set GPIO to HIGH

# Regular material experiment (Set #1) switch (P9_13)
echo 31 > "/sys/class/gpio/export" 
echo out > "/sys/class/gpio/export/gpio31/direction" 
# echo 1 > "/sys/class/gpio/gpio51/value"

# Self-healing material experiment (Set #2) switch (P9_11)
echo 30 > "/sys/class/gpio/export" 
echo out > "/sys/class/gpio/export/gpio30/direction" 
# echo 1 > "/sys/class/gpio/gpio51/value"

# Heater for self-healing material switch (P9_41)
echo 20 > "/sys/class/gpio/export" 
echo out > "/sys/class/gpio/export/gpio20/direction" 
# echo 1 > "/sys/class/gpio/gpio51/value"

# Heater for regular material switch (P8_8)
echo 67 > "/sys/class/gpio/export" 
echo out > "/sys/class/gpio/export/gpio67/direction" 
# echo 1 > "/sys/class/gpio/gpio51/value"

# Deployment switch (P8_12)
echo 44 > "/sys/class/gpio/export" 
echo out > "/sys/class/gpio/export/gpio44/direction" 
# echo 1 > "/sys/class/gpio/gpio51/value"
