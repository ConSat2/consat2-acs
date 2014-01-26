CFLAGS = -Wall
OBJ = ./obj
SRC = ./src
BIN = ./bin
INC = ./include

acs: i2c.o
	g++ $(CFLAGS) src/i2c.o $(SRC)/acs.cpp -o $(BIN)/acs

i2c.o:
	g++ $(CFLAGS) $(SRC)/i2c.cpp -c -o src/i2c.o

clean:
	rm $(OBJ)/* $(BIN)/* $(INC)/*~ $(SRC)/*~ *~
