#include "CTestLib.h"
#include <assert.h>

// add tests to regestry to run

int add(int a, int b) {return a + b;}

// create tests for add
void testAdd() {
    assert(add(2,2) == 4);

}
register_AddTest(testAdd);