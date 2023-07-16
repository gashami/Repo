
/*Cpp code to demonstrate using Standard Templet Library (STL). 
   Methods are 1. push() 2.pop() 3.empty() 4.front() 5.back() 6.size() */
#include <iostream>
#include<queue>
using namespace std;

void printQueue(queue<int> queue){
    while(!queue.empty()){
        cout<<queue.front() <<endl;
        queue.pop();
    }
    cout<<endl;

}

int main(){
    //Push, pop, empty, back and front function
     queue<int> myQueue;
     myQueue.push(1);
     myQueue.push(2);
     myQueue.push(3);
     myQueue.push(21);
     myQueue.push(22);
     myQueue.push(23);
     cout<<"Size is: "<<myQueue.size() <<endl;
     cout<<"First element is: "<<myQueue.front() <<endl;
     cout <<"Last element is :"<<myQueue.back() <<endl;

     cout<<"\nMy queue list is: "<<endl;
     printQueue(myQueue);

    return 0;
}