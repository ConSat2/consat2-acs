CFLAGS = -Wall
OBJ = ./obj
SRC = ./src
BIN = ./bin
INC = ./include

all: i2c.o 
	g++ $(CFLAGS) $(OBJ)/* $(SRC)/example.cpp -o $(BIN)/example.out

i2c.o:
	g++ $(CFLAGS) $(SRC)/i2c.cpp -c -o $(OBJ)/i2c.o

clean:	
	rm $(OBJ)/* $(BIN)/* $(INC)/*~ $(SRC)/*~ *~
