#include <iostream>
#include "NumDays.h"
using namespace std;

NumDays NumDays::operator ++ (int){
  NumDays temp(wrkHrs);
  wrkHrs++;
  wrkDays = float(wrkHrs) / 8.0f;
  return temp;
}
NumDays NumDays::operator ++ (){
  ++wrkHrs;
  wrkDays = float(wrkHrs) / 8.0f;
  return *this;
}
NumDays NumDays::operator -- (int){
  NumDays temp(wrkHrs);
  wrkHrs--;
  wrkDays = float(wrkHrs) / 8.0f;
  return temp;
}
NumDays NumDays::operator -- (){
  --wrkHrs;
  wrkDays = float(wrkHrs) / 8.0f;
  return *this;
}
NumDays NumDays::operator + (const NumDays &other){
  NumDays temp;
  temp.wrkHrs = wrkHrs + other.wrkHrs;
  temp.wrkDays = float(temp.wrkHrs) / 8.0f;
  return temp;
}
NumDays NumDays::operator - (const NumDays &other){
  NumDays temp;
  temp.wrkHrs = wrkHrs - other.wrkHrs;
  temp.wrkDays = float(temp.wrkHrs) / 8.0f;
  return temp;
}