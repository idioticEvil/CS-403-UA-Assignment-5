# Makefile for compiling C++ programs
CXX = g++
CXXFLAGS = -Wall -std=c++11

# List all your source files here
SOURCES = main.cpp Reading.cpp Shape.cpp Box.cpp Cylinder.cpp Sphere.cpp Torus.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = a.out

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
