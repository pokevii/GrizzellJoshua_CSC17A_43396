#include <iostream>
#include "DayOfYear.h"
using namespace std;

int main() {
    int d;
    do{
        cout << "Input a day of the year (1-365): ";
        cin >> d;
    }while(d > 365 || d < 1);
    DayOfYear doy = DayOfYear(d);
    doy.print();
}