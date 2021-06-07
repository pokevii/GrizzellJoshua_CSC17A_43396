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

  cout << "Input the name of the input file: ";
  cin >> inName;

  cout << "Input the name of the output file: ";
  cin >> outName;

  inFile.open(inName, ios::in);
  outFile.open(outName, ios::out);
  
  while(!inFile.eof()){
    index = 0;
    getline(inFile, sentnce);

    while(sentnce[index] != '\0'){
      if(sentnce[index] == ' ' || sentnce[index] == '.'){
        cout << sentnce[index];
        outFile << sentnce[index];
        index++;
        continue;
      }
      
      sentnce[index] += 5;

      while(sentnce[index] < 65){
        sentnce[index] += 10;
      }
      while(sentnce[index] > 120){
        sentnce[index] -= 10;
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

  return 0;
}

