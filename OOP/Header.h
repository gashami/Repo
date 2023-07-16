/*
 1. Macros
 2. Data type definition
 3. Function definition

*/

/*Macro
    1. Function-like
    2. conditional 
        #ifdef _WIN32L
            #include <windows.h>
        #else
            #include<sys/stat.h>
        #endif
        #ifndef NULL
            #define NULL
        #endif

       #if 1 or 0
           code
        #endif 
    */

#define DEBUG
#define MKSTR(x) #x
#define CONCAT(x, y) x ## y

#define MIN(a, b) (((a) < (b)) ? a : b)


int sumOfTwoNum(int a, int b){
    return (a + b);
}
