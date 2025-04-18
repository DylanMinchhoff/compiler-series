// defines a simple testing framework for unit testing c files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>

bool cmp_int(int a, int b) {
    return a == b;
}

// define way to open file read args and test args on a defined function
FILE* openFile(char* f) {
    return fopen(f, 'r');
}

// modifies the current regestry to add all the information regarding tests
// add tests as linked list then get size of list when need to run tests, as tests are being ran, add error information to tests
void run_test_reg(struct CTestLibTestReg* reg) {


}


void toHTMLFILE() {
    return;
}

void printOutTest(struct Test* test) {

}

void printOutTests() {

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