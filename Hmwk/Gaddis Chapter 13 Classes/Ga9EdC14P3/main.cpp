#include <iostream>
#include "DayOfYear.h"
using namespace std;

int main() {
  string m;
  int d;

  cout << "Input a month: ";
  cin >> m;

  cout << "Input a day: ";
  cin >> d;

  DayOfYear doy = DayOfYear(d, m);
  doy.printDM();
  cout << "++ postfix operator: ";
  doy++;
  doy.printDM();
  cout << "-- postfix operator: ";
  doy--;
  doy.printDM();
  cout << "-- prefix operator: ";
  --doy;
  doy.printDM();
  cout << "++ prefix operator: ";
  ++doy;
  doy.printDM();
}