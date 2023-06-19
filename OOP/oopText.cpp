/*
1. Class membeer function
2. Class access modifiers
3. constructor and distructor
4. copy constructor
5. Friend Function
6  Inline Function
7. This pointers
8. Pointers to C++ class
9. Static Members
*/

/* 
 1. Inheritance:
 2. Overloading
 3. Polymophism
 4. Abstraction
 5. Encapsulation
 6. Interface     
*/

/* C++ Advanced
    1. File and Stream
    2. Exception Handling
    3. Dynaamic Memory
    4. Namespace
    5. Templates
    6. Preprocessor
    7. Signal Handling void (*signal(int sig, void (*fun)(int)))(int);
    8. Multithreading
    9. 

*/
#include <iostream>
using namespace std;


#include "Header.h"

int main(){
    int i, j;
    i = 100;
    j = 30;
    int ij = 190;

    cout << "Value of __LINE__ : " << __LINE__ << endl;
    cout << "Value of __FILE__ : " << __FILE__ << endl;
    cout << "Value of __DATE__ : " << __DATE__ << endl;
    cout << "Value of __TIMe__ : " << __TIME__ << endl;


    #ifdef DEBUG
        cerr << "Trace: Inside main function " << endl;
    #endif

    #if 1
        cout << MKSTR(HELLO C++) << endl;
    #endif
    
    cout << CONCAT(i,j) <<endl;

    cout << "The minimum is " << MIN(i, j) << endl;

    #ifdef DEBUG
     cerr <<"Trace: Coming out of main function " << endl;
    #endif


    cout << "Sum of two number is :" << sumOfTwoNum(100, 77) << endl;

    return 0;
}