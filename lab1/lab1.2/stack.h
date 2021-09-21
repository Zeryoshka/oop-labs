
#ifndef STACK_H
#define STACK_H

#define DELAULT_LEN 4
#define EMPTY_STACK_EXCPEPTION "STACK IS EMPTY"

template<class Item> class Stack {
public:
    Stack();
    Stack(const int &base_len);
    Stack(const Stack<Item> &stack);
    ~Stack();

    void push(const Item &item);
    Item pop();

    Item top() const;
    bool isEmpty() const;
    int getLen() const;

    bool isBalance() const;

    Item* copyToArray(const int &max_len) const;
private:
    Item* _stack;
    int _max_size;
    int _len;
};

template<class Item> Stack<Item>::Stack() {
    _stack = new Item[DELAULT_LEN];
    _max_size = DELAULT_LEN;
    _len = 0;
}

template<class Item> Stack<Item>::Stack(const int &base_len) {
    _stack = new Item[base_len];
    _max_size = base_len;
}

template<class Item> Stack<Item>::Stack(const Stack<Item> &resource_stack) {
    _len = _max_size = resource_stack.getLen();
    _stack = resource_stack.copyToArray(_len);
}

template<class Item> Stack<Item>::~Stack() {
    delete _stack;
}

template<class Item> void Stack<Item>::push(const Item &item) {
    if (_len == _max_size) {
        _max_size *= 2;
        Item* new_stack = copyToArray(_max_size);
        delete _stack;
        _stack = new_stack;
    }
    _stack[_len++] = item;
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
    return _len;
}

template<class Item> bool Stack<Item>::isBalance() const {
    if (_len < 2)
        return true;
    int sum_m = 0;
    int sum_x = 0, sum_y = 0, sum_z = 0;
    for (int i = _len - 2; i >= 0; --i) {
        sum_m += _stack[i-1].getM();
        sum_x += _stack[i-1].getX() * _stack[i-1].getM();
        sum_y += _stack[i-1].getY() * _stack[i-1].getM();
        if (!_stack[i].dotInBorders(sum_x/sum_m, sum_y/sum_m))
            return false;
    }
    return true;
}

template<class Item> Item* Stack<Item>::copyToArray(const int &max_len) const {
    Item* new_arr = new Item[_max_size];
    for (int i = 0; i < _len; ++i)
        new_arr[i] = _stack[i];
    return new_arr;
}

#endif
