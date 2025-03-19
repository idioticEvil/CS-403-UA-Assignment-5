#ifndef _TORUS_H_
#define _TORUS_H_

#include <string>
#include <vector>
#include "Shape.h"

class Torus : public Shape {
    public:
        Torus(const std::string& name, double innerRadius, double outerRadius);

        void setInnerRadius(double innerRadius);
        void setOuterRadius(double outerRadius);
        double getInnerRadius() const;
        double getOuterRadius() const;

        virtual double getArea() const override;
        virtual double getVolume() const override;
        virtual std::string getInfo() const override;
        virtual std::string getType() const override;
        
    private:
        double innerRadius;
        double outerRadius;
};

#endif