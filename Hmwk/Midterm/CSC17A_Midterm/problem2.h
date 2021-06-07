#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

string engVal(int total);
string enDigit(int num, string str);

struct Employee{
  string name;
  int hours;
  float payRate;
};

void problem2(){
  int arrSize;

  cout << "Input the number of employees to determine the gross pay of: ";
  cin >> arrSize;
  cin.ignore();
  cout << endl;

  Employee employee[arrSize];

  for(int i = 0; i < arrSize; i++){
    float total;
    int dbleHrs;
    int trplHrs;

    cout << "Employee " << i+1 << endl;
    cout << "Input the employee's name: ";
    getline(cin, employee[i].name);
    cout << endl;
    
    do{
      cout << "Input " << employee[i].name << "'s hours worked: ";
      cin >> employee[i].hours;
      cout << endl;
    }while (employee[i].hours < 0);

    do{
      cout << "Input " << employee[i].name << "'s rate of pay: ";
      cin >> employee[i].payRate;
      cout << endl;
    }while (employee[i].payRate < 0);


    if(employee[i].hours <= 40){
      total = employee[i].hours * employee[i].payRate;
    } 
    else if (employee[i].hours > 40){
      dbleHrs = employee[i].hours - 40;
      total += 40 * employee[i].payRate;
      if(dbleHrs <= 10){
        total += dbleHrs * (employee[i].payRate * 2);
      } else {
        trplHrs = dbleHrs - 10;
        total += 10 * (employee[i].payRate * 2);
        total += trplHrs * (employee[i].payRate * 3);
      }
    }

    //cout << fixed << setprecision(2) << "Salary: $" << total;
    cout << "Home Depot" << endl;
    cout << "1055 W 21st St" << endl;
    cout << setw(15) << left << employee[i].name << left << "$" << total << endl;
    cout << engVal(total) << "dollars";
    cout << endl;
    cout << "THE HOME DEPOT, INC.\n\n";
  }
}

//I cheaped out and made this take an int because I didn't want to add the cents part. 
//So we're converting float to int, losing the cents.
string engVal(int total){
  string enTotal;
  enTotal += enDigit(((total / 1000) % 100), "thousand ");
  enTotal += enDigit(((total / 100) % 10), "hundred ");

  if(total % 100 && total > 100){
    enTotal += "and ";
  }

  enTotal += enDigit((total % 100), "");
  return enTotal; 
}

string enDigit(int num, string str){
  string ones[] = {"", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ", "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen "};
  string tens[] = {"", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};
  
  string eng = "";

  if (num > 19){
    eng += tens[num / 10] + ones[num % 10];
  } else {
    eng += ones[num];
  }

  //cout << "str = " << str << " | eng = " << eng << endl;
  if(num) {eng += str;}
  
  //cout << "Number " << num << " returning " << eng << endl;
  return eng;
}
