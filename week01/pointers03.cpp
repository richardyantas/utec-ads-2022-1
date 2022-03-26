 #include<iostream>
using namespace std;

struct Node{
  public:
    int data;
    Node* next;
    Node(int data, Node* next){
		this->data = data;
		this->next = next;
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
	int count = 0;
	public:
		List(){};	
		void append(int data){
			if(count == 0){
				HEAD = new Node(data, NULL);				
			}
			else
				HEAD = new Node(data, HEAD);
			count++;
			HEAD->print();
		}
		int size(){
			return count;
		}
		void print(){
			Node *it;
			for(it=HEAD; it!=NULL; it=it->next){
				cout << it->data << " ";
			}
			cout << endl;
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


int main(){
	List l;
	l.append(9);
	l.append(4);
	// l.size();
	// l.print();
	cout << l << endl;

	return 0;
}





