#include <iostream>
using namespace std;

class NumDays{
  private:
    float wrkDays;
    int wrkHrs;
  public:
    //Constructors
    NumDays(){
      wrkDays = 0;
      wrkHrs = 0;
    }
    NumDays(int h){
      wrkHrs = h;
      wrkDays = float(wrkHrs) / 8.0f;
    }
    //Accessors / Modifiers
    int getHrs() { return wrkHrs; }
    float getDays() { return wrkDays; }
    void setHrs(int h) { wrkHrs = h; }
    void setDays(float d) { wrkDays = d; }
    //Function Prototypes
    void HrToDay();
    //Operator Overloads
    NumDays operator ++ (int);
    NumDays operator ++ ();
    NumDays operator -- (int);
    NumDays operator -- ();
    NumDays operator + (const NumDays &other);
    NumDays operator - (const NumDays &other);
};