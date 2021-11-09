#ifndef ITEM_H
#define ITEM_H

#define DEFAULT_POSITION_X 0
#define DEFAULT_POSITION_Y 0
#define DEFAULT_M 10
#define DEFAULT_HEIGHT 1


#include <string>

class Item {
public:
    Item();
    Item(
        const int &x, const int &y, const int &m,
        const int &height
    );

    virtual bool dotInBorders(float x, float y) const {
        return false;
    }

    int getX() const;
    void setX(const int &x);
    int getY() const;
    void setY(const int &y);
    int getM() const;
    int getHeight() const;
    virtual std::string toString() const;

protected:
    int _x;
    int _y;
    int _m;
    int _height;
};

#endif
