#include <iostream>
#include <algorithm> 

#include "dstree.h"
#include "dsarray.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int n, option1, option2, x, y; 
    char elem;
    vector<char> data, set1;
    DisjoinSet<char>* ds = nullptr;
        
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>elem;
        data.push_back(elem);
    }

    option1 = atoi(argv[1]);     
    option2 = atoi(argv[2]);   
    if(option1 == 1)
        ds = new DisjoinSetTree<char>(data);
    else
        ds = new DisjoinSetArray<char>(data);    
    
    ds->MakeSet();//MakeSet all elements
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>x>>y;
        ds->Union(x,y);
    }
    
    switch (option2)
    {
    case 1:        
        cout<<ds->sets()<<endl;        
        break;
    case 2:
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            cin>>elem>>x;
            ds->Add(elem, x);    
        }                
        cout<<ds->size()<<endl;
        cout<<ds->sets()<<endl;
        break;
    case 3:
        cin>>x>>y;        
        cout<<ds->isConnected(x, y)<<endl;        
    case 4:
        cin>>x;
        set1 = ds->getElementsSet(x);
        sort(set1.begin(), set1.end());
        for(auto it = set1.begin(); it != set1.end(); it++)
            cout<<*it<<endl;
    }

    return 0;
}
