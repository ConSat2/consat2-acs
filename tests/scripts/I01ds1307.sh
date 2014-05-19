#! /bin/sh
# https://unix.stackexchange.com/questions/98038/restrictions-of-etc-profile-in-gnome
if lsmod | grep rtc-ds1307 &> /dev/null ; then
if [ "$1" == "-r" ]; then
echo 0x68 > /sys/bus/i2c/devices/i2c-1/delete_device
    sed -i "s|RTCDS3232PATH=.*|RTCDS3232PATH='unset'|g" /etc/profile
    modprobe -r rtc-ds1307
    exit 0
  else
echo "rtc-ds1307 is loaded!"
    exit 0
  fi
else
  # Realtime clock
  if modprobe rtc-ds1307; then
echo ds1307 0x68 > /sys/bus/i2c/devices/i2c-1/new_device
    driverpath=$(find /sys/bus/i2c/devices/1-0068/ -type d -name 'iio:device*')
    sed -i "s|RTCDS3232PATH=.*|RTCDS3232PATH='$driverpath'|g" /etc/profile
    export RTCDS3232PATH="$driverpath"
    exit 1 # not sure if driver was loading correctly
  fi
fi
