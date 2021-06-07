#include <iostream>
#include <iomanip>
#include "TestScores.cpp"
using namespace std;

int main() {
  int t1, t2, t3;
  cout << "Input the score of test1: ";
  cin >> t1;
  cout << "Input the score of test2: ";
  cin >> t2;
  cout << "Input the score of test3: ";
  cin >> t3;
  TestScores scores = TestScores(t1, t2, t3);
  cout << "\nTest Scores:\n  Test 1: " << scores.getTest1() << "%\n";
  cout << "  Test 2: " << scores.getTest2() << "%\n";
  cout << "  Test 3: " << scores.getTest3() << "%\n";
  cout << setprecision(2) << fixed;
  cout << "  Average: " << scores.getAvg() << "%\n";

}