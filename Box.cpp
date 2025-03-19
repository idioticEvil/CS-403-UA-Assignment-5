#include "Box.h"
#include <sstream>
#include <iomanip>

using namespace std;

// Constructor for the Box class, we assume that we always get the correct number / type of parameters
Box::Box(const std::string& name, double length, double height, double width) 
    : Shape(name), length(length), height(height), width(width) {}

// Setters and Getters for the Box class
void Box::setLength(double length) {
    this->length = length;
}

void Box::setHeight(double height) {
    this->height = height;
}

void Box::setWidth(double width) {
    this->width = width;
}

double Box::getLength() const {
    return length;
}

double Box::getHeight() const {
    return height;
}

double Box::getWidth() const {
    return width;
}

// Function to calculate the surface area of the box
double Box::getArea() const {
    return 2 * (length * width + length * height + width * height);
}

// Function to calculate the volume of the box
double Box::getVolume() const {
    return (length * width * height);
}

// Function to get information string of the box
string Box::getInfo() const {
    stringstream ss;
    ss << fixed << setprecision(2);
    ss << "Box: " << getName() << ", Length=" << length << ", Width=" << width << ", Height=" << height << "\n";
    ss << "\tSurface Area=" << getArea() << ", Volume=" << getVolume();
    return ss.str();
}

std::string Box::getType() const {
    return "box";
}
