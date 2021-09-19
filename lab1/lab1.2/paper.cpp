#include "paper.h"

Paper::Paper() {
    _width = DEFAULT_WIDTH;
    _height = DEFAULT_HEIGHT;
    _length = DEFAULT_LENGTH;
    _x = DEFAULT_POSITION_X;
    _y = DEFAULT_POSITION_Y;
}

Paper::Paper(
        const int &width, const int &length, const int &height,
        const int &x, const int &y
) {
    _width = width;
    _height = length;
    _length = height;
    _x = x;
    _y = y;
}

Paper::Paper(const Paper &paper) {
    _width = paper.getWidth();
    _height = paper.getHeight();
    _length = paper.getLength();
    _x = paper.getX();
    _y = paper.getY();
}

Paper::~Paper() {}

int Paper::getWidth() const {
    return _width;
}
int Paper::getLength() const {
    return _length;
};
int Paper::getHeight() const {
    return _height;
};
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