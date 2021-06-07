#include "ProductionWorker.h"
#include <iomanip>

void ProductionWorker::crtEmp(string name, string date, int num){
  setENam(name);
  setHDat(date);
  setEID(num);
}

void ProductionWorker::prnEmp(){
  cout << "Employee Name: " << getENam() << endl;
  cout << "Date of Hire: " << getHDat() << endl;
  cout << "Employee ID: " << getEID() << endl;
  cout << "Shift: ";
  if(shift == 1){
    cout << "Day\n";
  } else if (shift == 2){
    cout << "Night\n";
  } else {
    cout << "Unknown\n";
  }
  cout << fixed << setprecision(2);
  cout << "Pay Rate: " << payRate << endl;
}