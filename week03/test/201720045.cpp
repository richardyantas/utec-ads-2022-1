#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data):data{data},next{nullptr}{};
};

class List{
    Node* HEAD;
    int nodes;
    public:
    List():HEAD{nullptr},nodes{0}{}
    void append(int data){
       Node* temp = new Node(data);
       nodes++;
       if(HEAD==nullptr){
           HEAD = temp;
           return;
       }
       Node* it = HEAD;
       while(it->next!=nullptr){
           it=it->next;
       }
       it->next = temp;
    }
    void addfront(int data){
       Node* temp = new Node(data);
       nodes++;
       temp->next = HEAD;
       HEAD = temp;
    }
    void pop(){
       Node* it = HEAD;
       nodes--;
       while(it->next->next!=nullptr){
           it=it->next;
       } 
       Node* it_2 = it->next;
       it->next = nullptr;
       delete it_2;
    }
    void print(){
       for(auto it=HEAD;it!=nullptr;it=it->next){
           cout<<it->data<<" -> ";
       }
       cout<<endl;
    }
};

int main(){
    List l;
    l.append(5);
    l.append(10);
    l.append(7);
    l.append(4);
    l.print(); // 5 10 7 4
    l.addfront(20);
    l.print(); // 20 5 10 7 4
    l.pop();
    l.print(); // 20 5 10 7
    return 0;
}