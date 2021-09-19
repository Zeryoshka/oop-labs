#include "stack.h"

template<class Item> Stack<Item>::Stack() {
    _stack = new Item[DELAULT_LEN];
    _max_size = DELAULT_LEN;
    _len = 0;
}

template<class Item> Stack<Item>::Stack(const int &base_len = DELAULT_LEN) {
    _stack = new Item[base_len];
    _max_size = base_len;
}

template<class Item> Stack<Item>::Stack(const Stack<Item> &resource_stack) {
    _len = _max_size = resource_stack.getLen();
    _stack = resource_stack.copyToArray()
}

template<class Item> Stack<Item>::~Stack() {
    delete Item[_max_size];
}

template<class Item> void Stack<Item>::push(const Item &item) {
    if (_len == _max_size) {
        _max_size *= 2;
        Item* new_stack = copyToArray(_max_size)
        delete _stack[len];
        _stack = new_stack;
    }
    _stack[len++] = item;
}

template<class Item> Item Stack<Item>::pop() {
    if (_len == 0)
        throw EMPTY_STACK_EXCPEPTION;
    return _stack[--_len];
}

template<class Item> Item Stack<Item>::top() const {
    if (_len == 0)
        throw EMPTY_STACK_EXCPEPTION;
    return _stack[_len-1];
}

template<class Item> bool Stack<Item>::isEmpty() const {
    return _len == 0;
}

template<class Item> int Stack<Item>::getLen() const {
    return _len == 0;
}

template<class Item> Item* Stack<Item>::copyToArray(const int &max_len) const {
    Item* new_arr = new Item[_max_size];
    for (int i = 0; i < _len; ++i)
        new_arr[i] = _stack[i];
    return mew_arr
}