#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
     int data;
     node *next;
};


int main(){
    node *head;
    node *one=nullptr;
    node *two=nullptr;
    node *three=nullptr;

    one = new node();
    two = new node();
    three = new node();

    one->data = 1;
    two->data = 2;
    three->data = 3;

    one->next = two;
    two->next =three;
    three->next = nullptr;
    node *four = new node();
    four->data = 4;
    one->next = four;
    four->next =two;
    head = one;
    while(head != nullptr){
        cout<<head->data <<" ";
        head = head->next;
    }
    four->data = 4;
    one->next = four;
    four->next =two;
     while(head != nullptr){
        cout<<head->data <<" " << head->next <<endl;
        head = head->next;
    }

}
