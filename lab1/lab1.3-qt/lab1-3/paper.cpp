#include "paper.h"
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

Paper::Paper() : Item() {
    _code = PAPER_CODE;
    _width = DEFAULT_WIDTH;
    _length = DEFAULT_LENGTH;
}

Paper::Paper(
        const int &length, const int &width, const int &height,
        const int &x, const int &y, const int &m
) : Item(x, y, m, height) {
    _code = PAPER_CODE;
    _width = width;
    _length = length;
}

Paper::Paper(const Paper &paper) {
    _code = PAPER_CODE;
    _width = paper.getWidth();
    _length = paper.getLength();
    _height = paper.getHeight();
    _x = paper.getX();
    _y = paper.getY();
    _m = paper.getM();
}

Paper::Paper(const string &s) {
    _code = PAPER_CODE;
    stringstream parse;
    parse << s;
    parse >> _x >> _y >> _m >> _width >> _height >> _length;
}

string Paper::toString() const {
    stringstream line;
    line << Item::toString() << " " << _width << " " <<
        _length;
    return line.str();
}

Paper::~Paper() {}

bool Paper::dotInBorders(float x, float y) const {
    x -= _x;
    y -= _y;
    if (x < -_length / 2 || x > _length / 2)
        return false;
    if (y < -_width / 2 || y > _width / 2)
        return false;
    return true;
}

int Paper::getWidth() const {
    return _width;
}
int Paper::getLength() const {
    return _length;
}
