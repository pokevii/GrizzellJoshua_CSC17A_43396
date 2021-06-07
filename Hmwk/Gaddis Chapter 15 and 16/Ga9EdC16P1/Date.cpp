#include <iostream>
#include "Date.h"
using namespace std;

const string Date::months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void Date::setMonth(int m){
  if(m < 13 && m > 0){
    month = m;
  } else {
    throw InvalidMonth();
  }
}

void Date::setDay(int d){
  if(d < 32 && d > 0){
    day = d;
  } else {
    throw InvalidDay();
  }
}
void Date::setYear(int y){
  year = y;
}
void Date::prnDate(){
  cout << month << "/" << day << "/" << year << endl;
  cout << months[month-1] << " " << day << ", " << year << endl;
  cout << day << " " << months[month-1] << " " << year << endl;
}