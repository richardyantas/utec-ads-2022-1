
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
	// void print(){
	// 	cout << "address: " << this << " data: " << this->data << ", next:" << this->next << endl;
	// }
};

struct iterator{
  public:
    Node* ptr;
    iterator(Node* p=NULL):ptr(p){}
    Node* operator->() const{
      
      return ptr;
    }
    iterator operator=(const iterator &it){      
      cout << (it.ptr)->data << endl;
      this->ptr = it.ptr;
      cout << "data: " << (this->ptr) << endl;     
      return iterator(NULL);
    }            
    iterator& operator++(){
      ptr=ptr->next;
      return *this;
    }        
    bool operator==(const iterator& t){
      return t.ptr == this->ptr;
    }    
    bool operator!=(const iterator &it){          
      bool isdif = (this -> ptr != it.ptr );          
      return isdif;
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
				HEAD = new Node(data, NULL, count);	
        ROOT = HEAD;
			}
			else
				HEAD = new Node(data, HEAD, count);
			count++;
			// HEAD->print();
		}
		int size(){
			return count;
		}

    void append(int data){      
      Node* new_node = new Node(data,NULL,++count);
      ROOT->next = new_node;
      ROOT = new_node;
    }
    
		void print(){      
			Node *it;
			for(it=HEAD; it!=NULL; it=it->next){
				cout << it->data << " ";
			}
			cout << endl;
		}	

    int Size(){
      return count;
    }

    
    void remove(int idx){
      Node* temp = HEAD;
      for(; temp!=NULL; temp=temp->next){
        if(temp==HEAD && temp->id == idx){
          HEAD = temp->next;
          delete temp;
          break;
        }        
        if(temp->next->id == idx){          
          if(temp->next == ROOT){
            ROOT = temp;
          }
          Node *aux = temp->next->next;
          delete temp->next;
          temp->next = aux;          
          break;
        }        
        temp->id -= 1;       
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
  l.append(40);
  l.print();
}