#ifndef ITERATOR_H
#define ITERATOR_H
#define LAST_EXCEPTION

#include <string>
#include <variant>
#include "paper.h"
#include "plate.h"

typedef std::variant<Paper, Plate> ItemVariant;
class Iterat {
public:
    Iterat(ItemVariant *stack, const int &len);
    ~Iterat();
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
