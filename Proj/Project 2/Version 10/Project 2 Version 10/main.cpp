#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "LastGame.h"
#include "PlayerData.h"
#include "Shop.h"
#include "Cat.h"
#include "Dog.h"

using namespace std;

//Constants
unsigned const int ms = 1000000;

//Global variables. They are not destroyed until the program ends.
//I know global variables are bad, but I need to use these in functions which cannot otherwise access them.
LastGame lastGame;

//Functions
PlayerData play(bool mode);
PlayerData bet(PlayerData pd);
void clear();
PlayerData newData();

//Main function
int main() {
  fstream file;
  PlayerData pd;
  Shop shop(true); 
  Cat cat;
  Dog dog;

  //cout << "Opening file.";
  file.open("data.dat", ios::in | ios::binary);
  if(file.fail()) { 
    pd = newData();
  } else {
    pd.Load();
    cout << "Welcome back to Baccarat, " << pd.getNam() << "!\n";
  }
  file.close();

  int menuNum;

  cout << "Version 10: PETS!\n\n";
  do{
    srand(time(NULL));
    cout << "Balance: $" << fixed << setprecision(2) << pd.getMny() << endl;
    cout << "1: [For Fun] Play a game of Baccarat.\n2: [For Glory] Put some money down!\n3: Visit the shop.\n";
    if(!pd.getHPet() || pd.getPetT() != 1){
      cout << "[X] ";
    }
    cout << "4: Check on your cat.\n";
    if(!pd.getHPet() || pd.getPetT() != 2){
      cout << "[X] ";
    }
    cout << "5: Check on your dog.\n";
    cout << "6: View post-game statistics.\n7: View your statistics.\n8: Delete save data.\n9+: Save and Exit\n";

    cin >> menuNum;
    switch(menuNum){
      //Play a regular match of baccarat.
      case 1: clear();
      pd += play(0);
      break;
      //Bet on a match of baccarat.
      case 2: clear();
      pd = bet(pd);
      break;
      //Utilize the shop.
      case 3: clear();
      pd = shop.prnShop(pd);
      break;
      //Manage cat, if you have one.
      case 4: clear();
      if(!pd.getHPet()){
        cout << "You don't have a cat! Go buy one at the shop.\n\n";
        break;
      }
      if(pd.getPetT() != 1){
        cout << "You already have a dog! Go take care of it instead.\n\n";
        break;
      }
      cat.petMenu(pd);
      break;
      //Manage dog, if you have one.
      case 5: clear();
      if(!pd.getHPet()){
        cout << "You don't have a dog! Go buy one at the shop.\n\n";
        break;
      }
      if(pd.getPetT() != 2){
        cout << "You already have a cat! Go take care of it instead.\n\n";
        break;
      }
      dog.petMenu(pd);
      break;
      //Display information from the last game.
      case 6: clear();
      lastGame.dispLG();
      break;
      //Display player's data.
      case 7: clear();
      pd.DispDat();
      break;
      //Delete player's data.
      case 8: clear();
      pd.DelDat();
      break;
      default: break;
    }
  }while(menuNum < 8);
  //Return without saving if delDat was called
  if(menuNum == 8){
    return 1;
  }
  //Save by default
  pd.Save();
  cout << "Saved successfully. See you!\n";
  return 0;
}

//Takes "mode" param; 0 = for fun, 1 = betting.
PlayerData play(bool mode){
  PlayerData game;
  string dCard[10], pCard[10], outCard[52];
  int dScore = 0, pScore = 0;
  int c = 0, o = 0;    //c = card drawn counter, o = out cards counter
  Hand dHand, pHand;

  //Clear the screen.
  clear();

  //Player goes first.
  do{
    pCard[c] = pHand.drwCard();
    //If we find a card that has already been drawn, continue.
    if(pHand.repeat(c, pCard[c], outCard)){
      //cout << "[R] PLAYER: " << pCard[c] << endl;
      continue;
    };
    pScore += dHand.cardVal(pCard[c]);
    outCard[o] = pCard[c];
    cout << "PLAYER: " << pCard[c] << " (+" << pHand.cardVal(pCard[c]) << ")\n";
    c++, o++;
    usleep(0.2 * ms);
  }while (c < 2 || pScore < 5);
  //Transfer the score and cards into their struct.
  pHand.setScre(pScore);
  pHand.setDrwn(c);
  for(int i = 0; i < c; i++){
    pHand.setCard(pCard[i], i);
  }
  usleep(ms);

  //Dealer goes next.
  c = 0;
  do{
    dCard[c] = dHand.drwCard();
    if(dHand.repeat(c, dCard[c], outCard)){
      //cout << "[R] DEALER: " << dCard[c] << endl;
      continue;
    }
    dScore += dHand.cardVal(dCard[c]);
    outCard[o] = dCard[c];
    cout << "DEALER: " << dCard[c] << " (+" << dHand.cardVal(dCard[c]) << ")\n";
    c++, o++;
    usleep(0.2 * ms);
  }while (c < 2 || dScore < 5);
  dHand.setScre(dScore);
  dHand.setDrwn(c);
  for(int i = 0; i < c; i++){
    dHand.setCard(dCard[i], i);
  }
  usleep(ms);

  //Calculate final score; numbers 10 or higher get the first digit lopped off.
  pScore %= 10;
  dScore %= 10;
  cout << "\nPlayer's Score: " << pHand.getScre() << endl;
  cout << "Dealer's Score: " << dHand.getScre() << "\n\n";

  //If mode == 0, add wins/losses to playerdata.
  if(mode == 0){
    if(pHand.getScre() > dHand.getScre()){
      game.WonGame();
    } else if (pHand.getScre() < dHand.getScre()){
      game.LstGame();
    } else {
      game.TieGame();
    }
  }

  lastGame.fillDat(pHand, dHand);
  cout << "__________________________________\n\n";

  return game;
}

PlayerData bet(PlayerData pd){
  float wager;
  int betVal = 0;
  float money = pd.getMny();

  if(money == 0){
    cout << "Hey, you have no money! Giving a starting value of $1000.\n";
    money = 1000.00;
  }
  
  do{
    clear();
    cout << "Balance: $" << fixed << setprecision(2) << money << "\n\n";
    cout << left << setw(16) << "1. Player wins" << setw(4) << "[2:1]\n"; 
    cout << left << setw(16) << "2. Dealer wins" << setw(4) << "[2:1]\n"; 
    cout << left << setw(16) << "3. Tie" << setw(4) << "[8:1]\n"; 
    cin >> betVal;
    switch(betVal){
      case 1: cout << "You will win 2x your bet if you win the game.\nHow much will you put down?: ";
      break;
      case 2: cout << "You will win 2x your bet if the dealer wins the game.\nHow much will you put down?: ";
      break;
      case 3: cout << "You will win 8x your bet if the game ends in a tie.\nHow much will you put down?: ";
      break;
        case 4: cout << "Screw it, just give me $10000. Just to see what else this program has to offer.\n";
        break;
      default: cout << "Invalid number!\n";
      break;
    }
  }while(betVal > 4 || betVal < 1);

  //Make sure that the user can't bet more than they have.
  do{
    cin >> wager;
  }while(wager > money);

  play(1);

  switch(betVal){
    case 1: if(lastGame.getWinr() == "Player"){
      money += wager*2;
      money -= wager;
      pd.AddGns(wager*2 - wager);
      pd.WonBet();
      cout << "\nYou've won your bet! Your wager of $" << wager << " has been DOUBLED! ($" << wager*2 << ")\n";
    } else {
      money -= wager;
      pd.LostBet();
      cout << "\nYou've lost your bet, and with it, your $" << wager << "...\n";
    }
    break;
    case 2: if(lastGame.getWinr() == "Dealer"){
      money += wager*2;
      money -= wager;
      pd.AddGns(wager*2 - wager);
      pd.WonBet();
      cout << "\nYou've won your bet! Your wager of $" << wager << " has been DOUBLED! ($" << wager*2 << ")\n";
    } else {
      money -= wager;
      pd.LostBet();
      cout << "\nYou've lost your bet, and with it, your $" << wager << "...\n";
    }
    break;
    case 3: if(lastGame.getWinr() == "Tie"){
      money += wager*8;
      money -= wager;
      pd.AddGns(wager*8 - wager);
      pd.WonBet();
      cout << "\nYou've won your bet! Your wager of $" << wager << " has been OCTUPLED! ($" << wager*8 << ")\n";
    } else {
      money -= wager;
      pd.LostBet();
      cout << "\nYou've lost your bet, and with it, your $" << wager << "...\n";
    }
    break;
      case 4: money = 10000;
              break;
    default: break;
  }
  cout << money << endl;
  pd.setMny(money);
  return pd;
}

void clear(){
  cout << "\033[2J\033[1;1H";
}

PlayerData newData(){
  PlayerData pd;
  char name[25];

  cout << "Welcome to Baccarat! It must be your first time playing.\n";
  cout << "What would your name be? (One word, please!): ";
  cin >> name;
  pd.setNam(name);
  cout << "Well, nice to meet you, " << pd.getNam() << "!\n";
  cout << "Since you're new here, how about I give you $1000?\n";
  cout << "On the house, of course. Gamble responsibly!\n(press enter to continue)\n";
  cin.ignore(); //Need two here because of the cin
  cin.ignore();
  pd.setMny(1000);
  clear();

  return pd;
}
