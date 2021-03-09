#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int month, year, days;
    
    //Ask the user for a month.
    cout << "Enter a month (1-12): ";
    cin >> month;
    cout << endl;
    
    //Check how many days are in the month the user specified.
    //Maybe a switch case would have looked cleaner..
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 9 || month == 11){
        days = 31;
    }
    else if(month == 4 || month == 6 || month == 8 || month == 10 || month == 12) {
        days = 30;
    }
    else if(month == 2){
        days = 28; 
    }
    else{
        cout << "Invalid month.\n";
        return 1;
    }
    
    //Ask user for a year.
    cout << "Enter a year: ";
    cin >> year;
    cout << endl;
    

    //Leap year check
    if(month == 2){
        if(year % 100 == 0){
            if(year % 400 == 0){
                days++;
            }
        } else {
            if(year % 4 == 0)
            {
                days++;
            }
        }
    }
    
    //Print amount of days.
    cout << "Days: " << days << endl;
    return 0;
}

