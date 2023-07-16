#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *Next;
};

//insert a new node infront of the list
void push(struct Node** head, int node_data){
    //1. Create new node
    struct Node* newNode = new Node;
    //2. assigned data to node
    newNode->data = node_data;

    /*3. set next to new node as head*/
    newNode->Next = (*head);

    /* 4. Move the head to print to new node*/
    (*head) = newNode;
}
//insert new node after given node
void insertAfter(struct Node * prev_node, int node_data){
    /* . Check if the given prev_node is NULL*/
    if(prev_node == NULL){
        cout<<"The given previous node is required, can not be NULL";
        return;
    }
    /* 2. Create and allocate new node*/
    struct Node* newNode = new Node;
    
    /* 3. assign data to the node*/
    newNode->data = node_data;

    /* 4. Make next of new node as next pf previous */
    newNode->Next = prev_node->Next;

    /* 5. Move the next end of prev_node as new_node*/
    prev_node->Next = newNode;

}
//iinsert new node at the end of the linked list
void append(struct Node** head, int node_data){
    /* 1. Create and allocate node*/
    struct Node *newNode = new Node;
    struct Node *last = (*head);

    /* 2. assign data to the node*/
    newNode->data = node_data;

    /* 3. set next pointer of new node to null as its the last node*/
    newNode->Next = NULL;

    /* 4. if the list is empty, new node becomes first node*/
    if(*head == NULL){
        *head = newNode;
        return;
    }

    /* 5. Else traverse till the last node*/
    while(last->Next != NULL){
        last = last->Next;
    }
    /* 6. change the next of last node*/
    last->Next = newNode;
    //return;
}
//Display linked list contents
void displayList(struct Node *node){
    /* Traverse the list to display each node*/
    while(node != NULL){
        cout << node->data <<"-->";
        node = node->Next;
    }
    if(node == NULL)
    cout<<"NULL" << endl;

}

Node* deleteFistNode(struct Node *head){
    if(head == NULL)
    return NULL;

    Node* tempNode = head;
    head = head->Next;
    delete tempNode;

    return head;
}
Node* removeLastNode(struct Node* head){
    if(head == NULL)
    return NULL;

    if(head->Next == NULL){
        delete head;
        return NULL;
    }
    Node* second_last = head;
    while(second_last->Next->Next != NULL)
    second_last = second_last->Next;

    delete(second_last->Next);

    second_last->Next = NULL;

    return head;
    
}

int main(){
    /*Empty List*/
    struct Node* head = NULL;

    /*
        append(&head, 10);
        push(&head, 20);
        push(&head, 30);
        append(&head, 40);
        insertAfter(head->Next, 50);
    */
    for(int i = 2; i < 20; i+=2){
        push(&head, i);
    }

    cout << "Final Linked List : "<< endl;
    displayList(head);

    head = deleteFistNode(head);

    cout << "after deleted first node Linked List : "<< endl;
    displayList(head);

    head = removeLastNode(head);

    cout << "after deleting the last node Linked List : "<< endl;
    displayList(head);

    return 0;
}
