#ifndef CAT_H
#define CAT_H
#include "Animal.h"
#include "PlayerData.h"
#include <algorithm>
using namespace std;

class Cat : public Animal{
  public:
      void arrSort();
      
    void speak(){
      clear();
      cout << "\"Meow.\"\n";
    }

    void pet(){
      clear();
      cout << "You pet " << name << ".\n";
      cout << "\"Purrrr...\"\n";
      cout << "You think it likes that.\n\n";
    }

    void status(){
      clear();
      cout << "You can't tell what it's feeling.\n\n";
    }

    void trick(){
      clear();
      cout << "Your cat knows how to use STL! Good kitty, good kitty!\n\n";
      arrSort();
    }

    void setup(PlayerData pd){
      char n[25];
      cout << "You brought home a new feline friend from the store.\n";
      cout << "My, it's so adorable..\n";
      cout << "What will you name it?";
      cin >> n;
      this->setName(n);
      cout << "What a nice name! I hope this little kitten grows up to be a strong cat!\n";
      pd.setPNam(n);
      pd.setPetT(1);
    }
};

void Cat::arrSort(){
    int* arr = new int[20];
    int rspNum = rand() % 3;
    for(int i = 0; i < 20; i++){
        arr[i] = rand() % 20;
        cout << arr[i] << " ";
    }
    cout << endl;
    
    sort(arr, arr + 20);
    
    for(int i = 0; i < 20; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    switch(rspNum){
        case 0: cout << "After sorting the array, " << name << " finds a box and sleeps in it.\n\n";
        break;
        case 1: cout << "After sorting the array, " << name << " goes to get some kibble.\n\n";
        break;
        case 2: cout << "After sorting the array, " << name << " starts to look very smug.\n\n";
    }
    
    delete[] arr;
}

#endif