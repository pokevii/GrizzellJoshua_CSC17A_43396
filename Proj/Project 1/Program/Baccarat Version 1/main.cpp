#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Constants
const string suit[4] = {" of Clubs", " of Hearts", " of Spades", " of Diamonds"};
const string face[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

//Structs
struct Hand{
  string* cards;
  int score;
};

//Functions
string drwCard();
int cardVal(string strCard);
void play();
void clear();

int main() {
  int menuNum, tScore;
  string tCard;
  cout << "Welcome to Baccarat!\nVersion 1: PROTOTYPE EDITION!\n";
  do{
    srand(time(NULL));
    cout << "1: Draw a card.\n2: Get value of drawn card.\n3: Play a normal game of Baccarat.\n4+: Exit\n";
    cin >> menuNum;
    switch(menuNum){
      case 1: tCard = drwCard();
      break;
      case 2: tScore = cardVal(tCard);
      break;
      case 3: play();
      break;
      default: break;
    }
  }while(menuNum < 4);
}

void play(){
  string dCard[10], pCard[10];
  int dScore = 0, pScore = 0, hndCount = 0;
  Hand dHand, pHand;
  
  //Clear the screen.
  clear();
  //Player goes first.
  do{
    pCard[hndCount] = drwCard();
    cout << "PLAYER: " << pCard[hndCount];
    pScore += cardVal(pCard[hndCount]);
    cout << " (+" << cardVal(pCard[hndCount]) << ")\n";
    hndCount++;
  }while (hndCount < 2 || pScore <= 5);
  
  pHand.score = pScore;
  pHand.cards = new string[hndCount];
  for(int i = 0; i < hndCount; i++){
    pHand.cards[i] = pCard[i];
  }

  //Dealer goes next.
  hndCount = 0;
  do{
    dCard[hndCount] = drwCard();
    cout << "DEALER: " << dCard[hndCount];
    dScore += cardVal(dCard[hndCount]);
    cout << " (+" << cardVal(dCard[hndCount]) << ")\n";
    hndCount++;
  }while (hndCount < 2 || dScore <= 5);
  
  dHand.score = dScore;
  dHand.cards = new string[hndCount];
  for(int i = 0; i < hndCount; i++){
    dHand.cards[i] = dCard[i];
  }

  pScore %= 10;
  dScore %= 10;

  cout << "\nPlayer's Score: " << pScore << endl;
  cout << "Dealer's Score: " << dScore << "\n\n";

  if(pScore > dScore){
    cout << "PLAYER WINS!\n\n";
  } else if (dScore > pScore){
    cout << "DEALER WINS!\n\n";
  } else {
    cout << "TIE!!!\n\n";
  }

}

string drwCard(){
  string card;
  string prevCrd;
  int suitNum, faceNum;
  
  do{
    faceNum = rand() % 13;
    suitNum = rand() % 4;

    card = face[faceNum] + suit[suitNum];
  }while(card == prevCrd);

  prevCrd = card;
  return card;
}

int cardVal(string strCard){
  int value = -1;
  
  for(int i = 0; i < 13; i++){
    for(int j = 0; j < 4; j++){
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

void clear(){
  cout << "\033[2J\033[1;1H";
}