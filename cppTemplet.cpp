#include <iostream>
using namespace std;

template<typename T> T myMax(T x, T y){
    return(x > y) ? x : y;
}

template<typename T> class Array{
private:
    T* ptr;
    int size;
public:
    Array(T arr[], int s);
    void print();
};

template <typename T> Array<T>::Array(T arr[], int s){
    ptr = new T[s];
    size = s;
    for( int i = 0; i < size; i++)
        ptr[i] = arr[i];
    
}
template <typename T> void Array<T>::print(){
    for(int i = 0; i < size; i++)
        cout << "  " << *(ptr + i);
    cout << endl;
    
}

template <class T, class U> class A{
    T x;
    U y;
    public:
        A(){
            cout << "Constracot called " << endl;
        }
};
int main(){

    int arr[5] = {1, 2, 3, 4, 5};
    Array<int> a(arr, 5);

    a.print();
    
    cout<< myMax<int>(3, 7) << endl;
    cout<< myMax<float>(4.55, 7.99) << endl;
    cout<< myMax<double>(3.4444, 7.00) << endl;
    cout<< myMax<char>('g', 'e') << endl;

    cout<<"Hello World!"<<endl;

    A<char, char> c;
    A<int, double> b;
    

    return 0;
}