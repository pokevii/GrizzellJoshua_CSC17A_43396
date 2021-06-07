#include <iostream>
#include "Numbers.h"
using namespace std;

string Numbers::ones[20] = {"", " one", " two", " three", " four", " five", " six", " seven", " eight", " nine", " ten", " eleven", " twelve"," thirteen", " fourteen", " fifteen", " sixteen", " seventeen", " eighteen", " nineteen"};
string Numbers::tens[10] = {"", "", " twenty", " thirty", " forty", " fifty", " sixty", " seventy", " eighty", " ninety"};

void Numbers::print(){
  string eng = "";
  eng += convert((number / 1000) % 100, " thousand");
  eng += convert((number / 100) % 10, " hundred");
  eng += convert((number % 100), "");

  cout << eng << endl;
}

string Numbers::convert(int n, string s){
  string cnvrtd = "";
  if(n > 19){
    cnvrtd += tens[n/10] + ones[n%10];
  } else {
    cnvrtd += ones[n];
  }

  if(n != 0){
    cnvrtd += s;
  }
  
  return cnvrtd;
}