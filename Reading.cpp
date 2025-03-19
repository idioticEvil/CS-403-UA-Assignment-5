#include "Reading.h"
#include "Shape.h"
#include "Box.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Torus.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// Takes a istringstream of a shape's data as an input and returns a pointer to the resulting shape object
Shape* createShape(istringstream& lineStream) {
    string shapeName, shapeType;
    lineStream >> shapeName;
    lineStream >> shapeType;

    if (shapeType == "box") {
        double length, width, height;
        lineStream >> length >> width >> height;
        return new Box(shapeName, length, width, height);
    } else if (shapeType == "sphere") {
        double radius;
        lineStream >> radius;
        return new Sphere(shapeName, radius);
    } else if (shapeType == "cylinder") {
        double radius, height;
        lineStream >> radius >> height;
        return new Cylinder(shapeName, radius, height);
    } else if (shapeType == "torus") {
        double innerRadius, outerRadius;
        lineStream >> innerRadius >> outerRadius;
        return new Torus(shapeName, innerRadius, outerRadius);
    }

    // Print errors and return nullptr if the shape type is not recognized
    cout << "Error: Unknown shape type " << shapeType << endl;
    cout << "Skipping line: " << lineStream.str() << endl;
    return nullptr;
}

// Opens file with name matching the input, and returns a pointer to a vector of shape objects from
// the processed data
vector<Shape*> *readFrom(string filename) {
    // Open file with shape data inside, and start shape vector
    ifstream infile(filename);
    vector<Shape*> *shapes = new vector<Shape*>();

    // Check if we even opened the file
    if (!infile.is_open()) {
        cout << "Error: File " << filename << " could not be opened." << endl;
        return shapes;
    }

    // Read file line by line & word by word to parse out shapes
    string currentLine;
    while (getline(infile, currentLine)) {
        // Create a new shape object and add it to the vector
        istringstream lineStream(currentLine);
        Shape* newShape = createShape(lineStream);
        if (newShape) {
            shapes->push_back(newShape);
        }
    }

    // Close the file
    infile.close();

    // Return the vector of shapes
    return shapes;
}