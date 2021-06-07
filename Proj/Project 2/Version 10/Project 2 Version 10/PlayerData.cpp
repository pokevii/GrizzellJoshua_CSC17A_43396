#include "PlayerData.h"
#include "Shop.h"

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//Need to define static vars here or else undefined reference
Item Shop::item[9];
float PlayerData::money;
bool PlayerData::bought[5];
bool PlayerData::hasPet;

void PlayerData::DispDat(){
  //The 'spice' variable is just if the first item in the shop has been purchased.
  bool spice = bought[0]; 
  float ratio;
  float betRtio;
  ratio = float(wins) / float(losses);
  betRtio = float(betWon) / float(betLost);

  //clear();
  if(betWon == 0 && betLost == 0){
    betRtio = 0;
  }
  if(!spice){
    cout << "=========================\n";
  } else {
    cout << "	        /\\" << endl;
    cout << "           / *\\" << endl;
	  cout << "          /  **\\" << endl;
    cout << "=========/   ***\\========" << endl;
  }
  cout << name << "'s Baccarat Profile\n\n";
  cout << "WINS: " << wins << endl;
  cout << "LOSSES: " << losses << endl;
  cout << "TIES: " << ties << endl;
  cout << "W/L RATIO: " << ratio << "\n\n";
  cout << "BETS WON: " << betWon << endl;
  cout << "BETS LOST: " << betLost << endl;
  cout << "W/L RATIO: " << betRtio << "\n\n";
  cout << "TOTAL PROFITS: $" << gains << endl; 
  if(!spice){
    cout << "=========================\n\n";
  } else {
    cout << "=====|   /======\\***|====" << endl;
    cout << "     |  /        \\**|      " << endl;
    cout << "     | /          \\*|      " << endl;
    cout << "     |/            \\|      " << endl;
  }

}

void PlayerData::DelDat(){
  char c;
  cout << "Hey, " << name << ", we'll be sad to see you go.\n";
  cout << "Are you sure you want to delete your save data? (Y/N): ";
  cin >> c;
  switch(c){
    case 'y':
    case 'Y': cout << "You got it. Make sure to come back sometime, understand?\n";
    if(remove("data.dat") != 0){
      cout << "Error deleting file... hehe, maybe it's a blessing in disguise, eh?\n";
    } else {
      cout << "Save data's all gone! See you around!\n";
    }
    break;
    case 'n':
    case 'N': cout << "Gotcha, your save data is safe. Still gotta end the program, though. You understand.\n";
    break;
  }
}

void PlayerData::Load(){
  fstream file;

  //Load the file. If it can't be loaded, throw an exception.
  try{
    file.open("data.dat", ios::in | ios::binary);
    if(file.fail()){
      throw NoDataFound();
    }
  } catch (NoDataFound e) {
    cout << "Error: No save data found. Terminating program...\n";
  }
  
  //Load in data from the binary file.
  file.read(reinterpret_cast<char *>(&money), sizeof(money));
  file.read(reinterpret_cast<char *>(&name), sizeof(name));
  file.read(reinterpret_cast<char *>(&wins), sizeof(wins));
  file.read(reinterpret_cast<char *>(&losses), sizeof(losses));
  file.read(reinterpret_cast<char *>(&ties), sizeof(ties));
  file.read(reinterpret_cast<char *>(&betWon), sizeof(betWon));
  file.read(reinterpret_cast<char *>(&betLost), sizeof(betLost));
  file.read(reinterpret_cast<char *>(&gains), sizeof(gains));
  file.read(reinterpret_cast<char *>(&bought), sizeof(bought));
  file.read(reinterpret_cast<char *>(&hasPet), sizeof(hasPet));
  file.read(reinterpret_cast<char *>(&petName), sizeof(petName));
  file.read(reinterpret_cast<char *>(&petType), sizeof(petType));

  file.close();
}

void PlayerData::Save(){
  fstream file;

  //Load the file. If it can't be loaded, throw an exception.
  try{
    file.open("data.dat", ios::out | ios::binary);
    if(file.fail()){
      throw NoDataFound();
    }
  } catch (NoDataFound e){
    cout << "Error: No save data found. Terminating program...\n";
  }

  //Load in data from the binary file.
  file.write(reinterpret_cast<char *>(&money), sizeof(money));
  file.write(reinterpret_cast<char *>(&name), sizeof(name));
  file.write(reinterpret_cast<char *>(&wins), sizeof(wins));
  file.write(reinterpret_cast<char *>(&losses), sizeof(losses));
  file.write(reinterpret_cast<char *>(&ties), sizeof(ties));
  file.write(reinterpret_cast<char *>(&betWon), sizeof(betWon));
  file.write(reinterpret_cast<char *>(&betLost), sizeof(betLost));
  file.write(reinterpret_cast<char *>(&gains), sizeof(gains));
  file.write(reinterpret_cast<char *>(&bought), sizeof(bought));
  file.write(reinterpret_cast<char *>(&hasPet), sizeof(hasPet));
  file.write(reinterpret_cast<char *>(&petName), sizeof(petName));
  file.write(reinterpret_cast<char *>(&petType), sizeof(petType));
  file.close(); 
}

//These are simple functions that, for the most part, add 1 to a member.
void PlayerData::LostBet() { betLost++; }
void PlayerData::WonBet() { betWon++; }
void PlayerData::LstGame() { losses++; }
void PlayerData::WonGame() { wins++; }
void PlayerData::TieGame() { ties++; }
void PlayerData::AddGns(float g) { gains += g; }

//Operator overloads
PlayerData PlayerData::operator +=(const PlayerData &other){
  money += other.money;
  wins += other.wins;
  losses += other.losses;
  ties += other.ties;
  betWon += other.betWon;
  betLost += other.betLost;
  gains += other.gains;
  return *this;
}

PlayerData PlayerData::operator -=(const PlayerData &other){
  money -= other.money;
  wins -= other.wins;
  losses -= other.losses;
  ties -= other.ties;
  betWon -= other.betWon;
  betLost -= other.betLost;
  gains -= other.gains;
  return *this;
}