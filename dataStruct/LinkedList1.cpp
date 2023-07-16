#include <iostream>
using namespace std;
/*
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
class Node{
    public: 
        int data;
    Node* Next;
};
void Print_LinkedList(Node * head){
    head = new Node();
    cout<<"\nPrinting new list ..."<<endl;
    while(head != NULL){
        cout<<head->data <<" "<<endl;
        head->Next
    }
}
void initNode(struct Single_Node *head, int n){
    //Allocate memory dynamically

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
}*/
struct node{
    int data;
    node *next;
};

class linked_List{
    private:
       node *head, *tail;
    public:
    linked_List(){
        head = NULL;
        tail = NULL;
    }
    void add_node(int n){
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;
        if(head == NULL){
            head = tmp;
            tail = tmp;
        }else{
            tail->next = tmp;
            tail = tail->next;
        }
    }
    node *gethead(){
        return head;
    }
    void printList(node * tmp){
        tmp = head;
        while(tmp != NULL){
            cout << tmp->data <<endl;
            tmp = tmp->next;
        }
    }
    static void display(node *head){ 
       // cout<<"\nPrinting new list ..."<<endl;
        if(head == NULL){
             cout <<"NULL"<<endl;
        }else{
            cout<<head->data <<" "<<endl;
            display(head->next);
       }
    }
    static void concatenate(node *a, node *b){
        if(a != NULL && b != NULL){
            if(a->next == NULL){
                a->next =b;
            }else{
                concatenate(a->next, b);
            }
        }else{
            cout<< "Either a or b is null\n";
        }
    }
    
    void InsertFront(int value){
        node *newNode = new node;
        newNode -> data = value;
        newNode -> next = head;
        head = newNode;

    }
    void InsertAfter(node *a, int value){
        node* p = new node;
        p->data = value;

        p->next = a->next;
        a->next = p;
    }

    void del (node *before_del){
        node *tmp;
        tmp = before_del->next;
        before_del->next = tmp->next;
        cout <<"Deleted data is: " << tmp->data <<endl;
        delete tmp;
    }
    void deletLinkedList(node *allNode){
        node *tmpNode;
        while(allNode->next == NULL){
            tmpNode = allNode;
            allNode = tmpNode->next;
            delete tmpNode;
        }
    }
};


int main(){
    linked_List a;
    a.add_node(5);
    a.add_node(23);
    a.InsertFront(10);
    a.add_node(100);
    a.add_node(111);
    a.InsertAfter(a.gethead()->next->next->next, 150);
    a.del(a.gethead()->next);
    linked_List b;
    b.add_node(3);
    b.add_node(20);

   linked_List::concatenate(a.gethead(), b.gethead());
   linked_List::display(a.gethead());
   
   a.deletLinkedList(a.gethead());
   linked_List::display(a.gethead());
    return 0;
}