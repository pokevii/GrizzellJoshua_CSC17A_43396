#include <iostream>
using namespace std;

template <class T>
T maximum(T val1, T val2)
{
  if(val1 > val2){
    return val1;
  } else if(val1 < val2){
    return val2;
  } else {
    return 0;
  }
}

template <class T>
T minimum(T val1, T val2){
  if(val1 < val2){
    return val1;
  } else if(val1 > val2){
    return val2;
  } else {
    return 0;
  }
}

int main() {
  int i1, i2;
  float f1, f2;

  cout << "Input two integer values: ";
  cin >> i1 >> i2;
  cout << "Input two float values: ";
  cin >> f1 >> f2;

  cout << "Maximum int: " << maximum(i1, i2) << endl;
  cout << "Minimum int: " << minimum(i1, i2) << endl;
  cout << "Maximum float: " << maximum(f1, f2) << endl;
  cout << "Minimum float: " << minimum(f1, f2) << endl;
}
