#include <iostream>
using namespace std;

struct Nodo{
    public: 
        int valor;
        Nodo* p;
        Nodo (int data, Nodo* punt){
            this-> valor = data;
            this-> p = punt;
        }

};

struct lista{
    public:
        Nodo* HEAD;
        int contador = 0;
    void append(int numero){
        Nodo* pointer = Nodo(int valor);
        if (contador==0){
            HEAD = new Node(data, NULL);
        }


    }

};

int main(){
    return 0;
}