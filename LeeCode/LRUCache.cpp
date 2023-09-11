#include <iostream>
#include<unordered_map>

using namespace std;

class LRUCahse{
    public:
    class node{
        public:
           int key;
           int value;
           node *next;
           node *prev;
           node(int k, int v){
                key = k;
                value = v;             
            }
    };
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    int cap;
    unordered_map<int, node*> m;

   LRUCahse(int capacity){
       cap = capacity;
       head->next = tail;
       tail->prev = head;
    }

    void addnode(node *newnode){
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev =newnode;
    }
    void deletenode(node *delnode){
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    int get(int ky){
        if(m.find(ky) != m.end()){
            node *resnode = m[ky];
            int res = resnode->value;
            m.erase(ky);
            deletenode(resnode);
            addnode(resnode);
            m[ky] = head->next;
            return res;
        }
        return -1;
    }
    void put(int key, int value){
        if(m.find(key) != m.end()){
            node *existingnode = m[key];
            m.erase(key);
            deletenode(existingnode);
        }
        if(m.size() == cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        m[key] = head->next;
        
        }
};


int main(){
  LRUCahse *obj = new LRUCahse(2);

   return 0;
}