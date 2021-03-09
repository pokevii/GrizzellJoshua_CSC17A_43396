#include <iostream>
#include <cstdlib>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    float celsius, fahrenheit;
    cout << "Enter a temperature in Celsius to convert to Fahrenheit: ";
    cin >> celsius;
    cout << endl;
    
    fahrenheit = (9.0/5.0)*celsius + 32;
    cout << celsius << "°C is " << fahrenheit << "°F.";
    return 0;
}

