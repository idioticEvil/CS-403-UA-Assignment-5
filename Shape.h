#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <string>
#include <vector>

#define PI  3.14159265358979323846

class Shape {
    public:
        Shape(const std::string&);
        virtual ~Shape() = default; // compiler generates virtual destructor

        void setName(const std::string&);
        bool test(const std::vector<std::string>& cond) const;
        std::string getName() const;

        virtual std::string getType() const = 0; // get the type of the shape
        virtual double getArea() const = 0; // get the surface area          
        virtual double getVolume() const = 0; // get the volume          
        virtual std::string getInfo() const = 0; // get all the info in a string

    protected:
        // Helper functions for comparison
        bool compareNumeric(double lhs, const std::string& op, double rhs) const;
        bool compareString(const std::string& lhs, const std::string& op, const std::string& rhs) const;
    
    private:
        std::string name;
};

#endif