#ifndef _CYLINDER_H_
#define _CYLINDER_H_

#include <string>
#include <vector>
#include "Shape.h"

class Cylinder : public Shape {
    public:
        Cylinder(const std::string& name, double radius, double height);

        void setRadius(double radius);
        void setHeight(double height);
        double getRadius() const;
        double getHeight() const;

        virtual double getArea() const override;
        virtual double getVolume() const override;
        virtual std::string getInfo() const override;
        virtual std::string getType() const override;
        
    private:
        double radius;
        double height;
};

#endif