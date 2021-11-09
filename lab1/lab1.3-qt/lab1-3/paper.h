#ifndef PAPER_H
#define PAPER_H

#define DEFAULT_WIDTH 10
#define DEFAULT_LENGTH 10
#define PAPER_CODE "Paper"

#include <string>
#include "item.h"

class Paper : public Item {
public:
    Paper();
    Paper(
        const int &length, const int &width, const int &height,
        const int &x, const int &y, const int &m
    );
    Paper(const Paper &paper);
    Paper(const std::string &string);

    ~Paper();

    virtual bool dotInBorders(float x, float y) const;

    int getWidth() const;
    int getLength() const;

    virtual std::string toString() const;

private:
    int _width;
    int _length;
};

#endif
