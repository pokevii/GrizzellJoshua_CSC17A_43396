#include <iostream>
#include "MilTime.h"
using namespace std;

void MilTime::setTime(){
  int mins = milHrs % 100;
  setHour((milHrs - mins) / 100);
  setMin(milHrs % 100);
  setSec(milSecs);
}

int MilTime::getSHr(){
  int hour;
  hour = getHour();
  return hour;
}

int MilTime::getMHr(){
  int hour;
  hour = milHrs;
  return hour;
}
