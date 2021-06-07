#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using namespace std;

class Item{
  protected:
    string name;
    string desc;
    float price;
    bool isBought;
  public:
    friend class PlayerData;
    //Constructors
    Item(){
      name = "";
      desc = "";
      price = 0;
      isBought = false;
    }
    Item(string n, string d, float p, bool b){
      name = n;
      desc = d;
      price = p;
      isBought = b;
    }

    //Accessors and Mutators
    float getPrice() { return price; }
    string getName() { return name; }
    string getDesc() { return desc; }
    bool getBght() { return isBought; }

    void setPrice(float p) { price = p; }
    void setName(string n) { name = n; }
    void setDesc(string d) { desc = d; }
    void setBght(bool b) { isBought = b; }
};

#endif