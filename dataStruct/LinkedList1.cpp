#include <iostream>
using namespace std;

//Creating a Single Linked list node using a user-define data tyoe 
struct Single_Node{
    int data;
    Single_Node *Next;
};

//Creating a Double Linked list node using a user-define data tyoe 
struct Double_Node{
    struct Double_Node *prev;
    int data;    
    struct Dobule_Node *next;
};
void initNode(struct Single_Node *head, int n){
    Single_Node *NewNode = new Single_Node;
    NewNode->data = n;
    NewNode->Next = NULL;

    Single_Node *cur = head;
    while(cur){
        if(cur->Next == NULL){
            cur->Next = NewNode;
            return;
        }
        cur = cur->Next;
    }
}

