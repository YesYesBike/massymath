TARGET = mass
CC = cc
CFLAGS = -g
OBJ = vector.o polygon.o

all: main.c $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $^ -lm

vector.o: vector.c vector.h
	$(CC) $(CFLAGS) -c $< -lm

polygon.o: polygon.c polygon.h
	$(CC) $(CFLAGS) -c $< -lm
