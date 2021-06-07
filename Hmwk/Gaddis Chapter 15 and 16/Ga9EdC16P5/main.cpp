#include <iostream>
using namespace std;

template <class T>
T total(int i){
    T sum = 0;
    T num;

    while(i > 0){
        cin >> num;
        sum += num;
        i--;
    }
    return sum;
}


int main() {
  int amount;

  cout << "How many integers would you like to input?: "; 
  cin >> amount;
  cout << "Input " << amount << " integers: " << total<int>(amount);

  cout << "\nGreat! How many floats would you like to input?: "; 
  cin >> amount;
  cout << "Now input " << amount << " floats: " << total<float>(amount);

  cout << "\nLet's do shorts last. How many shorts would you like to input?: "; 
  cin >> amount;
  cout << "Finally, input " << amount << " shorts: " << total<short>(amount);
}
