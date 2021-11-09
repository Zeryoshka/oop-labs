// for compiling you need to use flag -std=c++17 in gcc or clang
#include <variant>
#include <assert.h>
#include <iostream>

#include "paper.h"
#include "plate.h"
#include "iterator.h"
#include "stack.h"
#include "item.h"
using namespace std;

int main() {
    Stack stack;
    Plate pl1 = Plate();
    Plate pl2 = Plate(15, 2, 5, 5, 4);
    Plate pl3 = Plate(pl2);
    Paper pa1 = Paper();
    Paper pa2 = Paper(15, 25, 2, 5, 5, 4);
    Paper pa3 = Paper(pa2);
    stack.push(pl1);
    cout << pl1.toString() << std::endl;
    cout << stack.isBalance() << std::endl;
    cout << visit(CallToString{}, stack.top()) << std::endl;
    stack.push(pl1);
    cout << stack.isBalance() << std::endl;
    cout << visit(CallToString{}, stack.top()) << std::endl;
    stack.push(pl2);
    cout << stack.isBalance() << std::endl;
    cout << visit(CallToString{}, stack.top()) << std::endl;
    stack.push(pl3);
    // std::cout << stack.isBalance() << std::endl;
    // std::cout << stack.top().toString() << std::endl;
    // stack.push(pa2);
    // Paper pa =  *(&stack.pop());
    // Plate pl = *(&stack.pop());
    // std::cout << pa.toString() << std::endl;
    // std::cout << pl.toString() << std::endl;
}
