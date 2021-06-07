#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

using namespace std;

//Constants
const string suit[4] = {" of Clubs", " of Hearts", " of Spades", " of Diamonds"};
const string face[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
unsigned const int ms = 1000000;

//Structs
struct Hand{
  string cards[10];
  int drawn, score;
};

struct LastGame{
  Hand player;
  Hand dealer;
  string date, winner;
};

struct PlayerData{
  float money;
  char name[25];
  int wins, losses, ties, betWon, betLost;
  float gains;
};

//Global variables. They are not destroyed until the program ends.
//I know global variables are bad, but I need to use these in functions which cannot otherwise access them.
LastGame lastGame;
PlayerData pd;

//Functions
void play(bool mode);
float bet(LastGame l);
string drwCard();
int cardVal(string strCard);
void clear();
void dispLG(LastGame l);
bool repeat(int o, string card, string *outCard);
LastGame fillDat(Hand p, Hand d, int pScore, int dScore);
PlayerData newData();
void dispDat(PlayerData pd);
void delDat(PlayerData pd);

//Main function
int main() {
  fstream file;

  //cout << "Opening file.";
  file.open("data.dat", ios::in | ios::binary);
  if(file.fail()) { 
    pd = newData();
  } else {
    file.read(reinterpret_cast<char *>(&pd.money), sizeof(pd.money));
    file.read(reinterpret_cast<char *>(&pd.name), sizeof(pd.name));
    file.read(reinterpret_cast<char *>(&pd.wins), sizeof(pd.wins));
    file.read(reinterpret_cast<char *>(&pd.losses), sizeof(pd.losses));
    file.read(reinterpret_cast<char *>(&pd.ties), sizeof(pd.ties));
    file.read(reinterpret_cast<char *>(&pd.gains), sizeof(pd.gains));
    cout << "Welcome back to Baccarat, " << pd.name << "!\n";
  }
  file.close();

  int menuNum;

  cout << "Version 5: THE FINAL UPDATE!\n\n";
  do{
    srand(time(NULL));
    cout << "Balance: $" << fixed << setprecision(2) << pd.money << endl;
    cout << "1: [For Fun] Play a game of Baccarat.\n2: [For Glory] Put some money down!\n3: View post-game statistics.\n4: View your statistics.\n5: Delete save data.\n6+: Save and Exit\n";
    cin >> menuNum;
    switch(menuNum){
      case 1: play(0);
      break;
      case 2: pd.money = bet(lastGame);
      break;
      case 3: dispLG(lastGame);
      break;
      case 4: dispDat(pd);
      break;
      case 5: delDat(pd);
      break;
      default: break;
    }
  }while(menuNum < 5);
  //Return without saving if delDat was called
  if(menuNum == 5){
    return 1;
  }
  //Save by default
  file.open("data.dat", ios::out | ios::binary);
  file.write(reinterpret_cast<char *>(&pd.money), sizeof(pd.money));
  file.write(reinterpret_cast<char *>(&pd.name), sizeof(pd.name));
  file.write(reinterpret_cast<char *>(&pd.wins), sizeof(pd.wins));
  file.write(reinterpret_cast<char *>(&pd.losses), sizeof(pd.losses));
  file.write(reinterpret_cast<char *>(&pd.ties), sizeof(pd.ties));
  file.write(reinterpret_cast<char *>(&pd.gains), sizeof(pd.gains));
  file.close();
  
}

//Takes "mode" param; 0 = for fun, 1 = betting.
void play(bool mode){
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
    usleep(0.2 * ms);
  }while (c < 2 || pScore < 5);
  //Transfer the score and cards into their struct.
  pHand.score = pScore;
  pHand.drawn = c;
  for(int i = 0; i < c; i++){
    pHand.cards[i] = pCard[i];
  }
  usleep(ms);
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
    usleep(0.2 * ms);
  }while (c < 2 || dScore < 5);
  dHand.score = dScore;
  dHand.drawn = c;
  for(int i = 0; i < c; i++){
    dHand.cards[i] = dCard[i];
  }
  usleep(ms);
  //Calculate final score; numbers 10 or higher get the first digit lopped off.
  pScore %= 10;
  dScore %= 10;
  cout << "\nPlayer's Score: " << pScore << endl;
  cout << "Dealer's Score: " << dScore << "\n\n";
  //If mode == 0, add wins/losses to playerdata.
  if(mode == 0){
    if(pScore > dScore){
      pd.wins++;
    } else if (pScore < dScore){
      pd.losses++;
    } else {
      pd.ties++;
    }
  }

  lastGame = fillDat(pHand, dHand, pScore, dScore);
  cout << "__________________________________\n\n";
}

float bet(LastGame l){
  float wins, wager;
  int betVal = 0;
  float money = pd.money;

  if(money == 0){
    cout << "Hey, you have no money! Giving a starting value of $1000.\n";
    money = 1000.00;
  }
  
  do{
    clear();
    cout << "Balance: $" << fixed << setprecision(2) << pd.money << "\n\n";
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
    }
  }while(betVal > 3 || betVal < 1);

  //Make sure that the user can't bet more than they have.
  do{
    cin >> wager;
  }while(wager > pd.money);

  play(1);
  l = lastGame;

  switch(betVal){
    case 1: if(l.winner == "Player"){
      money += wager*2;
      money -= wager;
      pd.gains += (wager*2 - wager);
      pd.betWon++;
      cout << "\nYou've won your bet! Your wager of $" << wager << " has been DOUBLED! ($" << wager*2 << ")\n";
    } else {
      money -= wager;
      pd.betLost++;
      cout << "\nYou've lost your bet, and with it, your $" << wager << "...\n";
    }
    break;
    case 2: if(l.winner == "Dealer"){
      money += wager*2;
      money -= wager;
      pd.gains += (wager*2 - wager);
      pd.betWon++;
      cout << "\nYou've won your bet! Your wager of $" << wager << " has been DOUBLED! ($" << wager*2 << ")\n";
    } else {
      money -= wager;
      pd.betLost++;
      cout << "\nYou've lost your bet, and with it, your $" << wager << "...\n";
    }
    break;
    case 3: if(l.winner == "Tie"){
      money += wager*8;
      money -= wager;
      pd.gains += (wager*8 - wager);
      pd.betWon++;
      cout << "\nYou've won your bet! Your wager of $" << wager << " has been OCTUPLED! ($" << wager*8 << ")\n";
    } else {
      money -= wager;
      pd.betLost++;
      cout << "\nYou've lost your bet, and with it, your $" << wager << "...\n";
    }
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

void dispLG(LastGame l){
  clear();
  if(l.date == ""){
    cout << "No previous game found! Go play a match, dummy.\n\n";
    return;
  }

  cout << "=========================\n";
  cout << "Previous Game on " << l.date << endl;
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
  cout << "=========================\n\n";
}

void clear(){
  cout << "\033[2J\033[1;1H";
}

PlayerData newData(){
  PlayerData pd;

  cout << "Welcome to Baccarat! It must be your first time playing.\n";
  cout << "What would your name be? (One word, please!): ";
  cin >> pd.name;
  cout << "Well, nice to meet you, " << pd.name << "!\n";
  cout << "Since you're new here, how about I give you $1000?\n";
  cout << "On the house, of course. Gamble responsibly!\n(press enter to continue)\n";
  cin.ignore(); //Need two here because of the cin
  cin.ignore();
  pd.money = 1000.00;
  pd.losses = 0;
  pd.wins = 0;
  pd.gains = 0.0f;
  pd.ties = 0;
  pd.betWon = 0;
  pd.betLost = 0;
  clear();

  return pd;
}

void dispDat(PlayerData pd){
  float ratio;
  float betRtio;
  ratio = float(pd.wins) / float(pd.losses);
  betRtio = float(pd.betWon) / float(pd.betLost);
  clear();
  cout << "=========================\n";
  cout << pd.name << "'s Baccarat Profile\n\n";
  cout << "WINS: " << pd.wins << endl;
  cout << "LOSSES: " << pd.losses << endl;
  cout << "TIES: " << pd.ties << endl;
  cout << "W/L RATIO: " << ratio << "\n\n";
  cout << "BETS WON: " << pd.betWon << endl;
  cout << "BETS LOST: " << pd.betLost << endl;
  cout << "W/L RATIO: " << betRtio << "\n\n";
  cout << "TOTAL PROFITS: $" << pd.gains << endl; 
  cout << "=========================\n\n";
}

void delDat(PlayerData pd){
  char c;
  cout << "Hey, " << pd.name << ", we'll be sad to see you go.\n";
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