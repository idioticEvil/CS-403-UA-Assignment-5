#ifndef _SPHERE_H_
#define _SPHERE_H_

#include <string>
#include <vector>
#include "Shape.h"

class Sphere : public Shape {
    public:
        Sphere(const std::string& name, double radius);

        void setRadius(double radius);
        double getRadius() const;

        virtual double getArea() const override;
        virtual double getVolume() const override;
        virtual std::string getInfo() const override;
        virtual std::string getType() const override;
        
    private:
        double radius;
};

#endif