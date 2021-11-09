#include "iterator.h"

Iterat::Iterat(ItemVariant* arr, const int &len) {
    _arr = arr;
    _len = len;
    _i = 0;
}

Iterat::~Iterat() {}

void Iterat::head() {
    _i = 0;
}
bool Iterat::isLast() {
    if (_len - 1 == _i)
        return true;
    return false;
}
void Iterat::next() {
    _i++;
    if (_len == _i)
        throw LAST_EXCEPTION;
}
ItemVariant Iterat::value() const {
    return _arr[_i];
}
