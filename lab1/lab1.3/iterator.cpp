#include "iterator.h"

Iterator::Iterator(ItemVariant* arr, const int &len) {
    _arr = arr;
    _len = len;
    _i = 0;
}

Iterator::~Iterator() {}

void Iterator::head() {
    _i = 0;
}
bool Iterator::isLast() {
    if (_len - 1 == _i)
        return true;
    return false;
}
void Iterator::next() {
    _i++;
    if (_len == _i)
        throw LAST_EXCEPTION;
}
ItemVariant Iterator::value() const {
    return _arr[_i];
}
