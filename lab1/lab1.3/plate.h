#ifndef PLATE_H
#define PLATE_H

#define DEFAULT_RADIUS 10

#include <string>
#include "item.h"

class Plate : public Item {
public:
    Plate();
    Plate(
        const int &radius, const int &height,
        const int &x, const int &y, const int &m
    );
    Plate(const Plate &plate);
    Plate(const std::string &string);

    ~Plate();

    virtual bool dotInBorders(float x, float y) const;

    int getRadius() const;

    virtual std::string toString() const;

private:
    int _radius;
};

#endif