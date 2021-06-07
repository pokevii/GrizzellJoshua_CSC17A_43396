#include <iostream>
using namespace std;
#include "ProductionWorker.h"

int main() {
  string name, date;
  int ID, shift;
  float pay;
  cout << "Enter employee information.\n";
  cout << "Employee name: ";
  getline(cin, name);
  cout << "Date of hire: ";
  getline(cin, date);
  cout << "Employee ID: ";
  cin >> ID;
  do{
    cout << "Shift (1 = Day, 2 = Night): ";
    cin >> shift;
  }while(shift > 2 || shift < 1);
  cout << "Pay Rate: ";
  cin >> pay;
  cout << "\n\n";

  ProductionWorker pw(shift, pay);
  pw.crtEmp(name, date, ID);
  pw.prnEmp();
  
}