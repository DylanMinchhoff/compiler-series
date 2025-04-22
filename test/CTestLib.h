#ifndef C_TEST_LIB
#define C_TEST_LIB

#include <time.h>
#include <assert.h>

#ifndef __cplusplus
#include <stdbool.h>
#endif

// final status of test after test is ran
typedef enum {
    CTEST_LIB_STATUS_FAIL,
    CTEST_LIB_STATUS_PASS,
    CTEST_LIB_STATUS_UXPASS,
    CTEST_LIB_STATUS_SKIPP,
    CTEST_LIB_STATUS_ERROR,
    CTEST_LIB_STATUS_RETURN,
    CTEST_LIB_STATUS_TIMEOUT,
    CTEST_LIB_STATUS_CRASH,
} CTEST_LIB_TEST_STATUS;

//expected status of test (optional param)
typedef enum {
    CTEST_LIB_STATUS_EXFAIL,
    CTEST_LIB_STATUS_EXSKIPP,
    CTEST_LIB_STATUS_EXERROR,
} CTEST_LIB_TEST_EXPECTED;

// porgram status of a test (crash, error, return etc...)
typedef enum {
    CTEST_LIB_RES_STATUS_ERROR,
    CTEST_LIB_RES_STATUS_RAN,
    CTEST_LIB_RES_STATUS_RUNNING,
    CTEST_LIB_RES_STATUS_TIMEOUT,
    CTEST_LIB_RES_STATUS_CRASH,
} CTEST_LIB_RESULT_STATUS;

typedef void (*ctl_cmp_eval)(void);

struct CTLTest {
    const char* des;
    ctl_cmp_eval cmp;
};

/**
 * user-defined test for CTestLib
 * acts like a 'suite' of tests
 */
struct CTLTestSuite
{
    const char* name;
    int numTests;
    struct CTLTest testFunctions[];
};

/**
 * CTestLibTest
 * This is the struct for the test result of a given test
 */
struct CTestLibTest
{
    CTEST_LIB_TEST_STATUS status;
    CTEST_LIB_RESULT_STATUS result;
    void* expected;
    void* actual;
    ctl_cmp_eval cmp;
    double elapsedTime;
    const char* testName;
    int testNum;
    bool testsPassed;
    bool testsFailed;
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
    int totalTests;
    int passed;
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





// TODO: add custon compares to lib

#define ctestlib_cmp_int (bool cmp_int(int a, int b) {return a == b};)

#define ASSERT_EQ_FN(actual, expected)\
make_assert_eq_func(actual, expected, __FILE__, __LINE__, #actual, #expected)


struct CTestLibTestReg* init_CTestLib();

// Deletes and cleans up the test registry
void del_CTestLib(struct CTestLibTestReg* reg);

// Runs a single test with a given timeout
void runTest(struct CTestLibTestReg* reg, struct CTestLibTest* test, int timeout);

// Runs all tests registered in the test registry
void runTestReg(struct CTestLibTestReg* reg, int timeout);

// Converts test output to HTML format (placeholder)
void toHTMLFILE();

// Gets the result string for a given test
const char* getTestResult(struct CTestLibTest* test);

// Prints the result of a single test and frees associated memory
void printOutTest(struct CTestLibTest* test);

// Placeholder for printing all test results
void printOutTests();

// Dummy function for testing the CTestLib framework
void testCtestLib(void* func, void* expected);

// Adds a single test to the registry
void addTestToRegestry(struct CTestLibTestReg* reg, struct CTestLibTest* test);

// Adds an entire suite of tests to the registry (placeholder)
void addTestSuiteToRegistry(struct CTestLibTestReg* reg, struct CTLTestSuite* suite);

void stage_suite(struct CTLTestSuite* suite);

void printOutSummary(struct CTestLibTestReg* reg);

// Global test registration hook (to be implemented by the user)
extern void gbl_stage_registration(struct CTestLibTestReg* reg);


#define CTL_TEST(func, a, b, type, expected) \
    static void test_##func##_##type##_##expected(void) {\
        assert((func((a), (b)) == expected));}

#define CTL_ADD_SUITE(suite) \
    void register_suite(struct CTestLibTestReg* reg, struct STLTestSuite* suite) {\
        addTestSuiteToRegistry(reg, suite);\
    }\

// 
#ifdef _MSC_VER
#define CTL_CONSTRUCTOR \
    __pragma(section(".CRT$XCU",read)) \
    __declspec(allocate(".CRT$XCU")) static void
#else
#define CTL_CONSTRUCTOR \
    static void __attribute__((constructor))
#endif

// make auto-register function
#define ctl_suite_register(suite_name)\
    \
    static struct CTestLibTestReg* pending_registry = NULL;\
    \
    CTL_CONSTRUCTOR auto_register_suite(void) {\
        stage_suite(&suite_name);\
    }\
    \
    void gbl_stage_registration(struct CTestLibTestReg* reg) {\
        pending_registry = reg;\
    }\

#define ctl_add_suite(suite_address) static void 


#endif