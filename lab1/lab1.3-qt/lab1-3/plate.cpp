#include "plate.h"
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

Plate::Plate() : Item() {
    _radius = DEFAULT_RADIUS;
    _code = PLATE_CODE;
}

Plate::Plate(
        const int &radius, const int &height,
        const int &x, const int &y, const int &m
) : Item(x, y, m, height) {
    _code = PLATE_CODE;
    _radius = radius;
}

Plate::Plate(const Plate &plate) {
    _code = PLATE_CODE;
    _radius = plate.getRadius();
    _height = plate.getHeight();
    _x = plate.getX();
    _y = plate.getY();
    _m = plate.getM();
}

Plate::Plate(const string &s) {
    _code = PLATE_CODE;
    stringstream parse;
    parse << s;
    parse >> _x >> _y >> _m >>  _height >> _radius;
}

string Plate::toString() const {
    stringstream line;
    line << Item::toString() << " " << _radius;
    return line.str();
}

Plate::~Plate() {}

bool Plate::dotInBorders(float x, float y) const {
    x -= _x;
    y -= _y;
    if ( (x*x + y*y) <= _radius*_radius)
        return true;
    return false;
}

int Plate::getRadius() const {
    return _radius;
}
