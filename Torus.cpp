#include "Torus.h"
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

// Constructor for the Torus class, we assume that we always get the correct number / type of parameters
Torus::Torus(const string& name, double innerRadius, double outerRadius)
    : Shape(name), innerRadius(innerRadius), outerRadius(outerRadius) {} 

// Setters and Getters for the Torus class
void Torus::setInnerRadius(double innerRadius) {
    this->innerRadius = innerRadius;
}

void Torus::setOuterRadius(double outerRadius) {
    this->outerRadius = outerRadius;
}

double Torus::getInnerRadius() const {
    return innerRadius;
}

double Torus::getOuterRadius() const {
    return outerRadius;
}

// Function to get the name of the shape type
string Torus::getType() const {
    return "torus";
}

// Function to calculate the surface area of the torus
double Torus::getArea() const {
    return 4 * PI * PI * innerRadius * outerRadius;
}

// Function to calculate the volume of the torus
double Torus::getVolume() const {
    return 2 * PI * PI * innerRadius * outerRadius * outerRadius;
}

// Function to get information string of the torus
string Torus::getInfo() const {
    stringstream ss;
    ss << fixed << setprecision(2);
    ss << "Torus: " << getName() << ", Small Radius=" << innerRadius << ", Big Radius=" << outerRadius << "\n";
    ss << "\tSurface Area=" << getArea() << ", Volume=" << getVolume();
    return ss.str();
}




