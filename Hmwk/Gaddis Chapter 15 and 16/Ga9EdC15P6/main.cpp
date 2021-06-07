#include <iostream>
#include "Essay.h"
using namespace std;

int main() {
  int g, s, l, c;
  
  cout << "Grading essay...\n\n";
  do{
    cout << "Input score for grammar (max score 30): ";
    cin >> g;
  }while(g > 30 || g < 0);
  do{
    cout << "Input score for spelling (max score 20): ";
    cin >> s;
  }while(s > 20 || s < 0);
  do{
    cout << "Input score for length (max score 20): ";
    cin >> l;
  }while(l > 20 || l < 0);
  do{
    cout << "Input score for content (max score 30): ";
    cin >> c;
  }while(c > 30 || c < 0);

  Essay essay(g, s, l, c);
  essay.grade();

}