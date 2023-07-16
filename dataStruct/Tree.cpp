#include<iostream>
using namespace std;


class Node{
    public:
        int data;
        Node *left;
        Node *right;
};

Node *CreateNode(int data){
    Node *newNode = new Node();
    newNode->left = newNode->right =nullptr;
    return newNode;
}
//Preorder traversing
void printTreePre(Node *root){
    if(root == nullptr)
        return;
    cout<< root->data <<endl;
    printTreePre(root->left);
    printTreePre(root->right);
}
//inorder traversing
void printTreeIn(Node *root){
    if(root == nullptr)
        return;    
    printTreeIn(root->left);
    cout<< root->data <<endl;
    printTreeIn(root->right);

}
//Postorder traversing
void printTreePost(Node *root){
    if(root == nullptr)
        return;    
    printTreePost(root->left);
    printTreePost(root->right);
    cout<< root->data <<endl;
}

int main(){
     //Level 0
     Node *root = CreateNode(1);
     //Level 1
     root->left = CreateNode(2);
     root->right = CreateNode(3);     
     //Level 2
     root->left->left = CreateNode(4);
     root->left->right = CreateNode(5);
     root->right->left = CreateNode(6);
     root->right->right =CreateNode(7);     
     //Level 3
     root->left->right->left = CreateNode(9);
     root->right->right->left = CreateNode(15);
     
     printTreePre(root);
    return 0;
}

