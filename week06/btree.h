#ifndef BTree_H
#define BTree_H
#include <iostream>
#include "node.h"

using namespace std;

template <typename TK>
class BTree
{
private:
    Node<TK> *root;   
    int M;//grado u orden del arbol

public:
    BTree(int _M) : M(_M), root(nullptr) {}

    string toString(string sep){//inorder    
        return toString(root, sep);
    }

    Node<TK>* search(TK key){
        return search(root, key);
    }

    void insert(TK key){
        if(root == nullptr){
            root = new Node<TK>(M);
            root->keys[0] = key;
            root->count = 1;
        }
        else { 
            if(root->count == M - 1){//si esta lleno
                //TODO: split en la raiz y actualizar el root
                Node<TK>* parent = new Node<TK>(M, false);
                parent->children[0] = root;
                split(parent, 0, key);//split del hijo de la posicion 0
                if(key < parent->keys[0])
                    insert(parent->children[0], key);
                else
                    insert(parent->children[1], key);
                root = parent;
            }
            else
                insert(root, key);
        }
    }


    void remove(TK key);
    int height();

    TK minKey();//minimo valor de la llave en el arbol
    TK maxKey();//maximo valor de la llave en el arbol
    ~BTree();//liberar memoria

private:
    string toString(Node<TK>*node, string sep){
        if(node === nullptr) return "";
        string result = "";
        int i = 0;
        while(i < node->count)
        {
            result += toString(node->children[i], sep);
            result += node->key[i] + sep;
            i++;
        }
        result += toString(node->children[i], sep);       
        return result;
    }

    Node<TK>* search(Node<TK>*node, TK key){
        int i = 0;
        //ubicar la posicion del hijo
        while(i < node->count && key > node->keys[i]) i++;

        if(node->keys[i] == key)  
            return node;
        else if(node->leaf) 
            return nullptr;
        else 
            //buscar recursivamente en dicho hijo
            return search(node->children[i], key);
    }

    void insert(Node<TK>*node,TK key){
        if(! node->leaf){//es nodo interno
            int i = 0;
            //ubicar la posicion del hijo
            while(i < node->count && key > node->keys[i]) i++;

            if(node->keys[i] == key) return;
            //verificar si el hijo ya tiene espacio
            if(node->children[i]->count == M - 1){
                split(node, i, key);
                if(key > node->keys[i]) i++;
            }
            insert(node->children[i], key);
        }
        else {            
            //mover las keys para dar espacio al input
            for(int i = node->count - 1;
                i>= 0 && key < node->keys[i];
                i--)
                node->keys[i+1] = node->keys[i];               
            node->keys[i] = key;
            node->count++;
        }
    }
};

#endif