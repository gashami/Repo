#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prevous;
        Node* next;
};

/*A. First Node
  1. Create a new node
        Node *node = new Node()
        node->data = 4
        node->next = nullptr
        node->prevoius= nullptr
  B.Second Node
  1. Create a new node
  2. node->data = 5
  3. node->next = nullptr and node->prevoius=tail;
  4.tail->next = node
  5. tail = node
*/
void createNode(Node* node){
    node = new Node();
    node->data = 4; 
    node->next = nullptr;
    node->prevous = nullptr;

}
void addBeforeNode(Node *Next_Node, int value){
    //check if the given node is null
    if(Next_Node == nullptr){
        cout <<"The given next node can not be null"<<endl;
        return;
    }
    //1. Allocat new nodw
    Node *New_Node = new Node();
    New_Node->data = value;
    New_Node->prevous = Next_Node->prevous;
    Next_Node->prevous = New_Node;
    New_Node->next = Next_Node;
    if(New_Node->prevous != nullptr){
        New_Node->prevous->next = New_Node;
    }else{
        head =New_Node;
    }
}
void addNode(Node *head, Node* tail, int value){
     
    Node *node = new Node();
    head = node;
    tail= node; 
    node = new Node();
    node->data = value;
    node->next = nullptr;
    node->prevous = tail;
    tail->next = node;
    tail = node;
}
void printForward(Node *head){
     Node *traverser = head;
     while(traverser != nullptr){
        cout<<traverser->data <<endl;
        traverser = traverser->next;
     }
}
void printBackward(Node *tail){
     Node *traverser =tail;
     while(traverser != nullptr){
        cout<<traverser->data <<endl;
        traverser = traverser->prevous;
     }
}

void insertNodeFront(Node *head, int value){
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    newNode->prevous = nullptr;

    if(head != nullptr){
        head->prevous =newNode;
   }
   head = newNode;
}
int main(){
   
    Node *head;
    Node *tail;
 
    Node *node = new Node();
    head = node;
    tail= node; 
    node = new Node();
    node->data = value;
    node->next = nullptr;
    node->prevous = tail;
    tail->next = node;
    tail = node;
    
    
    printForward(head);
    printBackward(tail);

    return 0;
}