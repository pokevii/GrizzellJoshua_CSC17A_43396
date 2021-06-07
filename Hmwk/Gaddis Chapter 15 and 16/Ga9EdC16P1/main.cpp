#include <iostream>
#include "Date.h"
using namespace std;

int main() {
  int month, day, year;
  Date date;
  cout << "Input the day: ";
  cin >> day;
  date.setDay(day);

  cout << "\nInput the month: ";
  cin >> month;
  date.setMonth(month);

  cout << "\nInput the year: ";
  cin >> year;
  date.setYear(year);
  cout << endl;

  date.prnDate();
}