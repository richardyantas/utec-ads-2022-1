#include<iostream>
using namespace std;


// class A{
//     protected:
//     int data=7;
//     public:
//     virtual void print() = 0;
// };


// class B : public A{
//     void print(){
//         cout << data << endl;
//     }
// };


template<typename T>
class A{
    protected:    
    public:
    //T data;
    T data = 5;
    virtual void print() = 0;
};

template<typename T>
class B : public A<T>{
    public:    
    void print(){
        cout << A<int>::data << endl;
    }
};

int main(){
  B<int> b;
  A<int> *a = &b;
  a->print();
  // B b;
  // A *a = &b;
  // a->print();  
  return 0;
}

