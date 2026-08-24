CC = gcc
CFLAGS = -Wall -Wextra -g

SRC = main.c task.c jobs.c executor.c
TARGET = processflow

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)