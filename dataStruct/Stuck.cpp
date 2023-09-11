#include <iostream>
#include<stack>

using namespace std;

void printStack(stack<int> Stack){
    while(!Stack.empty()){
        cout<<Stack.top()<<endl;
        Stack.pop();
    }
}

int main(){
    //empty, size, push, pop, top
    stack<int> stackElement;

    stackElement.push(1);
    stackElement.push(2);
    stackElement.push(3);
    stackElement.push(4);

    printStack(stackElement);
  /*
    if(stackElement.empty())
        cout<< "Stack is Empty" <<endl;
    else
        cout<< "Stack is not Empty" << endl;

    cout << "Size of stack is: " << stackElement.size() << endl;
   */
}