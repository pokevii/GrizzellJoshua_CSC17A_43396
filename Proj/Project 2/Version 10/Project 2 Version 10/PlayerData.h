/*! Holds all of the user’s saved data.
 Probably the most important class in the entire program.*/
#ifndef PLAYERDATA_H
#define PLAYERDATA_H

#include <iostream>
#include <cstring>
using namespace std;

class PlayerData{
  protected: 
    //static variables [very important]
    static float money;
    static bool bought[5];
    static bool hasPet;
    //player variables
    char name[25];
    int wins, losses, ties, betWon, betLost;
    float gains;
    //pet variables
    char petName[25];
    int petType;
  public:
    class NoDataFound { };
    friend class Shop;
  //Constructors
    PlayerData(){
      money = 0;
      wins = 0;
      losses = 0;
      ties = 0;
      betWon = 0;
      betLost = 0;
      hasPet = false;
      petType = 0;
    }
    PlayerData(float m, string nam, int w, int l, int t, int bw, int bl, float g){
      money = m;
      strcpy(name, nam.c_str());
      wins = w;
      losses = l;
      ties = t;
      betWon = bw;
      betLost = bl;
      gains = g;
      hasPet = false;
      petType = 0;
    }
    ~PlayerData(){
      //Destructor here
    }

    //Accessors
    float getMny() { return money; }
    char* getNam() { return name; }
    char* getPNam() { return petName; }
    float getGain() { return gains; }
    int getWins() { return wins; }
    int getLoss() { return losses; }
    int getTies() { return ties; }
    int getBWon() { return betWon; }
    int getBLst() { return betLost; }
    int getPetT() { return petType; }
    bool getItem(int index) { return bought[index]; }
    bool getHPet() { return hasPet; }

    //Mutators
    void setMny(float m) { money = m; }
    void setNam(char* n) { strcpy(name, n); }
    void setPNam(char* n) { strcpy(petName, n); }
    void setGain(float g) { gains = g; }
    void setWins(int w) { wins = w; }
    void setLoss(int l) { losses = l; }
    void setTies(int t) { ties = t; }
    void setBWon(int bw) { betWon = bw; }
    void setBLst(int bl) { betLost = bl; }
    void setPetT(int p) { petType = p; }
    void setItem(bool b, int index) { bought[index] = b; }
    void setHPet(bool b) { hasPet = b; }

    //Function Prototypes
    void DispDat();
    void DelDat();
    void Load();
    void Save();
    void WonBet();
    void LostBet();
    void WonGame();
    void LstGame();
    void TieGame();
    void AddGns(float g);

    //Operator Overloads
    PlayerData operator += (const PlayerData &other);
    PlayerData operator -= (const PlayerData &other);
};

#endif