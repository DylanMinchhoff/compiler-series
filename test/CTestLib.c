// defines a simple testing framework for unit testing c files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <process.h>
#include "test_framework.h"

bool cmp_int(int a, int b) {
    return a == b;
}

// define way to open file read args and test args on a defined function
// FILE* openFile(char* f) {
//     return fopen(f, 'r');
// }

// modifies the current regestry to add all the information regarding tests
// add tests as linked list then get size of list when need to run tests, as tests are being ran, add error information to tests
void run_test_reg(struct CTestLibTestReg* reg) {


}


void toHTMLFILE() {
    return;
}


char* getTestResult(struct CTestLibTest* test) {
    char* res;
    if(test->result == CTEST_LIB_STATUS_ERROR) return (char*) malloc(sizeof("ERROR") + 1);
    if(test->result == CTEST_LIB_STATUS_PASS) return (char*) malloc(sizeof("PASS") + 1);
    if(test->result == CTEST_LIB_STATUS_UXPASS) return (char*) malloc(sizeof("UXPASS") + 1);
    if(test->result == CTEST_LIB_STATUS_FAIL) return (char*) malloc(sizeof("FAIL") + 1);
    if(test->result == CTEST_LIB_STATUS_RETURN) return (char*) malloc(sizeof("RETURN") + 1);
    if(test->result == CTEST_LIB_STATUS_SKIPP) return (char*) malloc(sizeof("SKIPP") + 1);

    return (char*) malloc(sizeof("CTest-Error") + 1);
}

void printOutTest(struct CTestLibTest* test) {
    char* res = getTestResult(test);
    printf("[%s] - Test:[%s%d] info: %fms \n", test->testName, test->testNum, res, test->elapsedTime);
    // free all resources
    free(res);
    free(test->testName);
    free(test);
}

void printOutTests() {

}

void testCtestLib(void* func, void* expected) {
    //
}


// this will function as a cmd for the testing framework
int main(int argc, char* argv) {
    

    return 0;
}


/**
 * order of file runner
 * 
 * link all the files and add all to regestry
 * run tests and modify regestry accordingly
 * printout results
 */