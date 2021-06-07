#include <iostream>
using namespace std;
#include "MilTime.h"

int main() {
  int hr, sec;
  
  cout << "Input hours in military format (e.g. 1630): ";
  cin >> hr;

  cout << "Input seconds: ";
  cin >> sec;

  MilTime mt(hr, sec);
  cout << endl;
  cout << "Military Hour: " << mt.getMHr() << endl;
  cout << "Standard Hour: " << mt.getSHr() << endl;
  cout << "Standard Mins: " << mt.getMin() << endl;
  cout << "Standard Secs: " << mt.getSec() << endl;
}
