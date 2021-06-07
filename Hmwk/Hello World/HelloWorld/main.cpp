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
  int drawn, score;
};

struct LastGame{
  Hand player;
  Hand dealer;
  string date, winner;
};

LastGame lastGame;

//Functions
void play();
float bet(float money, LastGame l);
string drwCard();
int cardVal(string strCard);
void clear();
void dispDat(LastGame l);
void cleanup(Hand &hand);
bool repeat(int o, string card, string *outCard);
LastGame fillDat(Hand p, Hand d, int pScore, int dScore);


//Main function
int main() {
  int menuNum;
  float money;

  cout << "Welcome to Baccarat!\nVersion 4: GAMBLING EDITION!\n";
  do{
    srand(time(NULL));
    cout << "1: Play a game of Baccarat for fun.\n2: Put some money down!\n3: View post-game statistics.\n3+: Exit\n";
    cin >> menuNum;
    switch(menuNum){
      case 1: play();
      break;
      case 2: bet(money, lastGame);
      break;
      case 3: dispDat(lastGame);
      default: break;
    }
  }while(menuNum < 4);
}

void play(){
  string dCard[10], pCard[10], outCard[52];
  int dScore = 0, pScore = 0;
  int c = 0, o = 0;    //c = card drawn counter, o = out cards counter
  Hand dHand, pHand;
  //Clear the screen.
  clear();
  //Player goes first.
  do{
    pCard[c] = drwCard();
    //If we find a card that has already been drawn, continue.
    if(repeat(c, pCard[c], outCard)){
      //cout << "[R] PLAYER: " << pCard[c] << endl;
      continue;
    };
    pScore += cardVal(pCard[c]);
    outCard[o] = pCard[c];
    cout << "PLAYER: " << pCard[c] << " (+" << cardVal(pCard[c]) << ")\n";
    c++, o++;
  }while (c < 2 || pScore < 5);
  //Transfer the score and cards into their struct.
  pHand.score = pScore;
  pHand.drawn = c;
  pHand.cards = new string[c];
  for(int i = 0; i < c; i++){
    pHand.cards[i] = pCard[i];
  }
  //Dealer goes next.
  c = 0;
  do{
    dCard[c] = drwCard();
    if(repeat(c, dCard[c], outCard)){
      //cout << "[R] DEALER: " << dCard[c] << endl;
      continue;
    }
    dScore += cardVal(dCard[c]);
    outCard[o] = dCard[c];
    cout << "DEALER: " << dCard[c] << " (+" << cardVal(dCard[c]) << ")\n";
    c++, o++;
  }while (c < 2 || dScore < 5);
  dHand.score = dScore;
  dHand.drawn = c;
  dHand.cards = new string[c];
  for(int i = 0; i < c; i++){
    dHand.cards[i] = dCard[i];
  }
  //Calculate final score; numbers 10 or higher get the first digit lopped off.
  pScore %= 10;
  dScore %= 10;
  cout << "\nPlayer's Score: " << pScore << endl;
  cout << "Dealer's Score: " << dScore << "\n\n";
  lastGame = fillDat(pHand, dHand, pScore, dScore);
  cout << "__________________________________\n\n";
}

float bet(float money, LastGame l){
  float wins, wager;
  int betVal;

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
    cout << left << setw(16) << "4. Player pair" << setw(4) << "[12:1]\n"; 
    cout << left << setw(16) << "5. Dealer pair" << setw(4) << "[12:1]\n"; 
    cin >> betVal;
    switch(betVal){
      case 1: cout << "You will win 2x your bet if you win the game.\nHow much will you put down?: ";
      break;
      case 2: cout << "You will win 2x your bet if the dealer wins the game.\nHow much will you put down?: ";
      break;
      case 3: cout << "You will win 8x your bet if the game ends in a tie.\nHow much will you put down?: ";
      break;
      case 4: cout << "You will win 12x your bet if you draw a pair.\nHow much will you put down?: ";
      break;
      case 5: cout << "You will win 12x your bet if the dealer draws a pair.\nHow much will you put down?: ";
      break;
      default: break;
    }
  }while(betVal > 5 || betVal < 1);

  //Make sure that the user can't bet more than they have.
  do{
    cin >> wager;
  }while(wager > money);

  play();

  switch(betVal){
    case 1: money = (l.winner == "Player") ? money += wager*2 : money -= wager;
    break;
    case 2: money = (l.winner == "Dealer") ? money += wager*2 : money -= wager;
    break;
    case 3: money = (l.winner == "Tie") ? money += wager*8 : money -= wager;
    break;
    default: break;
  }
  
  return money;
}

string drwCard(){
  string card;
  int suitNum, faceNum;
  
  faceNum = rand() % 13;
  suitNum = rand() % 4;

  card = face[faceNum] + suit[suitNum];

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

bool repeat(int o, string card, string *deck){
  bool same = false;
  for(int i = 0; i <= o; i++){
    if(deck[i] == card){
      same = true;
      break;
    }
  }
  return same;
}

LastGame fillDat(Hand p, Hand d, int pScore, int dScore){
  LastGame l;
  time_t curTime;
  time(&curTime);

  l.player = p;
  l.dealer = d;

  if(pScore > dScore){
    cout << "PLAYER WINS!\n\n";
    l.winner = "Player";
  } else if (dScore > pScore){
    cout << "DEALER WINS!\n\n";
    l.winner = "Dealer";
  } else {
    cout << "TIE!!!\n\n";
    l.winner = "Tie";
  }

  l.date = ctime(&curTime);

  return l;
}

void dispDat(LastGame l){
  clear();
  if(l.date == ""){
    cout << "No previous game found! Go play a match, dummy.\n\n";
    return;
  }

  cout << "Previous Game on " << l.date << "______________________\n\n";
  cout << "Player's Hand:\n";
  cout << left;
  for(int i = 0; i < l.player.drawn; i++){
    cout << setw(5) << l.player.cards[i] << endl;
  }
  cout << "Score: " << l.player.score % 10;
  if(l.player.score == 8 || l.player.score == 9){
    cout << " (Natural)";
  }

  cout << "\n\nDealer's Hand:\n";
  for(int i = 0; i < l.dealer.drawn; i++){
    cout << setw(5) << l.dealer.cards[i] << endl;
  }
  cout << "Score: " << l.dealer.score % 10;
  if(l.dealer.score == 8 || l.dealer.score == 9){
    cout << " (Natural)";
  }
  cout << "\n\nWINNER: " << l.winner << "\n";
  cout << "______________________\n\n";

  cout << "l.player.cards[0] = " << l.player.cards[0] << endl;
  cout << "l.dealer.cards[0] = " << l.dealer.cards[0] << endl; 
}

void clear(){
  cout << "\033[2J\033[1;1H";
}

void cleanup(Hand &hand){
  delete[] hand.cards;
  hand.cards = NULL;
  cout << "Hand cleaned up.\n";
}