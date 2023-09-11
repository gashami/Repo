#include<iostream>
#include<list>
using namespace std;

class AbsractEmployee{
    //pure virtual function for absraction
    virtual void AskForPromation() = 0;
};
class Employee:AbsractEmployee{
    private:
        string Name;
        string Company;
        int Age;
        
    public:
        void setName(string name){
            Name = name;
        }
        string getName(){
            return Name;
        }
        void setCompany(string company){
            Company = company;
        }
        string getCompany(){
            return Company;
        }
        void setAge(int age){
            Age = age;
        }
        int getAge(){
            return Age;
        }       
       
        
        Employee(string name, string company, int age){
            Name = name;
            Company = company;
            Age = age;
        }
        void display(){
            cout<<"Name is :" <<getName() << endl;
            cout<<"Company is :  "<<getCompany() <<endl;
            cout<<"Age is : "<<getAge() <<endl;
        }
        void AskForPromation(){
            if(Age > 40)
              cout<<Name <<" Get Promotion"<<endl;
            else
              cout<<Name <<", Sorry No promation for you"<<endl;


        }
        virtual void work(){
            cout<<Name<<" is checking email, task backlog, performing task ..."<<endl;
        }
};
class Developer:public Employee{
    public:
       string FavProgLang;
       Developer(string name, string company, int age, string favProgLamg ):
       Employee(name, company, age){
        FavProgLang =favProgLamg;
       }
       void fixBug(){
        cout<<getName() <<" Fix error using "<<FavProgLang <<endl;
       }
       void work(){
            cout<<getName()<<" is writing " << FavProgLang <<" and tracking issue ..."<<endl;
        }
};
class Teacher:public Employee{
    public:
        string Subject;
        void PrepareLesson(){
            cout<< getName() <<" is preparing  " << Subject << " lesson" <<endl;
        }
       Teacher(string name, string company, int age, string subject):
        Employee(name, company, age){
        Subject = subject;
       }
       void work(){
            cout<<getName()<<" is preparing " <<Subject <<" and preparing exams ..."<<endl;
        }
};


class EquilateralTriangle{
    private:
         float s;
         float Circumfrance;
         float area;
    public:
        void setA(float length){
             s = length;
             Circumfrance = s*3;
             area = (1.43 * s * s)/4;
        }
        /*Freind class and friend function can access private and protected data*/
        friend void PrintResult(EquilateralTriangle);
        friend class Homework;

};
void PrintResult(EquilateralTriangle et){
    cout<<"Friend Function: \n\tCircumfrence = "<<et.Circumfrance <<endl;
    cout<<"\tArea = "<< et.area <<endl;
}
class Homework{
    public:
        void PrintResultArea(EquilateralTriangle et){
            cout<<"Friend class: \n \tCircumfrence = "<<et.Circumfrance <<endl;
            cout<<"\tArea = "<< et.area <<endl;
        }
};

//copy constractor 
class Rectangle{
    private:
        int Width;
        int Height;
    public:
        Rectangle(int width, int height){
            Width = width;
            Height =height;
        }
        //Rectangle(int w, int h):Width(w),Height(h){}

        Rectangle(Rectangle &obj){
            Width =obj.Height;
            Height =obj.Width;
        }
        double CalculateArea(){
            return Height * Width;
        }
};
//Copy constractor implimentation
void CopyConstractor(){
    Rectangle rec1(4, 5);
    Rectangle rec2 = rec1;
    cout<<"\nArea of rectangle using con: " <<rec2.CalculateArea() <<endl;

}
//Friend class and function
void firendClasFun(){
    //Frien function implimentation
    
    EquilateralTriangle et;
    et.setA(4);
    PrintResult(et);
   
   //Frient class implimentation
   
   EquilateralTriangle eqT;
   eqT.setA(15);
   Homework h;
   h.PrintResultArea(eqT);

}

//C++ Function oberloading
class FunOverload{
    
    public:
    int add(int a, int b){
        return a + b;        
    }
    double  add(double a, double b){
        return a + b;
    }
    string add(string a, string b){
        return a.append(b); // a + b;
    }
};

//C++ Operator Overloading
class YouTubleChanal{
    public:
        string Name;
        int SubscriberCount;

        YouTubleChanal(string name, int subscriberCount){
            Name = name;
            SubscriberCount = subscriberCount;
        }
        bool operator==(const YouTubleChanal &channel) const{
            return this->Name == channel.Name;
        }
};
class Complex{
    private:
        int real;
        int img;
    public:
        Complex(int r = 0, int i = 0):real(r), img(i){}
        void display(){
            cout << real <<"+" <<img <<"i" ;
            
        }
        friend Complex operator + (Complex &C1, Complex &C2);
        friend Complex operator - (Complex &C1, Complex &C2);
};
struct MyCollection{
    list<YouTubleChanal>myChannels;
    void operator+=(YouTubleChanal &channel){
        this->myChannels.push_back(channel);
    }
    void operator-=(YouTubleChanal &channel){
        this->myChannels.remove(channel);
    }
};
/*
void operator<<(ostream& COUT, YouTubleChanal& ytChanel){
    COUT<<"Operator overloading:\n\tName: "<<ytChanel.Name<<endl;
    COUT<<"\tSubscribers: "<<ytChanel.SubscriberCount<<endl;
}*/
ostream &operator<<(ostream & output, YouTubleChanal & ytChanel){
    output<<"Operator overloading:\n\tName: "<<ytChanel.Name<<endl;
    output<<"\tSubscribers: "<<ytChanel.SubscriberCount<<endl;
    return output;
}
ostream &operator<<(ostream &output, MyCollection &myCol){
    for(YouTubleChanal ytChannel : myCol.myChannels)
        output << ytChannel <<endl;
    return output;
}

// Operator Overloading implimentation

void operatorOverSimple(){
    YouTubleChanal yt1 = YouTubleChanal("CodeBeauty", 7500);    
    cout << yt1;
   
}

void operatorOver(){
    YouTubleChanal yt1 = YouTubleChanal("CodeBeauty", 7500);
    YouTubleChanal yt2 = YouTubleChanal("GeekForGeek", 8500);   
    cout<<yt1 <<yt2<<endl;
    operator<<(cout, yt2);
}

void overloadUnnaryAdd(){
    YouTubleChanal yt1 = YouTubleChanal("CodeBeauty", 7500);
    YouTubleChanal yt2 = YouTubleChanal("GeekForGeek", 8500);
    MyCollection myCollection;
    myCollection += yt1;
    myCollection += yt2; 
    cout<<myCollection;
    cout<<myCollection; 
    myCollection -= yt2;
    cout<<myCollection;

}


Complex operator + (Complex &C1, Complex &C2){
            Complex tmp;
            tmp.real = C1.real + C2.real;
            tmp.img = C1.img  +  C2.img;
            return tmp;
        } 
Complex operator - (Complex &C1, Complex &C2){
            Complex tmp;
            tmp.real = C1.real - C2.real;
            tmp.img = C1.img - C2.img;
            return tmp;
        } 
void funcOverload(){
    FunOverload fOverlad;
    cout<<"sum of int: "<<fOverlad.add(19, 30) <<endl;
    cout<<"sum of double: "<<fOverlad.add(19.88, 30.12) <<endl;
    cout<<"sum of string: "<<fOverlad.add("Brook"," Ashami") <<endl;

}

void addOverloading(){
    Complex C1(2, 4), C2(15, 16), C3;
    C1.display();
    cout<<" + ";
    C2.display();
    cout<< " = ";
    C3 = C1 + C2;
    C3.display();
    cout<<endl;
}
void SubOverloading(){
    Complex C1(2, 4), C2(15, 16), C3;
    C1.display();
    cout<<" - ";
    C2.display();
    cout<< " = ";
    C3 = C1 - C2;
    C3.display();
    cout<<endl;
}
int main(){
    
    Employee e1 = Employee("Brook", "Intel", 50);
    Employee e2 = Employee("Tersit", "Bank of America", 34);
    /*
    e1.AskForPromation();
    e2.AskForPromation();
    //e.Name = "Brook";
    //e.Company = "Intel";
    //e.Age = 50;
    e1.display();
    e2.display();

    Developer d =Developer("Robel", "Google", 15, "Python");
    d.fixBug();
    d.AskForPromation();
    d.work();

    Employee * emp = &d;
    emp->work();

    Teacher t = Teacher("Amy", "PPa", 5, "Mathematics");
    t.PrepareLesson();
    t.AskForPromation();
    t.work();
    Employee* empT = &t;
    empT->work();

    firendClasFun();
    operatorOver();
    //operatorOverSimple();
    overloadUnnaryAdd();
    funcOverload();
    
    //copy constractor
    CopyConstractor();
    */
    addOverloading();
    SubOverloading();

    return 0;
}
