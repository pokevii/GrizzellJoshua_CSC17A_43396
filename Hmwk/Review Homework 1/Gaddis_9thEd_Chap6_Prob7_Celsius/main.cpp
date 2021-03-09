#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

float celsius(int temp);
/*
 * 
 */
int main(int argc, char** argv) {
    float cTemp;
    
    //Create the top of the table.
    cout << setw(6) << left << "F " << "||" 
            << setw(10) << right << "C" << endl; 
    cout << "==================" << endl;
    
    //Loop!
    cout << fixed;
    for(int i = 0; i < 21; i++) {
        
        cTemp = celsius(i);
        
        cout << setw(6) << left << i << "||" 
                << setw(10) << setprecision(2) << right << cTemp << endl;
    }
    
    return 0;
}

//I thought the convention was to capitalize function names
//But I am but a student, I will follow the will of the book...
float celsius(int temp) {
    float celsius;
    celsius = (temp - 32)*(5.0/9.0);
    return celsius;
}
