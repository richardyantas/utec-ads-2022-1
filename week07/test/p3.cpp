


template <typename T>
class Iterator {
    private:
        NodeBT<T>* current;
        queue<NodeBT<T>*> q;
        // TODO: estructura de apoyo
    public:
        Iterator(): current(nullptr) {};
        Iterator(NodeBT<T> *root){
          this->current = root;
          if(current->left != nullptr){
            q.push(current->left);
          }
          if(current->right != nullptr){
            q.push(current->right)
          }
            //TODO: 
        }        
        Iterator<T>& operator++(){
          if(q.empty()) current = nullptr;
          else  {
            current = q.front();
            q.pop();
            if(current->left != nullptr){
              q.push(current->left);              
            }
            if(current->right != nullptr){
              q.push(current->right);
            }          
          }
          return *this;
            //TODO: operador de avance
        }
        T operator*()
        {
          return current->data;
          //TODO: operador de acceso
        }
};
