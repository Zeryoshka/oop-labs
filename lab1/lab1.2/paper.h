#ifndef PAPER_H
#define PAPER_H

#define DEFAULT_WIDTH 10
#define DEFAULT_HEIGHT 1
#define DEFAULT_LENGTH 10
#define DEFAULT_POSITION_X 0
#define DEFAULT_POSITION_Y 0

class Paper {
public:
    Paper();
    Paper(
        const int &width, const int &length, const int &height,
        const int &x, const int &y
    );
    Paper(const Paper &paper);

    ~Paper();

    int getWidth() const;
    int getLength() const;
    int getHeight() const;
    int getX() const;
    void setX(const int &x);
    int getY() const;
    void setY(const int &y);

private:
    int _width;
    int _length;
    int _height;
    int _x;
    int _y;
};

#endif