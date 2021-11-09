#include <fstream>
#include <iostream>
#include <variant>
#include <string>
#include <QTextStream>
#include "iterator.h"
#include "stack.h"
#include "item.h"


Stack::Stack() : Stack(DELAULT_LEN) {}

Stack::Stack(const int &base_len) {
    _len = 0;
    _stack = new ItemVariant[base_len];
    _stack = new ItemVariant[base_len];
    _max_size = base_len;
}

Stack::Stack(const Stack &resource_stack) {
    _len = _max_size = resource_stack.getLen();
    _stack = resource_stack._copyToArray(_len);
}

Stack::~Stack() {
    delete[] _stack;
}

void Stack::push(const ItemVariant &item) {
    if (_len == _max_size) {
        _max_size *= 2;
        ItemVariant* new_stack = _copyToArray(_max_size);
        delete[] _stack;
        _stack = new_stack;
    }
    _stack[_len++] = item;
}

ItemVariant Stack::pop() {
    if (_len <= 0)
        throw EMPTY_STACK_EXCPEPTION;
    return _stack[--_len];
}

void Stack::clear() {
    delete[] _stack;
    _stack = new ItemVariant[DELAULT_LEN];
    _max_size = DELAULT_LEN;
    _len = 0;
}

ItemVariant Stack::top() const {
    if (_len == 0)
        throw EMPTY_STACK_EXCPEPTION;
    return _stack[_len-1];
}

bool Stack::isEmpty() const {
    return _len == 0;
}

int Stack::getLen() const {
    return _len;
}

bool Stack::isBalance() const {
    if (_len < 2)
        return true;
    int sum_m = 0;
    int sum_x = 0, sum_y = 0;
    for (int i = _len - 2; i >= 0; --i) {
        sum_m += std::visit(CallGetM{}, _stack[i+1]);
        sum_x += std::visit(CallGetX{}, _stack[i+1]) *
            std::visit(CallGetM{}, _stack[i+1]);
        sum_y += std::visit(CallGetY{}, _stack[i+1]) *
            std::visit(CallGetM{}, _stack[i+1]);
        if (!std::visit(
            CallDotInBorders{
                (float) sum_x/sum_m, (float) sum_y/sum_m
            },
            _stack[i]
        ))
            return false;
    }
    return true;
}

ItemVariant* Stack::_copyToArray(const int &max_len) const {
    if (max_len < _len)
        throw SMALL_LEN;
    ItemVariant* new_arr = new ItemVariant[max_len];
    for (int i = 0; i < _len; ++i)
        new_arr[i] = _stack[i];
    return new_arr;
}

Iterat Stack::getIterator() const {
    return Iterat(_copyToArray(_len), _len);
}

void Stack::serialise(QTextStream &out) const {
    out << _len << "\n";
    for (int i = 0; i < _len; ++i)
        out << QString::fromStdString(visit(CallToString{}, _stack[i])) << "\n";
}

Stack::Stack(QTextStream &in) {
    in >> _len;
    _max_size = _len + 1;
    _stack = new ItemVariant[_max_size];
    for (int i = 0; i < _len; ++i) {
        QString code;
        in >> code;
        QString line = in.readLine(255);
        if (code == PLATE_CODE) {
            _stack[i] = Plate(line.toStdString());
        } else if (code == PAPER_CODE) {
            _stack[i] = Paper(line.toStdString());
        }
    }
}
