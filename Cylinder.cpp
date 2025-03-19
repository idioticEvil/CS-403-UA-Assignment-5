#include "Cylinder.h"
#include <sstream>
#include <iomanip>

using namespace std;

// Constructor for the Cylinder class, we assume that we always get the correct number / type of parameters
Cylinder::Cylinder(const std::string& name, double radius, double height) 
    : Shape(name), radius(radius), height(height) {}

// Setters and Getters for the Cylinder class
void Cylinder::setRadius(double radius) {
    this->radius = radius;
}

void Cylinder::setHeight(double height) {
    this->height = height;
}

double Cylinder::getRadius() const {
    return radius;
}

double Cylinder::getHeight() const {
    return height;
}

// Function to calculate the surface area of the Cylinder
double Cylinder::getArea() const {
    return 2 * PI * radius * (radius + height);
}

// Function to calculate the volume of the Cylinder
double Cylinder::getVolume() const {
    return PI * radius * radius * height;
}

// Function to get information string of the Cylinder
string Cylinder::getInfo() const {
    stringstream ss;
    ss << fixed << setprecision(2);
    ss << "Cylinder: " << getName() << ", Radius=" << radius << ", Height=" << height << "\n";
    ss << "\tSurface Area=" << getArea() << ", Volume=" << getVolume();
    return ss.str();
}

std::string Cylinder::getType() const {
    return "cylinder";
}

