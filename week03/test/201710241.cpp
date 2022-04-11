//File Christopher Briceño (201710241)

// HEAD = [3,d1] -> [5,d2] -> [2,d3] 
// append: [3,d1] -> [5,d2] -> [2,d3] -> [new_value, new_adress]
// addfront: [new_value, new_adress] -> [3,d1] -> [5,d2] -> [2,d3] 
// pop: [3,d1] -> [5,d2] -> ([2,d3] deleted !!) 

#include <iostream>
using namespace std;

struct Node{
    public:
        int data;
        Node *next;
        int id;
        Node(int data, int id, Node *next){
            this->data = data;
            this->id = id;
            this->next = next;
        }        
};

struct List{
    Node *HEAD;
    Node *ROOT;
    int countList = 0;
    public:
        List(){};
        void append(int data){
            Node *temp;            
            temp = new Node(data, 0, NULL);
            cout << "-------" << endl;
            ROOT->next = temp;  // PRIMERO TIENE QUE ROOT APUNTAR A UN NODE PARA LUEGO APLICAR NEXT
            cout << "-------" << endl;
            // ROOT = temp;            
            // countList ++;
            // Node *it = HEAD;
            // for(int X = countList; X >= 0; X--){                
            //     it->id = X;
            //     it = it->next;
            // }
        }

        void addfront(int data){
            if (countList == 0){
                HEAD = new Node(data, countList, NULL);
                ROOT = HEAD;
            }
            else{
                HEAD = new Node(data, countList, HEAD);
            }
            countList ++;
        }

        void pop(){
            Node *temp;
            temp = HEAD->next;
            delete HEAD;
            HEAD = temp;
        }
};

ostream& operator<<(ostream& os, List& list){
    Node *it = list.HEAD;
    for(int X = list.countList; X <= 0; X--){
        os << it->data << " ";
        it=it->next;
    }
    return os;
}

int main(){
    List lst;
    lst.append(2);
    lst.append(4);
    lst.append(8);
    lst.append(16);
    lst.append(32);

    cout << lst << endl;

    lst.addfront(123);
    cout << lst << endl;
    lst.addfront(987);
    cout << lst << endl;

    lst.pop();
    cout << lst << endl;
    lst.pop();
    cout << lst << endl;
    

    return 0;
}





//===========================================
// #include <iostream>
// using namespace std;

// void point1(){
//     int a = 5;
//     int *p = &a;
//     a = 4;
//     cout << *p ;
//     int b = 7;
//     p = &b;
//     cout << *p << endl;
// }

// class Point{
//     public:
//         float x, y;
//         Point(){
//             //this->x = 0;
//             //this->y = 0;
//         };
//         Point(int x, int y){
//             this->x = x;
//             this->y = y;
//         }
// };

// int main(){
//     int c_1;
//     int c_2;
//     int *b = &c_1;
//     int **a = &b;

//     b = &c_2;

//     Point *p;
//     // p = new int;
//     // delete p;
//     // ->, this;

//     return 0;
// }