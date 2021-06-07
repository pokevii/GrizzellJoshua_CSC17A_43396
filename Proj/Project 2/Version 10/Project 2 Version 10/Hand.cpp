#include <iostream>
#include "Hand.h"
using namespace std;

const string Hand::suit[4] = {" of Clubs", " of Hearts", " of Spades", " of Diamonds"};
const string Hand::face[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

string Hand::drwCard(){
  string card;
  int suitNum, faceNum;
  
  //Get a random number from 0-13 for the face of the card.
  faceNum = rand() % 13;
  //Get a random number from 0-4 for the suit of the card.
  suitNum = rand() % 4;

  //The values from before give us the full name of the card using string arrays.
  card = face[faceNum] + suit[suitNum];

  return card;
}

int Hand::cardVal(string strCard){
  int value = -1;
  
  for(int i = 0; i < 13; i++){
    for(int j = 0; j < 4; j++){
      //If the string of the card is equal to the string the for loop generated, set the value.
      if(strCard == face[i] + suit[j]){
        value = i+1;
        //If the card is a jack, queen, or king, set the value to 0.
        if(value >= 10 && value <= 13){
          value = 0;
        }
      }
    }
  }
  //cout << value << " has been added to their score.\n";
  return value;
}

bool Hand::repeat(int o, string card, string *deck){
  bool same = false;
  for(int i = 0; i <= o; i++){
    //If the card passed in is equal to the current card in the discard pile, set the bool to true.
    if(deck[i] == card){
      same = true;
      break;
    }
  }
  return same;
}

//Operator overloads
Hand Hand::operator ++ (int){
  Hand temp(cards, score, drawn);
  temp.drawn = drawn + 1;
  return temp;
}

Hand Hand::operator -- (int){
  Hand temp(cards, score, drawn);
  temp.drawn = drawn - 1;
  return temp;
}