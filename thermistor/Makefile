# Warning flags
WARNINGS= -wall -Wextra -fpermissive
#C Compiler
CCFLAGS = -c $(Warnings)
BEAGLECC=g++

LIBS := libshakespeare-BB.a

read-thermistor: $(LIBS)
	$(BEAGLECC) read-thermistor.cpp -L./ -lshakespeare-BB -o $@
