#ifndef DOG_H
#define DOG_H
#include "Animal.h"
#include "PlayerData.h"
#include <typeinfo>
using namespace std;

class Dog : public Animal{
  public:
    template<class T>
    void typeGuess(T type);

    void speak(){
      clear();
      cout << "\"Woof.\"\n\n";
    }

    void pet(){
      clear();
      cout << "You pet " << name << ".\n";
      cout << "\"*pant*... *pant*...\"\n";
      cout << "Its tail is wagging.\n\n";
    }

    void status(){
      clear();
      cout << "It's hungry.\n\n";
    }

    void trick(){
      clear();
      int menuNum;
      int i;
      char c;
      float f;

      cout << "Your dog tells you to choose a type. He'll guess what you chose without looking.\n";
      cout << "1. int\n2. float\n3.char\n";
      do{
        cin >> menuNum;
        switch(menuNum){
          case 1: cout << "Input your int: ";
          cin >> i;
          typeGuess(i);
          break;
          case 2: cout << "Input your float: ";
          cin >> f;
          typeGuess(f);
          break;
          case 3: cout << "Input your char: ";
          cin >> c;
          typeGuess(c);
          break;
          default: break;
        }
      }while(menuNum > 3);
    }

    void setup(PlayerData pd){
      char n[25];
      cout << "You brought home a new canine companion from the store.\n";
      cout << "Goodness, it's so cute..\n";
      cout << "What will you name it?";
      cin >> n;
      this->setName(n);
      cout << "What a nice name! I hope this little pup grows up to be a strong dog!\n";
      pd.setPNam(n);
      pd.setPetT(1);
    }
};

template<class T>
void Dog::typeGuess(T type){
  cout << "\"Your variable is of type " << typeid(type).name() << ". Woof!\"\n";
  type *= 2;
  cout << "\"I can multiply that by two to get " << type << "!\" *wags tail*\n\n";
}

#endif