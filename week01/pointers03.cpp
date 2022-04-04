#include<iostream>
using namespace std;

struct Node{
  public:
    int data;
	//int id=0;
	int id;
    Node* next;
    Node(int data, int id, Node* next){
		this->data = data;
		this->next = next;
		//this->id++;
		this->id = id;
    }
	void print(){
		cout << "data: " << this->data << ", next:" << this->next << endl;
	}
};
/*
	HEAD = root = (,NULL) -> () -> ()
	>> append(4)
	root = (,NULL) -> HEAD = (4, next) 
	Node node(7,NULL);
	int a = 7;
	// HEAD->next = NULL;
	// HEAD->data = 0;
	// HEAD->print();
*/
struct List{
	Node *HEAD;
	Node *root;
	int count = 0;
	int *p = NULL;
	public:
		List(){};	
		void append(int data){
			if(count == 0){
				HEAD = new Node(data, count, NULL);
				root = HEAD;
			}
			else
				HEAD = new Node(data, count, HEAD);
			count++;
			//HEAD->print();
		}
		int size(){
			return count;
		}
		void print(){
			Node *it;
			for(it=root; ; it=it->next){
				if(it == HEAD){
					cout << it->data << " ";
					break;
				}
				cout << it->data << " ";
			}
			cout << endl;
		}
		/*
			7 8 9 1 3
			idx = 3 -> e = 1
			i = 4  -> i = 0
			id = 4 -> id = 3
			/////// id = 3 -> id = 2 -> id = idx
			id = 2 -> id = 2
			id = 1 -> id = 1	 		
		*/
		void remove(int idx){
			Node* it;
			for(it=HEAD; it!=NULL; it=it->next){
				it->id -= 1;
				if (it->id == idx){					
					cout << it->data << " ";
					delete it;
					break;
				}
			}
			// delete 
			count = count-1;
		}
};

// ostream& operator<<(ostream& os, const  List& l){
// 	Node *it;
// 	for(it=HEAD; it!=NULL; it=it->next){
// 		os << it->data << " ";
// 	}
// 	os << endl;			
// 	return os;
// }

void test_node_link(){
	struct Node{
	public:
		int data;
		//int id=0;
		int id;
		Node* next;
		Node(int data, int id, Node* next){
			this->data = data;
			this->next = next;
			//this->id++;
			this->id = id;
		}
		void print(){
			cout << "data: " << this->data << ", next:" << this->next << endl;
		}
	};	
}

int main(){
	List l;
	l.append(9);
	l.append(4);
	// 9 4(HEAD) 

	// l.size(); // 2
	l.print(); // 9 4
	l.remove(1); // 4
	l.print(); // 9


	// cout << l << endl;

	return 0;
}





