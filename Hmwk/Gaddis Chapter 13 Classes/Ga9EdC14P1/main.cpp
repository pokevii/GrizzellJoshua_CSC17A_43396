#include <iostream>
#include <iomanip>
#include "Numbers.h"
using namespace std;

int main() {
  int i;
  do{
        cout << "Input a number to convert to english (0-9999): ";
        cin >> i;
  }while(i < 0 || i > 9999)

  Numbers numbers = Numbers(i);
  numbers.print();
}