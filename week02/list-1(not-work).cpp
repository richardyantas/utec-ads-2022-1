
#include <iostream>
using namespace std;

struct Node{
  public:
    int id;
    int data;
    //Node* prev;
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

// 

struct List{
	public:
	Node *HEAD;
  Node *root;
	int count = 0;	
		List(){};	
		void append(int data){
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
		
		struct iterator{			
			public:
        Node* ptr;
				iterator(Node* p=NULL):ptr(p){}
        Node* operator->() const{
          return ptr;
        }
        // = Henry, christpher
        // iterator operator=(iterator *it){
        //   cout << "---------" << endl;    
        //   iterator ite = iterator(it ->ptr);          
        //   return ite;
        // }        

        iterator operator=(const iterator &it){
          //iterator ite(NULL);
          cout << (it.ptr)->data << endl;
          this->ptr = it.ptr;
          cout << "data: " << (this->ptr) << endl;
          // ite.ptr = it.ptr; // it.ptr = root          
          //return *this;
          return iterator(NULL);
        }        


        // iterator ++, anthony, bernardo
        iterator& operator++(){
           ptr=ptr->next;
           return *this;
        }        
        bool operator==(const iterator& t){
          return t.ptr == this->ptr;
        }

        // !=  (bool) , Enzo, clocwise
        bool operator!=(const iterator &it){          
          bool isdif = (this -> ptr != it.ptr );          
          return isdif;
        }

        ~iterator(){
          delete this->ptr;
        }

		};

  
		iterator begin(){
			return iterator(this->root);
		}

		iterator end(){
			return iterator(this->HEAD);
		}


    // void swap(){}

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
      // Node *it;      
      iterator it;
      Node **aux = NULL;
      
      it=this->begin();

      // for(; it!=this->end(); ++it ){
      //   if(it->id == idx){ // it->next->id == idx        
      //     if(it == this->begin()){ 
      //       this->begin() = it->next;
      //     }
      //     else if(it==this->end()){
      //       (*aux)->next = it->next;
      //     }
      //     else{            
      //       (*aux)->next = it->next;
      //       this->end() = *aux;
      //     }
      //     cout << "found" << endl;
      //     // delete it; // ERROR
      //   }
      // }      


      // for(it=HEAD, (aux)=&it; it!=NULL; it=it->next){        
			// 	cout << "h->" << (*aux)->data << "," << it->data << endl;
      //   if(it->id == idx){
      //     cout << "node with value " << it->data << " will be deleted" << endl;
      //     if(it == HEAD){
      //       HEAD = it->next;
      //       //it->next = HEAD;
			// 			cout << "*" << endl;
      //     }
      //     else if(it == root){
      //       (*aux)->next = it->next;
      //       root = *aux;
			// 			cout << "**" << endl;
      //     }
      //     else{
      //       cout << "o:" << endl;            
      //       // (*aux)->next = it
			// 			cout << (*aux)->data << ", will point to : " << it->data <<endl;
      //       (*aux)->next = it->next;             
      //     }
      //     delete it;
      //     break;
      //   }        
      //   it->id -= 1;
      //   aux = &it;
		  // }
    }
};

int main() {
  // 7 4 8 5
  List l;
  l.append(7);
  l.append(4);
  l.append(8);
  l.append(5);
  l.print();
 //l.remove(1);
 // l.print();
  int a;
  int* A = NULL;
  int* B = &a;
  B = A;
  return 0;
}