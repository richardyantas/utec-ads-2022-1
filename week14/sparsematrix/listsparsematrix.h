#ifndef LIST_SPARSE_MATRIX_H
#define LIST_SPARSE_MATRIX_H
#include "sparsematrix.h"
#include <vector>
using namespace std;

template <typename T> struct Node {
  public:
    int posX;
    int posY;
    T data;
    Node<T> *next; // row
    Node<T> *down; // column
    Node<T>(){};

    // T data = 0
    Node<T>(int posX = 0, int posY = 0, T data = 0, Node<T> *next = nullptr,
            Node<T> *down = nullptr) {
        this->posX = posX;
        this->posY = posY;
        this->data = data;
        this->next = next;
        this->down = down;
    };
};

template <class T> class ListSparseMatrix : public SparseMatrix<T> {
  private:
    vector<Node<T> *> X;
    vector<Node<T> *> Y;

  public:
    ListSparseMatrix(){};
    ListSparseMatrix(unsigned rows, unsigned columns) {
        X.resize(rows);
        Y.resize(columns);
    };
    ~ListSparseMatrix() {
        X.clear();
        Y.clear();
    };

    bool set(unsigned posX, unsigned posY, T data) {
        Node<T> *p = new Node<T>(posX, posY, data);
        if (posY == 0) {
            // delete X[posX];
            X[posX] = p;
        }
        if (posX == 0) {
            // delete Y[posY];
            Y[posY] = p;
        }
        if (posX != 0 && posY != 0) {

            Node<T> *it = X[posX];
            while (it != nullptr) {
                it = it->next;
            }
            it->next = p;

            it = Y[posY];
            while (it != nullptr) {
                it = it->next;
            }
            it->next = p;
        }

        return true;
    };

    // O(1) + O(m)
    T get(unsigned posX, unsigned posY) {}

    bool remove(unsigned posX, unsigned posY) {}

    T operator()(unsigned posX, unsigned posY) {}

    ListSparseMatrix<T> &operator*(T scalar) {}
    ListSparseMatrix<T> &operator+(const ListSparseMatrix<T> &other) {}
    ListSparseMatrix<T> &operator-(const ListSparseMatrix<T> &other) {}
    ListSparseMatrix<T> &operator*(const ListSparseMatrix<T> &other) {}
    ListSparseMatrix<T> &transpose() {}

    void display(){
        // for (int i = 0; i < X.size(); i++) {
        //     Node<T> *it = X[i];
        //     while (it != nullptr) {
        //         it = it->next;
        //     }
        // }
    };
};

#endif
