#include <iostream>
#include<vector>
using namespace std;

/*Heapify is the process of creating a heap data structure from a binary try.it used to create Min_Heap or Max-Heaps
*/
void swap(int &a, int &b){
    int tmp = b;
    b = a;
    a = tmp;
}
void swap(int *a, int *b){
    int tmp = *b;
    *b = *a;
    *a = tmp;
}