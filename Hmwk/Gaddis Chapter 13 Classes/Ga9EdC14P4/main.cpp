#include <iostream>
#include <iomanip>
#include "NumDays.h"
using namespace std;

int main() {
  int hrs;
  int temp;
  cout << "Input work hours for numdys1: ";
  cin >> hrs;
  temp = hrs;
  NumDays numdys1 = NumDays(hrs);
  
  cout << "Input work hours for numdys2: ";
  cin >> hrs;
  NumDays numdys2 = NumDays(hrs);
  
  //cout << setprecision(2) << fixed;
  cout << "\nWORK DAYS: \n";
  cout << "Normal (no operator): " << numdys1.getDays() << endl;
  --numdys1;
  cout << "-- prefix operator: " << numdys1.getDays() << endl;
  numdys1.setHrs(temp);
  numdys1--;
  cout << "-- postfix operator: " << numdys1.getDays() << endl;
  numdys1.setHrs(temp);
  ++numdys1;
  cout << "++ prefix operator: " << numdys1.getDays() << endl;
  numdys1.setHrs(temp);
  numdys1++;
  cout << "++ postfix operator: " << numdys1.getDays() << endl;
  numdys1.setHrs(temp);

  NumDays numdys3 = NumDays();
  numdys3 = numdys1 + numdys2;
  cout << "+ operator (numdys1 + numdys2): " << numdys3.getDays() << endl;
  numdys3 = numdys1 - numdys2;
  cout << "- operator (numdys1 - numdys2): " << numdys3.getDays() << endl;
}
