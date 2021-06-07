#include <iostream>
#include "DayOfYear.h"
using namespace std;
int DayOfYear::totalDy[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
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