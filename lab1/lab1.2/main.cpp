#include "paper.h"
#include "stack.h"
#include <assert.h>
#include <iostream>

void paperTest() {
    Paper default_paper;
    assert(
        default_paper.getHeight() == DEFAULT_HEIGHT &&
        default_paper.getLength() == DEFAULT_LENGTH &&
        default_paper.getWidth() == DEFAULT_WIDTH &&
        default_paper.getX() == DEFAULT_POSITION_X &&
        default_paper.getY() == DEFAULT_POSITION_Y &&
        default_paper.getM() == DEFAULT_M
    );

    Paper paper(297, 210, 1, 0, 0, 10);
    assert(
        paper.getWidth() == 210 &&
        paper.getLength() == 297 &&
        paper.getHeight() == 1 &&
        paper.getX() == 0 &&
        paper.getY() == 0 &&
        paper.getM() == 10
    );

    Paper new_paper(paper);
    assert(
        new_paper.getHeight() == paper.getHeight() &&
        new_paper.getLength() == paper.getLength() &&
        new_paper.getWidth() == paper.getWidth() &&
        new_paper.getX() == paper.getX() &&
        new_paper.getY() == paper.getY() &&
        new_paper.getM() == paper.getM()
    );

    assert(default_paper.getX() == DEFAULT_POSITION_X);
    default_paper.setX(DEFAULT_POSITION_X + 1);
    assert(default_paper.getX() == DEFAULT_POSITION_X + 1);

    assert(default_paper.getY() == DEFAULT_POSITION_Y);
    default_paper.setY(DEFAULT_POSITION_Y + 1);
    assert(default_paper.getY() == DEFAULT_POSITION_Y + 1);

    assert(paper.dotInBorders(15, 14));
    assert(!paper.dotInBorders(150, -10));
    assert(!paper.dotInBorders(400, 10));
    assert(!paper.dotInBorders(-10, -10));
}

void stackTest() {
    Stack<Paper> default_stack;
    assert(default_stack.getLen() == 0);
    default_stack.push(Paper());
    assert(
        default_stack.top().getHeight() == DEFAULT_HEIGHT &&
        default_stack.top().getWidth() == DEFAULT_WIDTH &&
        default_stack.top().getLength() == DEFAULT_LENGTH &&
        default_stack.top().getX() == DEFAULT_POSITION_X &&
        default_stack.top().getY() == DEFAULT_POSITION_Y &&
        default_stack.top().getM() == DEFAULT_M
    );
    for (int i = 0; i < 4; ++i)
        default_stack.push(Paper());
    assert(default_stack.getLen() == 5);

    Stack<Paper> stack(default_stack);
    assert(stack.getLen() == 5);

    Paper paper = stack.pop();
    assert(
        paper.getHeight() == DEFAULT_HEIGHT &&
        paper.getWidth() == DEFAULT_WIDTH &&
        paper.getLength() == DEFAULT_LENGTH &&
        paper.getX() == DEFAULT_POSITION_X &&
        paper.getY() == DEFAULT_POSITION_Y &&
        paper.getM() == DEFAULT_M
    );
    assert(stack.getLen() == 4);

    assert(stack.isBalance());
    default_stack.push(Paper(100, 100, 2, 300, 300, 1500));
    assert(!stack.isBalance());
}

int main() {
    paperTest();
    stackTest();
    return 0;
}