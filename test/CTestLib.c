// defines a simple testing framework for unit testing c files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <process.h>
#include "CTestLib.h"

//test runner steps
//init registry
//add tests to registry
//init output
//run tests
//print results

// define way to open file read args and test args on a defined function
// FILE* openFile(char* f) {
//     return fopen(f, 'r');
// }

/**
 * runs a test
 */
void runTest(struct CTestLibTest* test) {
    clock_t startTime, endTime;

    // #ifdef _WIN32
    //     //windows code
    //     pid_t pid = CreateProccess();

    // #elif __APPLE__
    //     //apple code

    // #elif __linux__
        // linux code
        pid_t pid = fork();
        


    // #else
    //     //throw an error operating system not supported
    //     exit(-1)
    // #endif

    double elapsedTime = ((double) (endTime - startTime)) / CLOCKS_PER_SEC;
    test->elapsedTime = elapsedTime;
}


// modifies the current regestry to add all the information regarding tests
// add tests as linked list then get size of list when need to run tests, as tests are being ran, add error information to tests
void runTestReg(struct CTestLibTestReg* reg) {


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


void addTestToRegestry(struct CTestLibTestReg* reg, struct CTestLibTest* test) {
    //extract the linked list of tests
    struct CTestLibList* regList = reg->testLists;

    //create new test node
    struct CTestLibTestNode* currTestNode = (struct CTestLibTestNode*) malloc(sizeof(struct CTestLibTestNode));
    currTestNode->next = regList->head;
    currTestNode->test = test;
    
    regList->head = currTestNode;
    // add a new test
    if(reg->testLists == NULL) { // no tests in curr list of tests
        regList->head = currTestNode;
    }

    reg->testLists->size = reg->testLists->size + 1;
}

void addTestSuiteToRegistry() {
    
}

struct CTestLibTestReg* init_CTestLib() {
    struct CTestLibTestReg* reg = (struct CTestLibTestReg*) malloc(sizeof(struct CTestLibTestReg*));
    reg->testLists = (struct CTestLibList*) malloc(sizeof(struct CTestLibList));
    reg->testLists->head = NULL;
    reg->testLists->tail = NULL;
    reg->testLists->size = 0;



    return reg;
}


void del_CTestLib(struct CTestLibTestReg* reg) {
    // free all resources

    free(reg);
}

/**
 * order of file runner
 * 
 * link all the files and add all to regestry
 * run tests and modify regestry accordingly
 * printout results
 */