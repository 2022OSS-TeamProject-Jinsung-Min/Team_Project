CC = gcc
CFLAGS = -W -Wall
TARGET = main
OBJECTS = main.c system.o
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o system