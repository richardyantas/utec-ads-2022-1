#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class Heap
{
public:
    enum Type {
        MAX_HEAP, MIN_HEAP
    };

private:
    T *elements;
    int capacity;
    int n;
    Type type;

public:
    Heap(T *elements, int n, Type type=MAX_HEAP) : elements(elements), n(n), type(type)
    {
        capacity = n;
        // Apply the heapify only to parent nodes
        for (int i = n / 2 - 1; i >= 0; i--) 
            heapify_down(i);
    }

    Heap(int capacity, Type type=MAX_HEAP) : capacity(capacity), type(type)
    {
        elements = new T[capacity];
        n = 0;
    }

    int size()
    {
        return n;
    }

    bool empty()
    {
        return n == 0;
    }

    void push(T value)
    {
        if (n == capacity)
            throw out_of_range("index is out of range (Heap overflow)");
        // insert the new element to the end
        int index = n++;
        elements[index] = value;
        heapify_up(index);
    }

    T pop()
    {
        if (n == 0)
            throw out_of_range("index is out of range (Heap underflow)");
        // replace the root of the heap with the last element
        T temp = elements[0];
        elements[0] = elements[--n];
        heapify_down(0);
        return temp;
    }

    T top()
    {
        if (n == 0)
            throw out_of_range("index is out of range (Heap underflow)");
        return elements[0];
    }

    vector<T> extractTheTopK(int k){
        // TODO
        throw ("Function not implemented"); 
    }

    static void sortAsc(T* arr, int n){
       // TODO
       throw ("Function not implemented"); 
    }

    static void sortDesc(T* arr, int n){
       // TODO
       throw ("Function not implemented"); 
    }

private:
    int Parent(int i)
    {
        return (i - 1) / 2;
    }

    int Left(int i)
    {
        return (2 * i + 1);
    }

    int Right(int i)
    {
        return (2 * i + 2);
    }

    void heapify_down(int i)
    {
       // TODO
       throw ("Function not implemented"); 
    }

    void heapify_up(int i)
    { 
        // TODO
       throw ("Function not implemented"); 
    }
};