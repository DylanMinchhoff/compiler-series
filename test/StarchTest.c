#include "test_framework.h"
// run a test

// define an array with the tests inside

// add tests to regestry to run

int add(int a, int b) {return a + b;}

// create tests for add
CTestLib_Tests tests = {
    assert(add(2,2) == 4);

}
testCTestLib(testAdd);