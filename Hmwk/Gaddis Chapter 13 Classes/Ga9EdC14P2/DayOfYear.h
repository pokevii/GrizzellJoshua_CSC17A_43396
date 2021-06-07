#include <iostream>
using namespace std;

class DayOfYear{
  private:
    int day;
    static int totalDy[];
    static string months[];
  public:
    DayOfYear(int d){
      day = d;
    }
    void print();
};