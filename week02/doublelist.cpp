
#include <iostream>
using namespace std;

struct Node{
  public:
    int id;
    int data;
    Node* next;
    Node* prev;
    Node(int data, Node* next, Node* prev, int id){
		  this->data = data;
		  this->next = next;
      this->prev = prev;
      this->id = id;
    }
};

struct List{
	public:
  Node **head_ref;
	Node *HEAD;
  Node *ROOT;
	int count = 0;	
		List(){};	
		void addfront(int data){
			if(count == 0){
				HEAD = new Node(data, NULL, NULL, count);	
        ROOT = HEAD;
			}      
			else{
        Node *aux = new Node(data, NULL, NULL, count);
        HEAD->prev = aux;
        aux->next = HEAD;
        HEAD = aux;
      }
			count++;			
		}
		int size(){
			return count;
		}

    void append(int data){  
      // para un solo nodo agregar    
      Node* new_node = new Node(data, NULL, ROOT, ++count);
      ROOT->next = new_node;
      ROOT = new_node;
    }
    
		void print(){      
			Node *it;
			for(it=HEAD; it!=NULL; it=it->next){
				cout << it->data << " ";
			}
      cout << endl;
      // for(it=ROOT; it!=NULL; it=it->prev){
			// 	cout << it->data << " ";
			// }
			cout << endl;
		}	

    int Size(){
      return count;
    }

    
    void remove(int idx){
      Node* temp = HEAD;
      for(; temp!=NULL; temp=temp->next){
        if(temp->id==idx){          
          Node *a = temp->prev,*b=temp->next;          
          if(temp == HEAD){
            HEAD = b;               
          }
          else if(temp == ROOT){
            ROOT = a;
          }
          else {
            a->next = b;
            b->prev = a;
          }

          delete temp;
          break;
        }        
      }		  
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
  
  l.remove(3);
  l.addfront(1);
  l.addfront(100);
  l.print();

  // l.append(40);
  // l.print();
}