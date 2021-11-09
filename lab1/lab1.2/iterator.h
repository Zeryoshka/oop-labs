#ifndef ITERATOR_H
#define ITERATOR_H
#define LAST_EXCEPTION

#include <string>

template<class Item> class Iterator {
public:
    Iterator(Item* stack, const int &len);
    ~Iterator();
    Item value() const;
    void next();
    void head();
    bool isLast();

private:
    Item *_arr;
    int _len = 0;
    int _i = 0;
};

template<class Item> Iterator<Item>::Iterator(Item* arr, const int &len) {
    _arr = arr;
    _len = len;
    _i = 0;
}

template<class Item> Iterator<Item>::~Iterator() {}

template<class Item> void Iterator<Item>::head() {
    _i = 0;
}
template<class Item> bool Iterator<Item>::isLast() {
    if (_len - 1 == _i)
        return true;
    return false;
}
template<class Item> void Iterator<Item>::next() {
    _i++;
    if (_len == _i)
        throw LAST_EXCEPTION;
}
template<class Item> Item Iterator<Item>::value() const {
    return _arr[_i];
}

#endif