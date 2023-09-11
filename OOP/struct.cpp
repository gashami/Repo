#include <iostream>
using namespace std;
const int MAX = 10;

struct Employee
{
    char name[MAX];
    int age;
    float salary;
}emp;


void print_Emp(struct Employee *e_ptr){
    cout<<"print_Emp function ...\n\n" <<endl;
     
    cout << "Employee Name : " << e_ptr->name << endl;
    cout << "Employee Age : " << e_ptr->age << endl;
    cout << "Employee Salary : " << e_ptr->salary<< endl;
    cout<<"print_Emp function ..." <<endl;
    cout<<"print_Emp function ...\n\n" <<endl;

}


typedef struct structa_tag
{
   char        c;
   short int   s;
} structa_t;
  
// structure B
typedef struct structb_tag
{
   short int   s;
   char        c;
   int         i;
} structb_t;
  
// structure C
typedef struct structc_tag
{
   char        c;
   double      d;
   int         s;
} structc_t;
  
// structure D
typedef struct structd_tag
{
   double      d;
   int         s;
   char        c;
} structd_t;
  
int main(int argc, char* argv[]){
    struct Employee e1 = {"Brook", 50, 1000.45};
    struct Employee *e2;
    struct Employee e3 = {"Ashami", 40, 9900.45};
    e2 = &e3;

    struct Employee e4;
    struct Employee *e5 = &emp;

    cout << "Enter name of Emplyee E5 : ";
    cin.get(e5->name, 50);
    cout << "Enter age of Emplyee : ";
    cin >> e5->age;
    cout << "Enter salary of Employee : ";
    cin >> e5->salary;


    cout << "Enter name of Emplyee E4: ";
    cin.get(e4.name, 50);
    cout << "Enter age of Emplyee : ";
    cin >> e3.age;
    cout << "Enter salary of Employee : ";
    cin >> e4.salary;

    

    


    cout << "Employee Name : " << e1.name << endl;
    cout << "Employee Age : " << e1.age << endl;
    cout << "Employee Salary : " << e1.salary << endl;

    cout << "Employee Name : " << e2->name << endl;
    cout << "Employee Age : " << e2->age << endl;
    cout << "Employee Salary : " << e2->salary << endl;

    cout << "Employee Name : " << (*e2).name << endl;
    cout << "Employee Age : " << (*e2).age << endl;
    cout << "Employee Salary : " << (*e2).salary << endl;

    cout << "Employee Name : " << e4.name << endl;
    cout << "Employee Age : " << e4.age << endl;
    cout << "Employee Salary : " << e4.salary << endl;

    print_Emp(&e3);
     
    cout << "Employee Name : " << e5->name << endl;
    cout << "Employee Age : " << e5->age << endl;
    cout << "Employee Salary : " << e5->salary << endl;


    cout<<"Size of struc Employee is :"<<sizeof(Employee)<<endl;
    cout<<"Size of struc float is :"<<sizeof(float)<<endl;
    cout<<"Size of struc int* is :"<<sizeof(int*)<<endl;
    cout<<"Size of struc double* is :"<<sizeof(double*)<<endl;
    cout<<"Size of struc bool is :"<<sizeof(bool)<<endl;
    cout<<"Size of struc char is :"<<sizeof(char)<<endl;
    

cout << "sizeof(signed int) "<<sizeof(unsigned int) <<endl;
cout << "sizeof(unsigned int) "	<<sizeof(signed int)<<endl;
cout << "sizeof(int) "	<<	sizeof(int)<<endl;
cout << "sizeof(short) "	<<	sizeof(short)<<endl;
cout << "sizeof(long) "	<<	sizeof(long)<<endl;
cout << "sizeof(unsigned long) "	<<	sizeof(unsigned long)<<endl;
cout << "sizeof(unsigned long long) "<<	sizeof(unsigned long long)<<endl;
cout << "sizeof(long double) "	<<	sizeof(long double)<<endl;
cout << "sizeof(char) "		<<	sizeof(char)<<endl;
cout << "sizeof(signed char) "	<< sizeof(signed char)<<endl;
cout << "sizeof(unsigned char) "	<<	sizeof(unsigned char)<<endl;


cout << "sizeof(structa_t) = : " << sizeof(structa_t) << endl;
cout << "sizeof(structb_t) = : " << sizeof(structb_t) << endl;
cout << "sizeof(structc_t) = : " << sizeof(structc_t) << endl;
cout << "sizeof(structd_t) = : " << sizeof(structd_t) << endl;


}
