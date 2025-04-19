#ifndef C_TEST_LIB
#define C_TEST_LIB

#include <time.h>
#include <assert.h>

typedef void (*CTestLibTestFunction)(void);

struct CTestLib_Test {
    
};

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
};

struct CTestLibTestReg
{
    // single linked list of regestry
    struct CTestLibList* testLists;
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

enum CTEST_LIB_TEST_STATUS {
    CTEST_LIB_STATUS_FAIL,
    CTEST_LIB_STATUS_PASS,
    CTEST_LIB_STATUS_UXPASS,
    CTEST_LIB_STATUS_SKIPP,
    CTEST_LIB_STATUS_ERROR,
    CTEST_LIB_STATUS_RETURN
};

enum CTEST_LIB_RESULT_STATUS {
    CTEST_LIB_RES_STATUS_ERROR,
    CTEST_LIB_RES_STATUS_RAN,
    CTEST_LIB_RES_STATUS_RUNNING,
};


#endif