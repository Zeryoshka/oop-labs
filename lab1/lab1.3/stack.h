
#ifndef STACK_H
#define STACK_H

#include "iterator.h"
#include "paper.h"
#include "plate.h"
#include <fstream>
#include <variant>


#define DELAULT_LEN 4
#define EMPTY_STACK_EXCPEPTION "STACK IS EMPTY"
#define SMALL_LEN "max_len < _len"

typedef std::variant<Paper, Plate> ItemVariant;

class Stack {
public:
    Stack();
    Stack(const int &base_len);
    Stack(const Stack &stack);
    Stack(const std::string &path);
    ~Stack();

    void push(const ItemVariant &item);
    ItemVariant pop();
    void clear();
    ItemVariant top() const;
    bool isEmpty() const;
    int getLen() const;
    Iterator iterator() const;

    bool isBalance() const;
    void serialise(const std::string &path) const;

private:
    ItemVariant* _copyToArray(const int &max_len) const;
    ItemVariant* _stack;
    int _max_size;
    int _len;
};

struct CallGetM {
    int operator()(const Plate& plate) { return plate.getM(); }
    int operator()(const Paper& paper) { return paper.getM(); }
};

struct CallGetX {
    int operator()(const Plate& plate) { return plate.getX(); }
    int operator()(const Paper& paper) { return paper.getX(); }
};

struct CallGetY {
    int operator()(const Plate& plate) { return plate.getY(); }
    int operator()(const Paper& paper) { return paper.getY(); }
};

struct CallToString {
    std::string operator()(const Plate& plate) { return plate.toString(); }
    std::string operator()(const Paper& paper) { return paper.toString(); }
};

struct CallDotInBorders {
    CallDotInBorders(float x, float y) {
        _x = x;
        _y = y;
    }

    bool operator()(const Plate& plate) {
        return  plate.dotInBorders(_x, _y);
    }
    bool operator()(const Paper& paper) {
        return  paper.dotInBorders(_x, _y);
    }

private:
    float _x, _y;
};

#endif
