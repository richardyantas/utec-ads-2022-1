
#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
struct Node{
  int data;
  Node* left;
  Node* right;
};


struct BTree{      
  public:
    Node* root=NULL;
    BTree(){}
    void insert(Node* n, int data){      
      if( n == NULL){        
        Node* n = new Node;        
        n->data = data;    
        this->root = n;    
      }
      else if(n->right==NULL && n->left==NULL){        
        n->data = data;
      }
      else{
        if(data > n->data){
          insert(n->right, data);
        }
        else{
          insert(n->left, data);
        }
      }
    }
};


bool isBalanced(Node* root){
  queue< pair<Node*, int> > q;
  vector< pair<Node*, int> > d;
  int cont = 0;
  q.push(make_pair(root,cont));
  while(!q.empty()){        
    Node* n = q.front().first;
    cont = q.front().second;
    q.pop();
    cont++;    
    cout << "------------" << endl;
    if (n->left == NULL && n->right == NULL){      
      d.push_back(make_pair(n, cont));
    }
    q.push(make_pair(n->left, cont));    
    q.push(make_pair(n->right, cont));
  }
  
  int last = d.size()-1;
  sort(d.begin(), d.end());
  if (d[last].second-d[0].second<=1){
    return true;
  }
  else {
    return false;
  }
  //isBalanced(root->left)+1
}

int main(){
  BTree* tree = new BTree();  
  tree->insert(tree->root, 7);  
  tree->insert(tree->root, 5);
  tree->insert(tree->root, 2);
  tree->insert(tree->root, 12);
  tree->insert(tree->root, 3);

  /*
    7
  5  12
2
 3

  */
  cout << isBalanced(tree->root) << endl;
  return 0;
}