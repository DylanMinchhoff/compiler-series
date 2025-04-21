#ifndef C_TEST_LIB
#define C_TEST_LIB

#include <time.h>
#include <assert.h>

#ifndef C_TEST_LIB_SKIP_TEST
#define C_TEST_LIB_SKIP_TEST //

#endif



typedef void (*CTestLibTestFunction)(void);

// struct CTestLib

/**
 * user-defined test for CTestLib
 * acts like a 'suite' of tests
 */
struct CTestLibTestSuite {
    char* name;
    CTestLibTestFunction function;
};

/**
 * CTestLibTest
 * This is the struct for the test result of a given test
 */
struct CTestLibTest
{
    enum CTEST_LIB_TEST_STATUS status;
    enum CTEST_LIB_RESULT_STATUS result;
    void* expected;
    void* actual;
    void* evaluationFunction;
    double elapsedTime;
    char* testName;
    int testNum;
    int testsPassed;
    int testsFailed;
};

/**
 * global registry for the CTestLib Suite
 */
struct CTestLibTestReg
{
    // single linked list of regestry
    struct CTestLibList* testLists; // will be deleted when a node is ran
    // this is a registry as an array - this is where the ran tests will be held when ran
    struct CTestLibList* tests;
};


struct CTestLibTestNode {
    struct CTestLibTest* test;
    struct CTestLibTestNode* next;
};

struct CTestLibList {
    int size;
    struct CTestLibTestNode* head;
    struct CTestLibTestNode* tail;
};

// final status of test after test is ran
enum CTEST_LIB_TEST_STATUS {
    CTEST_LIB_STATUS_FAIL,
    CTEST_LIB_STATUS_PASS,
    CTEST_LIB_STATUS_UXPASS,
    CTEST_LIB_STATUS_SKIPP,
    CTEST_LIB_STATUS_ERROR,
    CTEST_LIB_STATUS_RETURN
};

//expected status of test (optional param)
enum CTEST_LIB_TEST_EXPECTED {
    CTEST_LIB_STATUS_UXFAIL,
    CTEST_LIB_STATUS_SKIPP,
    CTEST_LIB_STATUS_ERROR,
};

enum CTEST_LIB_RESULT_STATUS {
    CTEST_LIB_RES_STATUS_ERROR,
    CTEST_LIB_RES_STATUS_RAN,
    CTEST_LIB_RES_STATUS_RUNNING,
};


#endif