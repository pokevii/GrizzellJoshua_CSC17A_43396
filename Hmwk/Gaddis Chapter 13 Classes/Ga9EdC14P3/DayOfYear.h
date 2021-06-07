#include <iostream>
using namespace std;

class DayOfYear{
  private:
    int day;
    string month;
    static int totalDy[];
    static string months[];
    static int dayInMn[];
  public:
    DayOfYear(){
      day = 0;
      month = "";
    }
    DayOfYear(int d){
      day = d;
      month = "";
    }
    DayOfYear(int d, string m){
      for(int i = 0; i < 13; i++){
        if(months[i] == m){
          if(d > dayInMn[i] || d < 0){
            cout << "Invalid date given.\n";
            d = -1;
          }
        }
      }

      day = d;
      month = m;
    }

    DayOfYear operator ++ (int);
    DayOfYear operator -- (int);
    DayOfYear operator ++ ();
    DayOfYear operator -- ();
    void print();
    void printDM();
};