
#include<iostream>
using namespace std;

class Node{
  public:
    int data;
    Node* next;
};

class CircularList{
  Node* head;
  public:
    CircularList();

    void CircularList::remove_matches(CircularList ref){
      Node *i1 = this->head;
      Node *i2 = ref.head;
      while(i1 != nullptr && i2 != nullptr){
        //    ^
        // l: 1 2 7 10 12   -  ref: 2 5 6 11
        if(i1->next->data == i2->data){        
          Node *temp = i1->next->next;
          delete i1->next;
          i1->next = temp;
        }
        else if(i1->next->data > i2->data){
          i2 = i2->next;
        }
        else{
          i1 = i1->next;
        }
      }

    }
};

int main()
{
  CircularList cl;
  cl.push_front(7);
  cl.push_front(1);
  CircularList ref;
  ref.push_front(2);
  ref.push_front(1);

  cl.remove_matches(ref);

  cl.print();

}