#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

/*          
*   PROBLEM 6
*/  

void problem6(){
  cout << "DECIMAL     OCTAL   HEX     BINARY\n";
  cout << left << setw(12) << "2.875" << setw(8) << "2.7" << setw(8) << "2.E" << "0010.1110\n"; 
  cout << left << setw(12) << "0.1796875" << setw(8) << "0.134" << setw(8) << "0.2E" << ".00010111\n\n"; 
  cout << "DECIMAL     OCTAL       HEX         BINARY\n";
  cout << left << setw(12) << "-2.875" << setw(12) << "177776.01" << setw(12) << "FFFE.1" << "1110.0001\n"; 
  cout << left << setw(12) << "-0.1796875" << setw(12) << ".177751" << setw(12) << ".FFE9" << ".11101001\n\n";
  cout << left << setw(10) << "ORIGINAL" << setw(10) << "DECIMAL    \n";
  cout << left << setw(10) << "59999901" << setw(10) << "1503238401\n";
  cout << left << setw(10) << "59999902" << setw(10) << "1503238402\n";
  cout << left << setw(10) << "A66667FE" << setw(10) << "2791729150\n\n"; 
  //These last 3 feel wrong to me, but I don't know for sure if they are.
  //Just a gut feeling.
}