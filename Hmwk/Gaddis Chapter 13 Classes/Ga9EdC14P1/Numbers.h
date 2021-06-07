#include <iostream>
using namespace std;

class Numbers{
  private:
    int number;
    static string ones[];
    static string tens[];
  public:

    Numbers(int num){
      number = num;
    }
    void print();
    string convert(int n, string s);
};