
#include<iostream>
using namespace std;

void point1(){
  int a = 5;
  int *p = &a;
  a = 4;
  cout << *p << endl;
  int b = 7;
  p = &b;
  cout << *p << endl;
}


class Point{  
  public:
    float x,y;
    Point(){
      this->x = 0;
      this->y = 0;
    };
    Point(int x, int y){
      this->x = x;
      this->y = y;
    }
};

int main(){
  int c_1;
  int c_2; 
  int *b = &c_1; // (*b)
  int **a = &b;
  b = &c_2;
  // p = new int[4], 
  // delete p;

  Point *p;
  // p->x = 
  // . ,->, this;
  return 0;
}

// HEAD = [3,d1] -> [5,d2] -> [2,d3] = ROOT 
// append: [3,d1] -> [5,d2] -> [2,d3] -> [new_value, new_adress] = ROOT
// addfront: [new_value, new_adress] -> [3,d1] -> [5,d2] -> [2,d3] 
// pop: [3,d1] -> [5,d2] -> ([2,d3] deleted !!) 

