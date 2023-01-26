CC=g++
CCFLAGS= -Wall -std=c++11 -g
LIBFLAGS= -I/usr/include/SDL2
LIBFLAGS2= -lSDL2_image -lSDL2_ttf -lSDL2
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)
EXEC= monopoly


all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(LIBFLAGS) $^ -o $@ $(LIBFLAGS2)

%.o: %.cc
	$(CC) $(CCFLAGS) -o $@ $(LIBFLAGS) -c $< $(LIBFLAGS2)

.depend:
	g++ $(CCFLAGS) -MM $(SRC) > .depends
-include .depends

clean:
	rm -f $(OBJ) $(EXEC)

