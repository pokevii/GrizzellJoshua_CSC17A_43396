#ifndef LASTGAME_H
#define LASTGAME_H

#include <iostream>
#include "Hand.h"
using namespace std;

class LastGame : public Hand{ 
  protected:
    Hand dealer;
    Hand player;
    string date;
    string winner;
  public:
  //Constructors
    LastGame(){
      winner = "";
      date = "";
    }
    LastGame(Hand dlr, Hand p, string d, string w){
      dealer = dlr;
      player = p;
      date = d;
      winner = w;
    }

    //Accessors and Mutators
    string getWinr() { return winner; }
    string getDate() { return date; }
    void setWinr(string w) { winner = w; }
    void setDate(string d) { date = d; }

    //Inline functions that are declared in LastGame.cpp
    void dispLG();
    void fillDat(Hand p, Hand d);
};

#endif