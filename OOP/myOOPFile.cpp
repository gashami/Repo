#include<iostream>
using namespace std;
/*
1. Friend function and class
*/
struct Rectangle
{
    int height;
    int width;
    Rectangle(int h, int w){
        height = h;
        width = w;
    }
    void recArea(){
        cout<<"Area of rectangle " << ( height * width) << endl;
    }
};


//inheritance
class Shape_Protected{
    protected:    
        int width;
         int height;
    public:
        void setWidth(int w){
          width = w;
        }
        void setHeight(int h){
            height = h;
        }
        /*
        int getWidth(){
            return width;
        }
        int getHeight(){
            return height;
        }*/
};
class Shape_Private{     
        int width;
         int height;
    public:
        void setWidth(int w){
          width = w;
        }
        void setHeight(int h){
            height = h;
        }
        int getWidth(){
            return width;
        }
        int getHeight(){
            return height;
        }
};
//Drived Class
class Drive_Rec1:public Shape_Private{
    public:
        int getArea(){            
            return (getHeight() * getWidth());
        }
};
class Drive_Rec2:public Shape_Protected{
    public:
        int getArea(){
            return (width * height);           
        }
    };

void inheritanceClass(){
     Drive_Rec1 rec1;
     rec1.setHeight(7);
     rec1.setWidth(5);

     cout<<"The total area using private data : " <<rec1.getArea() <<endl;
    
     Drive_Rec2 rec2;
     rec2.setHeight(17);
     rec2.setWidth(15);
     cout<<"The total area using protected data : " <<rec2.getArea() <<endl;
}
//Aggrigate class
class Address{
    public:
    string addressLine, city, state, zip;
    Address(string addressLine, string city, string state, string zip){
        this->addressLine = addressLine;
        this->city = city;
        this->state = state;
        this->zip = zip;
    }
};

class Employee{
    private:
        Address *address;
    public:
        int id;
        string name;
    Employee(int id, string name, Address *address){
        this->id = id;
        this->name = name;
        this->address = address;
    }
    void display(){
        cout << id <<" "<< name << " "<<address->addressLine <<" " <<address->city <<" "<<address->state << " "<<address->zip <<endl;
    }
};
void AggreigateClass(){
     Address a1 = Address("1324 S Winchester Blvd apt 121", "San Jose", "CA", "95128");
     Employee e1= Employee(101, "Brook Ashami", &a1);
     e1.display();
}
enum week {
     MONDAY,
     TUESDAY,
     WEDNESDAY,
     THURSDAY,
     FRIDAY,
     SATURDAY,
     SUNDAY
};
class Account{
    public:
         int accno;
         string name;
         static int count;
         Account(int accno, string name){
             this->accno = accno;
             this->name = name;
             count++;
       }
     void display(){
         cout<<accno <<" " <<name <<endl;
     }
};

int Account::count = 0;
void myClass(){
     Account a1 = Account(201, "Brook");
     Account a2 = Account(202, "Ashami");
     Account a3 = Account(203, "Demissew");

     a1.display();
     a2.display();
     a3.display();
     cout <<"Total Object are: " << Account::count <<endl;
}

/* Polymorphism
    1. Function overloading
    2. Operation overloading
    3. Function overridding
    4. Vertual function
*/
class Polymorphic{
    public:
        int sum(int a, int b){
            return a + b;
        }
        double sum(double a, double b){
            return a + b;
        }
        template<class T> T sum(T a, T b){
            T result;
            result = a + b;
            return result;
        }
};

void myPoly(){
    int i = 10, j = 20;
    double f = 12.5, g = 20.125;
    Polymorphic poly;
    cout<<"Addition of Int "<<poly.sum(i, j) << endl;
    cout<<"Addition of double "<<poly.sum(f, g)<<endl;
    cout<<"Addition of int using Template "<<poly.sum<int>(i,j) <<endl;
    cout<<"Addition of double using Template "<<poly.sum<double>(f, g)<<endl;

}
void myStruct(){
    Rectangle rec = Rectangle(4, 6);
    rec.recArea();
}
void myEnum(){
     week day;
     day = MONDAY;
     cout << "The five day after monday is : " <<day + 4 << endl;
}
int main(){
     myClass();
     myStruct();
     myEnum();
     inheritanceClass();
     AggreigateClass();
     myPoly();
   return 0;
}