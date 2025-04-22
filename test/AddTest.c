#include "CTestLib.h"
#include <assert.h>
#include <stdio.h>

// add tests to regestry to run

int add(int a, int b) {return a + b;}

// create tests for add

CTL_TEST(add, 2, 2, int, 4)
CTL_TEST(add, 3, 4, int, 7)
CTL_TEST(add, 3, 4, int, 9)

struct CTLTestSuite addTests = {
    .name = "Testing Addition",
    .testFunctions = {
        {.des="add 2+2", .cmp=test_add_int_4},
        {.des="add 3+4", .cmp=test_add_int_7},
        {.des="add 4+4", .cmp=test_add_int_9},
    },
    .numTests=3
};
ctl_suite_register(addTests)
