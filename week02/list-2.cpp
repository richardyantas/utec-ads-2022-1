
#include <iostream>
using namespace std;

struct Node{
  public:
    int id;
    int data;
    Node* next;
    Node(int data, Node* next, int id){
		  this->data = data;
		  this->next = next;
      this->id = id;
    }
	void print(){
		cout << "address: " << this << " data: " << this->data << ", next:" << this->next << endl;
	}
};

struct List{
	public:
  Node **head_ref;
	Node *HEAD;
  Node *root;
	int count = 0;	
		List(){};	
		void addfront(int data){
			if(count == 0){
				HEAD = new Node(data, NULL, count);	
        root = HEAD;
			}
			else
				HEAD = new Node(data, HEAD, count);
			count++;
			HEAD->print();
		}
		int size(){
			return count;
		}

    void append(int data){      
      Node* new_node = new Node(data,NULL,++count);
      root->next = new_node;
      root = new_node;
    }
    

		void print(){      
			// Node *it;
			// for(it=HEAD; it!=NULL; it=it->next){ it++
			// 	cout << it->data << " ";
			// }
			// cout << endl;
		}	

    int Size(){
      return count;
    }

    
    void remove(int idx){
      // head_ref = &HEAD;
      // Node* temp = *head_ref;
      Node* temp = HEAD;
      for(; temp!=NULL; temp=temp->next){
        if(temp->id == idx && temp==HEAD){
          delete temp;
        }
        else if(temp->id == idx && temp==root){
          delete temp;
        }
        else if(temp->next->id == idx){        
          temp->next = temp->next->next
          (*aux)->next = it->next;                       
          delete it;
          break;
        }        
        it->id -= 1;
        aux = &it;
		  // }
    }
};

int main() {
  // 7 4 8 5
  List l;
  l.addfront(7);
  l.addfront(4);
  l.addfront(8);
  l.addfront(5);
  l.print();
  l.remove(1);
  l.print();
}