#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char month[3][30];
    char type;
    fstream inFile;

    inFile.open("weather.txt",ios::in);
    cout << " June  July  August\n";
    
    if (inFile.is_open()){  
       char c;
       for(int i = 0; i < 30; i++){
           for(int j = 0; j < 3; j++){
               inFile.get(c);
               cout << setw(3) << c;   
           }
       }
       
       inFile.close(); 
    }
   
    return 0;
}

