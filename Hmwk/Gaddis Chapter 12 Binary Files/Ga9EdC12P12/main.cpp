#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

struct Division{
  string name;
  int quarter;
  float sales[4];
};

int main(int argc, char** argv) {
  Division division[4];
  string divName[4] = {"East", "West", "North", "South"};
  string order[4] = {"first", "second", "third", "fourth"};
  fstream file;

  cout << "Searching for data.dat file.\n";
  file.open("data.dat", ios::in | ios::out);

  //If no file is found, go through the process of Problem 11
  if(file.fail()){
    cout << "File not found. Creating new file.\n\n----\n\n";
    file.close();

    for(int i = 0; i < 4; i++){
      division[i].name = divName[i];
      division[i].quarter = i+1;
      for(int j = 0; j < 4; j++){
        do{
          cout << "Enter " << division[i].name << " division's sales for the " << order[j] << " quarter.\n";
          cin >> division[i].sales[j];
        }while(division[i].sales[j] < 0);
      }
    }

    file.open("data.dat", ios::out | ios::binary);

    for(int i = 0; i < 4; i++){
      file << fixed << setprecision(2);
      for(int j = 0; j < 4; j++){
        file.write(reinterpret_cast<char *>(&division[i].sales[j]), sizeof(division[i].sales[j]));
      }
    }
    file.close();
    cout << "Data successfully output to file data.dat.\n";
    cout << "Re-run the program to begin data processing.\n\n";
    return 2;
  } //End of file creation.

  else {
    cout << "data.dat found.\n";
    cout << fixed << setprecision(2);

    float total = 0;
    float total2 = 0;
    float lowest = 100000, lowQ = 0;
    float highest = -100000, highQ = 0;

    //read in data!
    for(int i=0; i<4; i++){
      for(int j=0; j<4; j++){
        file.read(reinterpret_cast<char *>(&division[i].sales[j]), sizeof(division[i].sales[j]));
      }
      division[i].quarter = i+1;
    }

    //Corporate sales per quarter
    for(int i = 0; i < 4; i++){
      cout << "Total corporate sales for the " << order[i] << " quarter: $";
      for(int j = 0; j < 4; j++){
        total += division[j].sales[i];
      }
      if(total > highest){
        highest = total;
        highQ = division[i].quarter;
      }
      if(total < lowest){
        lowest = total;
        lowQ = division[i].quarter;
      }
      cout << total << endl;
      total = 0;
    }
    cout << '\n';

    //Total yearly sales for each division
    for(int i = 0; i < 4; i++){
      cout << "Total yearly sales for " << divName[i] << " division: $";
      for(int j = 0; j < 4; j++){
        total += division[i].sales[j];
        total2 += division[i].sales[j];
      }
      cout << total << endl;
      total = 0;
    }

    //Total yearly corporate sales
    cout << "\nTotal yearly corporate sales: $" << total2 << endl;
    total2 = 0;

    //Average quarterly sales for the divisions
    for(int i=0; i<4; i++){
      cout << "\nAverage quarterly sales for " << divName[i] << " division: $";
      for(int j=0; j<4; j++){
        total += division[i].sales[j];
      }
      total /= 4;
      cout << total;
      total = 0;
    }

    //The highest and lowest quarters for the corporation
    cout << "\n\nHighest quarter: Q" << setprecision(0) << highQ << " - $" << setprecision(2) << highest;
    cout << "\nLowest quarter: Q" << setprecision(0) << lowQ << " - $" << setprecision(2) << lowest;
  }
}
