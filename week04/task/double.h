#ifndef DOUBLE_H
#define DOUBLE_H

#include "iterator.h"

template <typename T>
class DoubleListIterator : public Iterator<T> {     
    public: 
        DoubleListIterator() : Iterator<T>() {};
        DoubleListIterator(Node<T> *current) : Iterator<T>(current) {};
        DoubleListIterator<T>& operator++();//++it
        DoubleListIterator<T>& operator--();//--it        
};

template <typename T>
class DoubleList : public List<T>{     
    public:
        typedef DoubleListIterator<T> iterator;
                 
    public:
        DoubleList() : List() { }

        /* new functions */             
        iterator begin() {
            // TODO
        }
             
        iterator end() {
            // TODO
        }      
             
        ~DoubleList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif