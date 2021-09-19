
#ifndef STACK_H
#define STACK_H

#define DELAULT_LEN 4
#define EMPTY_STACK_EXCPEPTION "STACK IS EMPTY"

template<class Item> class Stack {
public:
    Stack(const int &base_len = DELAULT_LEN);
    Stack(const Stack<Item> &stack);
    ~Stack();

    void push(const Item &item);
    Item pop();

    Item top() const;
    bool isEmpty() const;
    int getLen() const;

    Item* copyToArray(const int &max_len = _len) const;
private:
    Item* _stack;
    int _max_size;
    int _len;
};

#endif