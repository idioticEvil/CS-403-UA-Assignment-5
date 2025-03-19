#ifndef _BOX_H_
#define _BOX_H_

#include <string>
#include <vector>
#include "Shape.h"

class Box : public Shape {
    public:
        Box(const std::string& name, double length, double width, double height);

        void setLength(double length);
        void setHeight(double height);
        void setWidth(double width);
        double getLength() const;
        double getHeight() const;
        double getWidth() const;

        virtual double getArea() const override;
        virtual double getVolume() const override;
        virtual std::string getInfo() const override;
        virtual std::string getType() const override;
        
    private:
        double length;
        double height;
        double width;
};

#endif