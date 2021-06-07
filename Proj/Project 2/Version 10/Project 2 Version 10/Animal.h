#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include "PlayerData.h"
using namespace std;

class Animal{
  protected:
    char name[25];
    int petType; // 0 = none, 1 = cat, 2 = dog
  public:
    friend class PlayerData;

    virtual void setup(PlayerData pd) = 0;
    virtual void speak() = 0;
    virtual void status() = 0;
    virtual void pet() = 0;
    virtual void trick() = 0;

    char* getName() { return name; }
    int getType() { return petType; }
    void setName(char* n) { strcpy(name, n); }
    void setType(int t) { petType = t; }
    void petMenu(PlayerData pd);
    void clear() { cout << "\033[2J\033[1;1H"; }
};

void Animal::petMenu(PlayerData pd){
  //Make sure the name is obtained from playerData.
  setName(pd.getPNam());
  petType = pd.getPetT();
  
  int menuNum;

  do {
    cout << name << "'s Room\n";
    cout << "1. Have " << name << " speak.\n";
    cout << "2. Check " << name << "'s status.\n";
    cout << "3. Pet " << name << endl;
    cout << "4. Make " << name << " do a trick.\n";
    cout << "5+. Return to baccarat.\n";
    cin >> menuNum;
    switch(menuNum){
      case 1: speak();
      break;
      case 2: status();
      break;
      case 3: pet();
      break;
      case 4: trick();
      break;
      case 5: return; 
      default: break;
    }
  }while(menuNum < 5);
}

#endif