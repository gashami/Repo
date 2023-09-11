#include<iostream>
#include<iterator>
#include<vector>
#include<list>
#include<map>
#include<stack>
#include<queue>

using namespace std;


//vector and for loop using range
void vectorForLoop(){
    vector<int> age = {2, 4, 15, 34, 50};
    //print the age
    for(int &n : age){
        cout<<"age is:" <<n<<endl;
    }
}
map<int, string> mapFun(){
    map<int, string> emp;
    emp[101] = "Brook";
    emp[102] = "Tersit";
    emp[103] = "Ashami";
    emp[106] = "Anna";
    emp[105] = "Amy";
    emp[104] = "Robel";

    emp.insert(pair<int,string>(107, "Demissew"));

    return emp;
}

void printMap(map<int, string> Emp){
    map<int, string>:: iterator itr;
    for(itr = Emp.begin(); itr!= Emp.end(); ++itr){
        cout<<(*itr).first << ": "<<(*itr).second <<endl;
    }
}
void reveseMap(map<int, string> Emp){
    map<int, string>::reverse_iterator itr;
    for(itr = Emp.rbegin(); itr != Emp.rend(); ++itr){
        cout<<(*itr).first <<": "<<(*itr).second <<endl;
    }
}
int main(){
   /*
    map<int, string> emp = mapFun();
    printMap(emp);
    reveseMap(emp);
    
    vector<int> ar = {1, 2, 3, 4, 5, 6};
    vector<int>::iterator ptr;
    list<int> li = {2, 4, 6, 8, 10};
    list<int>::iterator itr = li.begin();

    for(ptr = ar.begin(); ptr < ar.end(); ptr++){
        cout<<*ptr <<" " ;
    }
    for(int i = 0; i < ar.size(); i++){
        cout<<ar.at(i) << " ";
    }
    cout<<endl;
    li.insert(li.end(), 12);
    li.push_back(14);
    li.push_back(16);
    li.push_front(0);
    
    for(itr = li.begin(); itr != li.end(); itr++){
        //cout<<*itr << " ";
    }
    */
    vectorForLoop();
    return 0;
}