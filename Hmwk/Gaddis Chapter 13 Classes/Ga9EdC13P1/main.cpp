#include <iostream>
using namespace std;

const string months[12] = {"January", "February", "March", "April", "May", 
"June", "July", "August", "September", "October", "November", "December"};

class Date{
    private:
        int month, day, year;
     public:
        void setMonth(int m){
            month = m;
        }
        void setDay(int d){
            day = d;
        }
        void setYear(int y){
            year = y;
        }
        void prnDate(){
            cout << month << "/" << day << "/" << year << endl;
            cout << months[month-1] << " " << day << ", " << year << endl;
            cout << day << " " << months[month-1] << " " << year << endl;
        }
};

int main() {
    int month, day, year;
    Date date;
    cout << "Input the day: ";
    do{
        cin >> day;
    }while(day < 1 && day > 31);
    date.setDay(day);

    cout << "\nInput the month: ";
    do{
        cin >> month;
    }while(month < 1 && month > 12);
    date.setMonth(month);

    cout << "\nInput the year: ";
    cin >> year;
    date.setYear(year);
    cout << endl;

    date.prnDate();
}