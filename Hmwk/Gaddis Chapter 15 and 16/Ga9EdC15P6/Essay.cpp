#include <iostream>
#include "Essay.h"
using namespace std;

void Essay::grade(){
  float total;
  total = spelling + grammar + content + length;
  setScore(total);
  cout << "Essay graded with a score of " << getScore() << "%\n";
}