#include "paper.h"
#include "iterator.h"
#include "stack.h"
#include <assert.h>

void stacksIsEqual(const Stack<Paper> &s1, const Stack<Paper> &s2);
void papersIsEqual(const Paper &p1, const Paper &p2);
void paperTest();
void stackTest();

int main() {
    paperTest();
    stackTest();
    return 0;
}

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

    Stack<Paper> stack1;
    assert(stack1.getLen() == 0);
    for (int i = 0; i < 5; ++i)
        stack1.push(Paper());
    assert(stack1.getLen() == 5);

    Stack<Paper> stack2(stack1);
    stacksIsEqual(stack1, stack2);

    stack2.serialise("test.txt");
    Stack<Paper> stack3("test.txt");
    stacksIsEqual(stack2, stack3);

    stack2.pop();
    assert(stack2.getLen() == 4);
    stack2.clear();
    assert(stack2.isEmpty());
}

void papersIsEqual(const Paper &p1, const Paper &p2) {
    assert(
        p1.getHeight() == p2.getHeight() &&
        p1.getLength() == p2.getLength() &&
        p1.getWidth() == p2.getWidth() &&
        p1.getX() == p2.getX()&&
        p1.getY() == p2.getY()&&
        p1.getM() == p2.getM()
    );
}

void stacksIsEqual(const Stack<Paper> &s1, const Stack<Paper> &s2) {
    assert(s1.getLen() != s2.getLen());
    Iterator<Paper> iter1 = s1.iterator(), iter2 = s2.iterator();
    while (iter1.isLast()) {
        papersIsEqual(iter1.value(), iter2.value());
        iter1.next(), iter2.next();
    }

}