#include "../src/main.h"
#include <assert.h>

void testGetTriangleType() {
    assert(getTriangleType(3, 4, 5) == 0);
}

void testcheck() {
    assert(check(2) == 0);
}

int main() {
    assert(addNumber(5, 2) == 7);
    testGetTriangleType();
    testcheck();
    return 0;
}
