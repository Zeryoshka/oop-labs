#ifndef ITERATOR_H
#define ITERATOR_H
#define LAST_EXCEPTION

#include <string>
#include "stack.h"

class Iterator {
public:
    Iterator(ItemVariant* stack, const int &len);
    ~Iterator();
    ItemVariant value() const;
    void next();
    void head();
    bool isLast();

private:
    ItemVariant *_arr;
    int _len = 0;
    int _i = 0;
};

#endif