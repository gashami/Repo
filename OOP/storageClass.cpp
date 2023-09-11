#include<iostream>
using namespace std;

/*  1. Auto (Automatic) - Local Variable
    2, Register
    3. External - Global variable (default value is zero)
    4. Static - Local Variable (default value is zero)
    5. Mutable
    6. Thread_local  */
/*
void fun(){
    static int i = 0;
    int j = 0;
    i++;
    j++;

    cout<<"i = " <<i <<" j = " <<j <<endl;
}
int main(){
    fun();
    fun();
    fun();
    return 0;
}
*/

int fun(){
    static int num = 16;
    return num--;
}
/*
int main()
{
    static int i=5;
    if(--i){
        main();
        cout<< i<<" ";
    }
    return 0;
}
*/

int main(){
    for(fun(); fun(); fun())
        cout<<fun() << " ";
    return 0;
}