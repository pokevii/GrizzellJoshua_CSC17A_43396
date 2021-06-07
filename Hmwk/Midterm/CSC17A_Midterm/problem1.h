#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

/*          
*   PROBLEM 1
*/    

struct Customer{
  string name, address;
  int accNum;
  float balance; 
  float *checks, *deposit; 
};

void problem1(){
  Customer customer;
  int num, digits;
  int chkSize, depSize;
  float total = 0;
  //Get name
  cout << "Enter your name: ";
  getline(cin, customer.name);
  cout << endl;
  //Get address
  cout << "Enter your address: ";
  getline(cin, customer.address);
  cout << endl;

  //Input validation-- get acc num, must be 5 digits.
  do{
    digits = 0;
    cout << "Enter your account number (5 digits): ";
    cin >> customer.accNum;
    num = customer.accNum;
    while(num != 0){
      num /= 10;
      digits++;
    }
  }while(digits != 5);

  cout << "Enter your balance at the beginning of the month: ";
  cin >> customer.balance;
  cout << endl;
  //Get the size of the array.
  cout << "How many checks have you written this month?: ";
  cin >> chkSize;
  
  customer.checks = new float[chkSize];
  for(int i = 0; i < chkSize; i++){
    cout << "Enter check " << i+1 <<": ";
    cin >> customer.checks[i];
    cout << endl;
  } 

  cout << "How many deposits have you recieved this month?: ";
  cin >> depSize;
  
  customer.deposit = new float[depSize];
  for(int i = 0; i < depSize; i++){
    cout << "Enter deposit " << i+1 << ": ";
    cin >> customer.deposit[i];
    cout << endl;
  }

  cout << endl << "ACCOUNT DETAILS" << endl << "____________________" << endl;
  cout << setw(12) << left << "Name: " << customer.name << endl;
  cout << setw(12) << left << "Address: " << customer.address << endl;
  cout << setw(12) << left << "Acct #: " << customer.accNum << endl;
  cout << fixed << setprecision(2);
  cout << setw(12) << left << "Balance: " << "$" << customer.balance << endl;
  cout << setw(12) << left << "Checks: " << endl;
  for(int i = 0; i < chkSize; i++){
    cout << setw(13) << right << "-$" << customer.checks[i] << endl;
    total -= customer.checks[i];
  }
  cout << setw(12) << left << "Deposits: " << endl;
  for(int i = 0; i < depSize; i++){
    cout << setw(13) << right << "+$" << customer.deposit[i] << endl;
    total += customer.deposit[i];
  }
  total += customer.balance;
  if(total < 0){
    total -= 20;
    cout << "!! Funds overdrawn. Your account has been charged an overdraft fee of $20. !!" << endl;
  }
  cout << "____________________" << endl;
  cout << setw(12) << left << "TOTAL: " << "$" << total << endl;
}