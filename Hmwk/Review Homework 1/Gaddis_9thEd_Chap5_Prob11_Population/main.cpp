#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int days;
    float popInc, popTotal, percent;
    
    //Get starting population from user
    cout << "How many organisms would you like to start with?: ";
    cin >> popTotal;
    cout << endl;
    
    //Terminate program if starting population is less than 2
    if(popTotal < 2){
        cout << "Starting population too low.";
        return 1;
    }
    
    //Get daily population increase and assign popInc a value
    cout << "Enter the daily population increase as a percentage: ";
    cin >> percent;
    cout << endl;
    popInc = 1 + (percent / 100);
    cout << popInc;
    
    //Terminate program if percent is negative.
    if(percent < 0){
        cout << "Population increase cannot be negative.";
        return 2;
    }

    //Get the number of days 
    cout << "Enter the number of days that the population will increase: ";
    cin >> days;
    cout << endl;
    
    //Terminate program if days is less than 1.
    if(days < 1){
        cout << "Days cannot be less than 1.";
        return 3;
    }
    
    cout << fixed;
    for(int i = 0; i < days; i++){
        popTotal = popTotal * popInc;
        cout << "Day " << i + 1 << ": " << setprecision(2) << popTotal << endl;
    }
    return 0;
}

