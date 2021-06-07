#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

void arrayToFile(string name, int *arr, int arrSize);
void fileToArray(string name, int *arr, int arrSize);

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
    file << endl;
  }
  file.close();
  cout << "Data successfully output to file data.dat.";
  return 0;
}