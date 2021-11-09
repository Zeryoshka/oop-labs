#include "paper.h"
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

Paper::Paper() {
    _width = DEFAULT_WIDTH;
    _height = DEFAULT_HEIGHT;
    _length = DEFAULT_LENGTH;
    _x = DEFAULT_POSITION_X;
    _y = DEFAULT_POSITION_Y;
    _m = DEFAULT_M;
}

Paper::Paper(
        const int &length, const int &width, const int &height,
        const int &x, const int &y, const int &m
) {
    _width = width;
    _height = height;
    _length = length;
    _x = x;
    _y = y;
    _m = m;
}

Paper::Paper(const Paper &paper) {
    _width = paper.getWidth();
    _height = paper.getHeight();
    _length = paper.getLength();
    _x = paper.getX();
    _y = paper.getY();
    _m = paper.getM();
}

Paper::Paper(const string &s) {
    stringstream parse;
    parse << s;
    parse >> _width >> _height >>
    _length >> _x >> _y >> _m;
}

string Paper::toString() const {
    stringstream parse;
    parse << _width << " " << _height << " " <<
        _length << " " << _x << " " << _y << " " << _m;
    return parse.str();
}

Paper::~Paper() {}

bool Paper::dotInBorders(float x, float y) const {
    x -= _x;
    y -= _y;
    if (x < 0 || x > _length)
        return false;
    if (y < 0 || y > _width)
        return false;
    return true;
}

int Paper::getWidth() const {
    return _width;
}
int Paper::getLength() const {
    return _length;
}
int Paper::getHeight() const {
    return _height;
}
int Paper::getX() const {
    return _x;
}
void Paper::setX(const int &x) {
    _x = x;
}
int Paper::getY() const {
    return _y;
}
void Paper::setY(const int &y) {
    _y = y;
}

int Paper::getM() const {
    return _m;
}