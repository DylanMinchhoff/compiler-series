#ifndef C_TEST_LIB
#define C_TEST_LIB

struct CTestLibTest
{
    enum CTEST_LIB_TEST_STATUS status;
    enum CTEST_LIB_RESULT_STATUS result;

};

struct CTestLibTestReg
{
    // single linked list of regestry
    
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
    CTEST_LIB_STATUS_ERROR,
    CTEST_LIB_STATUS_RAN,
    CTEST_LIB_STATUS_RUNNING,
};


#endif