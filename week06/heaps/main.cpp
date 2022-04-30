#include <iostream>
#include "heap.h"

using namespace std;

int main(int argc, char const *argv[])
{
    try
    {
        int n, option;
        vector<int> topk;
        int *array;
        Heap<int>* heap = nullptr;

        cin >> n;
        array = new int[n];
        for (int i = 0; i < n; i++)
            cin >> array[i];
        option = atoi(argv[1]);        
        switch (option)
        {
        case 1://Test heapify_down
            heap = new Heap<int>(array, n);
            cout<<heap->top();
        case 2://Test heapify_up
            heap = new Heap<int>(n);
            for (int i = 0; i < n; i++)
                heap->push(array[i]);
            cout<<heap->top();  
        case 3://Test extract top-k min values
            heap = new Heap<int>(array, n, Heap<int>::MIN_HEAP);
            topk = heap->extractTheTopK(3);
            for (int i = 0; i < 3; i++)
                cout<<topk[i]<<endl;
        case 4://Test sort ascending
            Heap<int>::sortAsc(array, n);
            for (int i = 0; i < n; i++)
                cout << array[i] << endl;
                break;
        case 5://Test sort descending
            Heap<int>::sortDesc(array, n);
            for (int i = 0; i < n; i++)
                cout << array[i] << endl;
                break;
        default:
            throw ("option not found");
        }        
    }
    catch (const std::exception &ex)
    {
        cout << endl
             << ex.what();
    }
    return 0;
}
