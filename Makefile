TARGET = mass
CC = cc
CFLAGS = -g
OBJ = vector.o list.o #polygon.o

all: main.c $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $^ -lm

vector.o: vector.c vector.h
	$(CC) $(CFLAGS) -c $< -lm

list.o: list.c list.h
	$(CC) $(CFLAGS) -c $<

polygon.o: polygon.c polygon.h
	$(CC) $(CFLAGS) -c $< -lm

clean:
	rm *.o
