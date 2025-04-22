// defines a simple testing framework for unit testing c files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#ifdef _WIN32
#include <process.h>
#endif

#include <unistd.h>

#ifdef __linux__
#include <sys/wait.h>
#endif

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
void runTest(struct CTestLibTestReg* reg, struct CTestLibTest* test, int timeout) {
    clock_t startTime, endTime;
    

    // #ifdef _WIN32
    //     //windows code
    //     pid_t pid = CreateProccess();

    // #elif __APPLE__
    //     //apple code

    // #elif __linux__
        // linux code
        test->result = CTEST_LIB_RES_STATUS_RAN;
        startTime = clock();

        pid_t pid = fork();
        

        if(pid < 0) {
            // failed fork
            test->result = CTEST_LIB_STATUS_ERROR;
            test->status = CTEST_LIB_RES_STATUS_ERROR;
        }
        else if(pid == 0) {
            test->cmp();
            exit(0);
        }
        else {
            int status;
            waitpid(pid, &status, 0);
            endTime = clock();


            if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
                test->status = CTEST_LIB_STATUS_PASS;
                reg->passed++;
            }
            else if (WIFSIGNALED(status)) {
                test->result = CTEST_LIB_RES_STATUS_CRASH;
                test->status = CTEST_LIB_STATUS_ERROR;
            }
            else {
                test->status = CTEST_LIB_STATUS_FAIL;
            }
        }
        


    // #else
    //     //throw an error operating system not supported
    //     exit(-1)
    // #endif

    double elapsedTime = ((double) (endTime - startTime)) / CLOCKS_PER_SEC;
    test->elapsedTime = elapsedTime;
}


// modifies the current regestry to add all the information regarding tests
// add tests as linked list then get size of list when need to run tests, as tests are being ran, add error information to tests
void runTestReg(struct CTestLibTestReg* reg, int timeout) {
    struct CTestLibTestNode* currNode = reg->testLists->head;
    int numTests = reg->testLists->size;

    // array of all tests
    struct CTestLibTest** tests = (struct CTestLibTest**) malloc(sizeof(struct CTestLibTest*) * numTests);
    int i = 0;

    while(currNode != NULL) {
        // init tests when transfer
        struct CTestLibTest* currTest = currNode->test;
        currTest->result = CTEST_LIB_RES_STATUS_RUNNING;
        currTest->testNum = i;

        tests[i] = currTest;

        runTest(reg, currTest, timeout);

    

        i++;
        struct CTestLibTestNode* tmpNode = currNode;
        currNode = currNode->next;

        //free linked list node
        free(tmpNode);
    }
    for(int j = 0; j < numTests; j++) {
        printOutTest(tests[j]);
    }
    printOutSummary(reg);
}

void printOutSummary(struct CTestLibTestReg* reg) {
    printf("===\tSummary for tests\t===\n");
    printf("== %d/%d tests passed ==\n", reg->passed, reg->totalTests);
}


void toHTMLFILE() {
    return;
}


const char* getTestResult(struct CTestLibTest* test) {
    if(test->result == CTEST_LIB_STATUS_ERROR) return "ERROR";
    if(test->result == CTEST_LIB_STATUS_PASS) return "PASS";
    if(test->result == CTEST_LIB_STATUS_UXPASS) return "UXPASS";
    if(test->result == CTEST_LIB_STATUS_FAIL) return "FAIL";
    if(test->result == CTEST_LIB_STATUS_RETURN) return "RETURN";
    if(test->result == CTEST_LIB_STATUS_SKIPP) return "SKIPP";

    return "CTest-Error";
}

void printOutTest(struct CTestLibTest* test) {
    const char* res = getTestResult(test);
    printf("[%s] - Test:[%s%d] info: %fms \n", test->testName, res, test->testNum, test->elapsedTime);
    // free all resources
    // free(test->testName);
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

    reg->testLists->size++;
    reg->totalTests++;
}

void addTestSuiteToRegistry(struct CTestLibTestReg* reg, struct CTLTestSuite* suite) {
    
    for(int i = 0; i < suite->numTests; i++) {
        struct CTestLibTest* test = (struct CTestLibTest*) malloc(sizeof(struct CTestLibTest));
        test->cmp = suite->testFunctions[i].cmp;
        test->testName = suite->testFunctions[i].des;
        addTestToRegestry(reg, test);
    }

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
    free(reg->tests);
    free(reg);
}

/**
 * order of file runner
 * 
 * link all the files and add all to regestry
 * run tests and modify regestry accordingly
 * printout results
 */

extern void gbl_stage_registration(struct CTestLibTestReg*);

#define MAX_STAGED_SUITES 1024

static struct CTLTestSuite* staged_suites[MAX_STAGED_SUITES];
static int staged_count = 0;
static struct CTestLibTestReg* live_registry = NULL;

void stage_suite(struct CTLTestSuite* suite) {
    if (live_registry) {
        // Registry already exists -> flush immediately
        addTestSuiteToRegistry(live_registry, suite);
    } else {
        // Stage until registry becomes available
        if (staged_count >= MAX_STAGED_SUITES) {
            //fprintf(stderr, "Too many staged test suites!\n");
            printf("Too many staged test suites!\n");
            exit(1);
        }
        staged_suites[staged_count++] = suite;
    }
}

void flush_suites(struct CTestLibTestReg* reg) {

    // Flush any previously staged suites
    for (int i = 0; i < staged_count; i++) {
        printf("adding suite\n");
        addTestSuiteToRegistry(reg, staged_suites[i]);
    }
    staged_count = 0; // Clear staging buffer
}


int main(int argc, char** argv) {
    int timeout = 5000;
    struct CTestLibTestReg* reg = init_CTestLib();
    printf("created test runner\n");
    flush_suites(reg);
    runTestReg(reg, timeout);

    // cmd for info

    del_CTestLib(reg);

    return 0;
}