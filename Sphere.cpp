#include "Sphere.h"
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

// Constructor for the Sphere class, we assume that we always get the correct number / type of parameters
Sphere::Sphere(const string& name, double radius) 
    : Shape(name), radius(radius) {}

// Setters and Getters for the Sphere class
void Sphere::setRadius(double radius) {
    this->radius = radius;
}

double Sphere::getRadius() const {
    return radius;
}

// Function to get the name of the type
string Sphere::getType() const {
    return "sphere";
}

// Function to calculate the surface area of the sphere
double Sphere::getArea() const {
    return 4 * PI * radius * radius;
}

// Function to calculate the volume of the sphere
double Sphere::getVolume() const {
    return (4.0 / 3.0) * PI * radius * radius * radius;
}

// Function to get information string of the sphere
string Sphere::getInfo() const {
    stringstream ss;
    ss << fixed << setprecision(2);
    ss << "Sphere: " << getName() << ", Radius=" << radius << "\n";
    ss << "\tSurface Area=" << getArea() << ", Volume=" << getVolume();
    return ss.str();
}

