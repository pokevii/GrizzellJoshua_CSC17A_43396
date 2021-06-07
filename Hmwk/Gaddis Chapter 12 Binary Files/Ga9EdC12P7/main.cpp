#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  string sentnce;
  int index = 0;
  fstream inFile;
  fstream outFile;
  string inName;
  string outName;

  cout << "Input the name of the file you would like to open: ";
  cin >> inName;

  cout << "Input the name of the file you would like to output to: ";
  cin >> outName;

  inFile.open(inName, ios::in);
  outFile.open(outName, ios::out);
  
  while(!inFile.eof()){
    index = 0;
    getline(inFile, sentnce);

    while(sentnce[index] != '\0'){
      if(sentnce[index-2] != '.' && index != 0){
        if(sentnce[index] > 64)
        sentnce[index] += 32;
      }
      cout << sentnce[index];
      outFile << sentnce[index];
      index++;
    }
    outFile << '\n';
    cout << endl;
  }
  
  inFile.close();
  outFile.close();
  
  cout << "\nInput successfully modified!" << endl;

  return 0;
}

