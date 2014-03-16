# Warning flags
WARNINGS= -wall -Wextra -fpermissive
#C Compiler
CCFLAGS = -c $(Warnings)
CC=g++
BEAGLECC=arm-linux-gnueabi-g++

SRCS    := read-thermistor.c of2g.c
SRCS    := $(addprefix src/, $(SRCS))

LIBS     := libshakespeare.a
LIBS     := $(addprefix lib/, $(LIBS))
INCFLAGS = -I./lib/include

BEAGLELIBS    := libshakespeare-BB.a
BEAGLELIBS    := $(addprefix lib/, $(BEAGLELIBS))

read-thermistor: $(LIBS)
	$(BEAGLECC) read-thermistor.cpp -L./BEAGLELIBS -lshakespeare-BB -o $@