TARGET = prog.out
LIBS = -lSDL2main -lSDL2 -lm
CC = g++
CFLAGS = -fPIC -Wall -Werror -Wextra -Wno-unused-result -Wno-unused-parameter -Wno-unused-variable -O2

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS)  $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
