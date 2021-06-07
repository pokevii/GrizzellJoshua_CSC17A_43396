#include "Shop.h"
#include <iostream>
#include <iomanip>
using namespace std;

Shop::Shop(bool isNew){
  //Define the items here if there's a new instance of Shop.
  if(isNew){
    item[0] = {
      "Prettier Stats Page",
      "Get some fancy ASCII art on your stats page!",
      2000,
      false 
    };
    item[1] = {
      "Name Change",
      "Don't like your name? Go ahead, change it! For a price...",
      2500,
      false
    };
    item[2] = {
      "Purchase a Pet Cat",
      "Want a little feline friend? Look no further! Purchase this to take care of a cat!\nNote: You can only have one pet. Choose wisely!",
      2999.99,
      false
    };
    item[3] = {
      "Purchase a Pet Dog",
      "Want a canine companion? Look no further! Purchase this to take home a new dog!\nNote: You can only have one pet. Choose wisely!",
      3999.99,
      false
    };
    item[4] = {
      "Big Head Mode",
      "This does nothing. There are no heads in this game. Spend money on it anyway.",
      3.14,
      false
    };
    //If this isn't a new instance, and instead one to load in from a file, do that here.
  } else {
    cout << "Load in things here.";
  }
}

//This prints the shop and allows the user to purchase items from it.
//This function made me make "money" a static variable. It should have been from the start, honestly.
PlayerData Shop::prnShop(PlayerData pd){ 
  int menuNum;
  char rspnse;

  cout << setprecision(2) << fixed;
  cout << "==================SHOP==================\n";
  for(int i = 0; i < 5; i++){
    if(pd.bought[i] == true){
      cout << "[X] ";
    }
    cout << i+1 << ". " << setw(25) << left << item[i].getName() << "$" << setw(10) << item[i].getPrice() << endl;
  }
  cin >> menuNum;
  Item curItem = item[menuNum-1];
  cout << curItem.getDesc() << endl;

  //If the player already has this item, get 'em outta here.
  if(pd.bought[menuNum-1] == true){
    cout << "You already have this item!\n\n";
    return pd;
  }

  //If the player already has a pet, make them feel bad for trying to replace them.
  if(pd.bought[2] == true){
    if(curItem.getName() == "Purchase a Pet Dog"){
      cout << "You can't buy more than one pet! You already have a loving pet cat...\n\n";
      return pd;
    }
  }
  if(pd.bought[3] == true){
    if(curItem.getName() == "Purchase a Pet Cat"){
      cout << "You can't buy more than one pet! You already have a loving pet dog...\n\n";
      return pd;
    }
  }

  cout << "This item costs $" << curItem.getPrice() << ". ";
  cout << "You have $" << pd.money << ".\n";

  //Check if user can afford the item
  if(curItem.getPrice() > pd.money){
    cout << "Unfortunately, you cannot afford this at the moment. Come back another time.\n\n";
  } else {
    //Ask the user if they would like to purchase the item.
    do{
      cout << "Would you like to purchase this item? (Y/N): ";
      cin >> rspnse;
    }while(rspnse != 'Y' && rspnse != 'N');
    //If yes, ensure to flag the item as bought.
    if(rspnse == 'Y'){
      pd.money -= curItem.getPrice();
      pd.setItem(true, menuNum-1);
      curItem.setBght(true);
      item[menuNum-1] = curItem;
      cout << "Item successfully purchased. Enjoy!\n\n";
    } else {
      cout << "Aww, how unfortunate. Oh, well.\n\n";
    }
  }

  //Name change function if they bought it
  if(pd.getItem(1)){
    char name[25];
    cout << "Set your brand new name!: ";
    cin >> name;
    pd.setNam(name);
    pd.setItem(1, false);
    curItem.setBght(false);
  }

  //Set if the player has pet if they buy a cat or a dog.
  if(pd.getItem(2)){
    char n[25];
    cout << "You've bought a cat! You can now access menu option #4.\n";
    pd.setHPet(true);
    pd.setPetT(1);
    cout << "What will you name your cat?: "; 
    cin >> n;
    pd.setPNam(n);
  }

  if(pd.getItem(3)){
    char n[25];
    cout << "You've bought a dog! You can now access menu option #5.\n";
    pd.setHPet(true);
    pd.setPetT(2);
    cout << "What will you name your dog?: "; 
    cin >> n;
    pd.setPNam(n);
  }

  return pd;
}