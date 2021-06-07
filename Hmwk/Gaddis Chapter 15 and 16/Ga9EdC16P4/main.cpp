#include <iostream>
using namespace std;

template <class T>
T abs(T num)
{
  if(num < 0){
    num *= -1;
  }

  return num;
}

int main() {
  signed int i;
  float f;
  double d;
  cout << "Conversion to absolute value.\n";
  cout << "Input an integer: ";
  cin >> i;
  cout << "Input a float: ";
  cin >> f;
  cout << "Input a double: ";
  cin  >> d;
  cout << "Absolute value of " << i << " = " << abs(i) << endl;
  cout << "Absolute value of " << f << " = " << abs(f) << endl;
  cout << "Absolute value of " << d << " = " << abs(d) << endl;
}
