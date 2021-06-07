#ifndef HAND_H
#define HAND_H

#include <iostream>
using namespace std;

class Hand{
  protected:
    string cards[10];
    int drawn, score;
    static const string suit[4];
    static const string face[13];
  public:
    //Constructors
    Hand(){
      int drawn = 0;
      int score = 0;
    }
    Hand(string c[10], int d, int s){
      for(int i = 0; i < 10; i++){
        cards[i] = c[i];
      }
      drawn = d;
      score = s % 10;
    }

    //Copy Constructors
    Hand(const Hand &h){
      for(int i = 0; i < 10; i++){
        cards[i] = h.cards[i];
      }
      drawn = h.drawn;
      score = h.score;
    }

    //Accessors & Mutators
    int getDrwn() { return drawn; }
    int getScre() { return score; }
    string getCard(int index) { return cards[index]; }
    void setDrwn(int d) { drawn = d; }
    void setScre(int s) { score = s % 10; }
    void setCard(string card, int index) { cards[index] = card; } 
    
    //Functions defined in hand.cpp
    string drwCard();
    int cardVal(string strCard);
    bool repeat(int o, string card, string *deck);

    //Operator overloads
    Hand operator ++ (int);
    Hand operator -- (int);
};

#endif