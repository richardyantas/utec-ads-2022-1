#include<iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node *next;
    Node(int data_in, Node *next_in)
    {
        this->data = data_in;
		this->next = next_in;
    }
};

struct List{
    Node *tail;
    Node *newdata;
    public:
        List(){};
        int count = 0;
        void append(int data){
            if (count != 0){
            newdata = new Node(data,NULL);
            tail->next = newdata;
            tail = newdata;}
            else{
                tail = new Node(data,NULL);
            }
        }
};

int main(){
	List l;
	l.append(9);
	l.append(4);

	return 0;
}




