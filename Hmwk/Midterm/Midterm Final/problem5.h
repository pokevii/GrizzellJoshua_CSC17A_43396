#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

/*          
*   PROBLEM 5
*/   

void problem5(){
  char c = 1;                     // 127  
  unsigned char uChar = 1;        // 255  
  short shrt = 1;                 //±32767    
  unsigned short uShrt = 1;       // 65535    
  int integer = 1;                //±2,147,483,647  
  unsigned int uInt = 1;          // 4,294,967,295
  long l = 1;                     // 2,147,483,647
  unsigned long uLong = 1;        // 4,294,967,295
  float f = 1;                    // 3.4e±38
  double d = 1;                   // 1.7e±308
  //Char
  for(int i = 1; i <= 5; i++){
    c *= i;
    if(i == 5){
      cout << "Maximum factorial for char: 5! (" << int(c) << ")\n"; 
    }
  }
  //Unsigned char
  for(int i = 1; i <= 5; i++){
    uChar *= i;
    if(i == 5){
      cout << "Maximum factorial for unsigned char: 5! (" << int(uChar) << ")\n"; 
    }
  }
  //Short
  for(int i = 1; i <= 7; i++){
    shrt *= i;
    if(i == 7){
      cout << "Maximum factorial for short: 7! (" << shrt << ")\n"; 
    }
  }
  //Unsigned short
  for(int i = 1; i <= 8; i++){
    uShrt *= i;
    if(i == 8){
      cout << "Maximum factorial for unsigned short: 8! (" << uShrt << ")\n"; 
    }
  }
  //Integer
  for(int i = 1; i <= 12; i++){
    integer *= i;
    if(i == 12){
      cout << "Maximum factorial for integer: 12! (" << integer << ")\n"; 
    }
  }
  //Unsigned integer
  for(int i = 1; i <= 12; i++){
    uInt *= i;
    if(i == 12){
      cout << "Maximum factorial for unsigned integer: 12! (" << uInt << ")\n"; 
    }
  }
  //Long
  for(int i = 1; i <= 12; i++){
    l *= i;
    if(i == 12){
      cout << "Maximum factorial for long: 12! (" << l << ")\n"; 
    }
  }
  //Unsigned long
  for(int i = 1; i <= 12; i++){
    uLong *= i;
    if(i == 12){
      cout << "Maximum factorial for unsigned long: 12! (" << uLong << ")\n"; 
    }
  }
  //Float
  for(int i = 1; i <= 34; i++){
    f *= i;
    if(i == 34){
      cout << "Maximum factorial for float: 34! (" << f << ")\n"; 
    }
  }
  //Double (this assignment really makes me understand why you hate doubles so much, Dr. Lehr)
  for(int i = 1; i <= 170; i++){
    d *= i;
    if(i == 170){
      cout << "Maximum factorial for double: 170! (" << d << ")\n"; 
    }
  }
}

//now I know we can't declare auto in a function prototype. 
//what a shame, it would've made the code look so much better!
/*
void factorial(string name, auto num, int max){
  for(int i = 1; i < max+1; i++){
    num *= i;
    cout << num << endl;
    if(i == max){
      cout << "Maximum factorial for " << name << ": " << max << "! (" << num << ")\n"; 
    }
  }
}
*/ 
