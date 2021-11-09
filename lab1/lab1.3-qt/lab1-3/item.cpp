#include <sstream>
#include <iostream>
#include <string>
#include <typeinfo>
#include "item.h"

using namespace std;


int Item::getX() const {
    return _x;
}

void Item::setX(const int &x) {
    _x = x;
}

int Item::getY() const {
    return _y;
}

void Item::setY(const int &y) {
    _y = y;
}

int Item::getM() const {
    return _m;
}

int Item::getHeight() const {
    return _height;
}

Item::Item(const int &x, const int &y, const int &m, const int &height) {
    _x = x;
    _y = y;
    _m = m;
    _height = height;
}

Item::Item() : Item(DEFAULT_POSITION_X, DEFAULT_POSITION_Y, DEFAULT_M, DEFAULT_HEIGHT) {
}

std::string Item::toString() const{
    stringstream parse;
    parse << _code.toStdString() << " " << _x << " " << _y <<
        " " << _m << " " << _height;
    return parse.str();
}
