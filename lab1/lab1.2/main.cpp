#include "paper.h"
#include <assert.h>

int main() {
    Paper default_paper;
    assert(
        default_paper.getHeight() == DEFAULT_HEIGHT &&
        default_paper.getLength() == DEFAULT_LENGTH &&
        default_paper.getWidth() == DEFAULT_WIDTH &&
        default_paper.getX() == DEFAULT_POSITION_X &&
        default_paper.getY() == DEFAULT_POSITION_Y
    );

    Paper paper(210, 297, 1, 0, 2);
    assert(
        paper.getHeight() == 1 &&
        paper.getLength() == 297 &&
        paper.getWidth() == 210 &&
        paper.getX() == 0 &&
        paper.getY() == 2
    );

    Paper new_paper(paper);
    assert(
        new_paper.getHeight() == paper.getHeight() &&
        new_paper.getLength() == paper.getLength() &&
        new_paper.getWidth() == paper.getWidth() &&
        new_paper.getX() == paper.getX() &&
        new_paper.getY() == paper.getY()
    );

    assert(default_paper.getX() == DEFAULT_POSITION_X);
    default_paper.setX(DEFAULT_POSITION_X + 1);
    assert(default_paper.getX() == DEFAULT_POSITION_X + 1);

    assert(default_paper.getY() == DEFAULT_POSITION_Y);
    default_paper.setY(DEFAULT_POSITION_Y + 1);
    assert(default_paper.getY() == DEFAULT_POSITION_Y + 1);

    return 0;
}
