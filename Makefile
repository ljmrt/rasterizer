TARGET = prog.out
LDLIBS = -lSDL2main -lSDL2
CXX = g++
CXXFLAGS = -g -fPIC -Wall -Werror -Wextra -Wno-unused-result -Wno-unused-parameter -Wno-unused-variable -O2

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) $(CXXFLAGS)  $(LDLIBS) -o $@

clean:
	-rm -f *.o
	-rm -f \#*\#
	-rm -f *~
	-rm -f $(TARGET)
