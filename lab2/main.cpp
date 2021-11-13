#include <iostream>
#include <assert.h>
#include <exception>
#include "set.h"

int main() {

    // test 1
    Set<int> s1;
    assert(s1.count() == 0);

    // test 2
    assert(s1.count() == 0);
    s1 << 1;
    assert(s1[1]);
    assert(s1.count() == 1);
    s1 >> 1;
    assert(s1.count() == 0);
    assert(!s1[1]);

    // test 3
    assert(s1.count() == 0);
    s1 << 1 << 2;
    assert(s1.count() == 2);
    assert(s1[1] && s1[2]);
    s1 >> 1;
    assert(s1.count() == 1);
    assert(!s1[1]);
    try {
        s1 >> 1;
        assert(false);
    } catch(const std::invalid_argument& e) {};
    assert(s1.count() == 1);

    // test 4
    assert(s1.count() == 1);
    s1.clear();
    assert(s1.count() == 0);
    assert(s1 == Set<int>{});

    // test 5
    Set<int> s2;
    s2 << 1 << 2 << 3;
    assert(s2.count() == 3);
    assert( (s2 && Set<int>{}) == Set<int>{});

    // test 6
    Set<int> s3;
    s3 << 3 << 1 << 2;
    assert(s3 == s2);
    assert((s3 && s2) == s2);

    // test 7
    Set<int> s4{s2};
    assert(s4 == s3);
    s4 << 100;
    assert(s4 != s3);
    s4 >> 100;
    assert(s4 == s3);

    // test 8
    assert(s4.count() == 3);
    s4.serialise("test.serialise");
    Set<int> s5{"test.serialise"};
    assert(s4 == s5);


    std::cout << "Test passed" << std::endl;

    return 0;
}
