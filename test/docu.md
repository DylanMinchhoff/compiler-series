# CTestLib

## Structure

/tests </br>
<p style="text-indent:30px;">CTestLib.h</p>
<p style="text-indent:30px;">ATest.c</p>
<p style="text-indent:30px;">BTest.c</p>
<p style="text-indent:30px;">CTestLib.c</p>
<p style="text-indent:30px;">CTestLibTests.c //auto-generated</p>
/
<p style="text-indent:30px;">test.py //creates the test-regestry and compiles it</p>


The framework acts like this:

In the test file define the function as the same name as the file.
The python file autocompiles a file where the test functions are injected into the global-test-registry. Then the test registry is run. 


In the testing framework:

- each injected test acts as a test suite
- run each test suite as fork() createprocess() (according to os)
- printout results


