#include <iostream>
#include <iomanip>
#include "LastGame.h"
using namespace std;

void LastGame::dispLG(){
  //If there's no date for the last game, there was no last game.
  if(date == ""){
    cout << "No previous game found! Go play a match, dummy.\n\n";
    return;
  }

  //Display the date of the previous game.
  cout << "=========================\n";
  cout << "Previous Game on " << date << endl;

  //Display the data of the player's hand.
  cout << "Player's Hand:\n";
  cout << left;
  for(int i = 0; i < player.getDrwn(); i++){
    cout << setw(5) << player.getCard(i) << endl;
  }
  //If the score is an 8 or 9, without having been modified, it is a natural.
  cout << "Score: " << player.getScre() % 10;
  if(player.getScre() == 8 || player.getScre() == 9){
    cout << " (Natural)";
  }

  //Display the data of the dealer's hand.
  cout << "\n\nDealer's Hand:\n";
  for(int i = 0; i < dealer.getDrwn(); i++){
    cout << setw(5) << dealer.getCard(i) << endl;
  }
  cout << "Score: " << dealer.getScre() % 10;
  if(dealer.getScre() == 8 || dealer.getScre() == 9){
    cout << " (Natural)";
  }
  //Display the winner.
  cout << "\n\nWINNER: " << winner << "\n";
  cout << "=========================\n\n";
}

void LastGame::fillDat(Hand p, Hand d){
  //time_t is a struct from the time class.
  time_t curTime;
  time(&curTime);

  player = p;
  dealer = d;

  //Check who has the greater score. They are the winner.
  if(player.getScre() > dealer.getScre()){
    cout << "PLAYER WINS!\n\n";
    winner = "Player";
  } else if (dealer.getScre() > player.getScre()){
    cout << "DEALER WINS!\n\n";
    winner = "Dealer";
  } else {
    cout << "TIE!!!\n\n";
    winner = "Tie";
  }

  //Get current time.
  date = ctime(&curTime);
}

