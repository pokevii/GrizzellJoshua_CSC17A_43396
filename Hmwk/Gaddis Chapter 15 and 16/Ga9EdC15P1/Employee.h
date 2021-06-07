#include <iostream>
using namespace std;

class Employee{
  private:
    string empName;
    string hireDte;
    int empID;
  public:
    Employee(string name, string date, int num){
      empName = name;
      hireDte = date;
      empID = num;
    }
    Employee(){
      empName = "";
      hireDte = "" ;
      empID = -1;
    }
    string getENam() { return empName; }
    string getHDat() { return hireDte; }
    int getEID() { return empID; }
    void setENam(string name) { empName = name; }
    void setHDat(string date) { hireDte = date; }
    void setEID(int num) { empID = num; }

};