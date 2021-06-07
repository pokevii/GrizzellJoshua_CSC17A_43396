
#include <iostream>
#include "DayOfYear.h"
using namespace std;

int DayOfYear::totalDy[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
int DayOfYear::dayInMn[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string DayOfYear::months[12] = {
  "January",
  "February",
  "March",
  "April",
  "May",
  "June",
  "July",
  "August",
  "September",
  "October",
  "November",
  "December"
};

void DayOfYear::print(){
  if(month != ""){
    cout << "This function does not work when using that constructor.\nInstead, try printDM().\n";
    return;
  }

  for(int i = 0; i <= 12; i++){
    if(i != 0){
      if(day >= totalDy[i-1] + 1 && day <= totalDy[i]){
        day -= totalDy[i-1];
        cout << months[i] << " " << day << endl;
      }
    } else if(i == 0){
      if(day > 0 && day <= 31){
        cout << months[i] << " " << day << endl;
      }
    }
  }
}

void DayOfYear::printDM(){
  int total = 0;

  if(day == -1){
    return;
  }

  for(int i = 0; i < 13; i++){
    total += dayInMn[i];
    if(month == months[i]){
      total -= dayInMn[i];
      total += day;
      cout << "Day of year: " << total << endl;
    }
  }
}

DayOfYear DayOfYear::operator ++ (int){
  DayOfYear temp(day, month);
  day++;
  return temp;
}

DayOfYear DayOfYear::operator -- (int){
  DayOfYear temp(day, month);
  day--;
  return temp;
}

DayOfYear DayOfYear::operator ++ (){
  DayOfYear temp(day, month);
  ++day;
  return temp;
}

DayOfYear DayOfYear::operator -- (){
  DayOfYear temp(day, month);
  --day;
  return temp;
}