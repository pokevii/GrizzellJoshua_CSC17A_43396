#include <cstdlib>
#include <iomanip>
#include <iostream>

#include "problem1.h"
#include "problem2.h"
#include "problem4.h"
#include "problem5.h"
#include "problem6.h"
#include "problem7.h"

using namespace std;

void clrscr();
void prnMenu();

int main(int argc, char** argv) {
  int iMenu;
  do{
    prnMenu();
    cin >> iMenu;
    cin.ignore();
    switch(iMenu){
        case 1: problem1();
        break;
        case 2: problem2();
        break;
        case 3: cout << "\nProblem 3 can be found as a seperate program.\n";
        break;
        case 4: problem4();
        break;
        case 5: problem5();
        break;
        case 6: problem6();
        break;
        case 7: problem7();
        break;
        default: cout << endl;
    }
  }while(iMenu < 8);

  return 0;
}

void clrscr(){
  cout << "\033[2J\033[1;1H";
}

void prnMenu(){
  cout << "     CSC17A Midterm" << endl; 
  cout << "_______________________" << endl;
  cout << "1: " << setw(20) << right << "Checking Account" << endl; 
  cout << "2: " << setw(20) << right << "Employee Gross Pay" << endl; 
  cout << "3: " << setw(20) << right << "Stats Function" << endl;
  cout << "4: " << setw(20) << right << "Octal Encryption" << endl;  
  cout << "5: " << setw(20) << right << "Factorials" << endl;  
  cout << "6: " << setw(20) << right << "Base Conversion" << endl;  
  cout << "7: " << setw(20) << right << "Prime Numbers" << endl;
  cout << "8+:" << setw(20) << right << "Exit Program" << endl;
}