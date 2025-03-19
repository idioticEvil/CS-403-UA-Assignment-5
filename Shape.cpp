// #include <sstream>
#include "Shape.h"
#include <cmath>
#include <iostream>

using namespace std;

// Constructor for the Shape class
Shape::Shape(const string& name)
   : name(name)
{}

// This function gets the name of the shape
void Shape::setName(const string& name) {
	this->name = name;
}

// This function gets the name of the shape
string Shape::getName() const {
	return name;
}

// This function compares two numeric values based on the operator provided
bool Shape::compareNumeric(double lhs, const string& op, double rhs) const {
	const double epsilon = 1e-6;

	if (op == "==") {
		return fabs(lhs - rhs) < epsilon;
	} else if (op == "!=") {
		return fabs(lhs - rhs) >= epsilon;
	} else if (op == ">") {
		return lhs > rhs;
	} else if (op == "<") {
		return lhs < rhs;
	} else if (op == ">=") {
		return lhs >= rhs || fabs(lhs - rhs) < epsilon;
	} else if (op == "<=") {
		return lhs <= rhs || fabs(lhs - rhs) < epsilon;
	} else {
		cout << "Error: " << op << " is an invalid operator" << endl;
		return false;
	}
}

// This function compares two strings based on the operator provided
bool Shape::compareString(const std::string& lhs, const std::string& op, const std::string& rhs) const {
	if (op == "==") {
		return lhs == rhs;
	} else if (op == "!=") {
		return lhs != rhs;
	} else if (op == ">") {
		return lhs > rhs;
	} else if (op == "<") {
		return lhs < rhs;
	} else if (op == ">=") {
		return lhs >= rhs;
	} else if (op == "<=") {
		return lhs <= rhs;
	} else {
		cout << "Error: " << op << " is an invalid operator" << endl;
		return false;
	}
}

// Function to test if the sphere satisfies given conditions
bool Shape::test(const vector<string>& cond) const {
    // Check if the conditions are valid / even present
    if (cond.empty() || cond.size() % 3 != 0) {
        return true;
    }

    // Iterate through the conditions
    for (size_t i = 0; i < cond.size(); i += 3) {
        string name = cond[i];
        string op = cond[i + 1];
        string value = cond[i + 2];

        if (name == "type") { 
            // Do lexicographical comparisions
            if (!compareString(getType(), op, value)) return false;
        } else if (name == "area") { 
            double area = getArea();
            double convertedValue;

            // Check if the value can be converted to a double
            try {
                convertedValue = stod(value);
            } catch (const std::invalid_argument&) {
                cout << "Error: Invalid numeric value: " << value << endl;
                return false;
            }

            // Do numeric comparisions for area
            if(!compareNumeric(area, op, convertedValue)) return false;
        } else if (name == "volume") {
            double volume = getVolume();
            double convertedValue;

            // Check if the value can be converted to a double
            try {
                convertedValue = stod(value);
            } catch (const std::invalid_argument&) {
                cout << "Error: Invalid numeric value: " << value << endl;
                return false;
            }

            // Do numeric comparisions for volume
            if(!compareNumeric(volume, op, convertedValue)) return false;
        } else {
            // If the name is not recognized, print an error message, and return false
            cout << name << ": invalid column." << endl;
            return false;
        }
    }
    return true;
}