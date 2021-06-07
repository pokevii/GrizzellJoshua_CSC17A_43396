/* 
 * Couldn't get this one to pass the second two test cases.
 * I'm almost certain it has something to do with setting the for loop on line
 * 25 to loop until JUNE instead of setting it dynamically. Not sure how to fix.
 */

//System Libraries
#include <iostream>
using namespace std;

enum month {JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, 
            OCTOBER, NOVEMBER, DECEMBER};

struct Weather {
    float rain;
    float hiTemp, loTemp;
};

void getData(Weather w);

int main(int argc, char** argv) {
    Weather w[12];
    float tempSum, rainSum, highest = -10000, lowest = 10000;
    month m;
    
    for(m = JANUARY; m <= JUNE; m = static_cast<month>(m+1)){
        cout << "Enter the total rainfall for the month:\n";
        cin >> w[m].rain;
        cout << "Enter the high temp:\n";
        cin >> w[m].hiTemp;
        cout << "Enter the low temp:\n";
        cin >> w[m].loTemp;

        rainSum += w[m].rain;
        tempSum += w[m].hiTemp;
        tempSum += w[m].loTemp;
    }

    for(m = JANUARY; m <= JUNE; m = static_cast<month>(m+1)){
        if(w[m].hiTemp > highest){
            highest = w[m].hiTemp;
        }
        if(w[m].loTemp < lowest){
            lowest = w[m].loTemp;
        }
    }
    
    cout << "Average monthly rainfall:" << (rainSum / m) << endl;
    cout << "High Temp:" << highest << endl;
    cout << "Low Temp:" << lowest << endl;
    cout << "Average Temp:" << (tempSum / (m*2));
    
    return 0;
}

void getData(Weather w){

}