#include <iomanip>
#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    float dollars, yen, euros;
    const float YEN_PER_DOLLAR = 0.0092;
    const float EUROS_PER_DOLLAR = 1.18;
    
    cout << "Enter an amount in U.S. Dollars: ";
    cin >> dollars;
    cout << endl;
    
    yen = dollars / YEN_PER_DOLLAR;
    euros = dollars / EUROS_PER_DOLLAR;
    
    cout << fixed;
    cout << "$" << setprecision(2) << dollars << endl;
    cout << "¥" << setprecision(2) << yen << endl;
    cout << "€" << setprecision(2) << euros << endl; 
    
    return 0;
}

