#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

void arrayToFile(string name, int *arr, int arrSize);
void fileToArray(string name, int *arr, int arrSize);

int main(int argc, char** argv) {
  const int arrSize = 50;
  int *arr = new int[arrSize];

  string file;
  cout << "Input the name of a file: ";
  cin >> file;
  cout << '\n';

  int n;
  do{
  cout << "1. Input contents of array into file.\n2. Output contents of file into array.\n3+: Exit\n\n";
  cin >> n;
    switch(n){
    case 1: srand(time(NULL));
    for(int i = 0; i < arrSize; i++){
    arr[i] = rand() % 9 + 1;
    }
    arrayToFile(file, arr, arrSize);
    break;
    case 2: fileToArray(file, arr, arrSize);
    break;
    default: break;
    }
  }while(n > 0 && n < 3);

  return 0;
}

void arrayToFile(string name, int *arr, int arrSize){
  fstream inFile;
  
  inFile.open(name, ios::out | ios::binary);
  cout << "Writing array to the file...\n";
  for(int i = 0; i < arrSize; i++){
    inFile.write(reinterpret_cast<char *>(&arr[i]), sizeof(arr[i]));
  }
  inFile.close();
  cout << "Done!\n\n";
}

void fileToArray(string name, int *arr, int arrSize){
  fstream outFile;
  outFile.open(name, ios::in | ios::binary);
  cout << "Writing contents of the file into the array...\n";
  for(int i = 0; i < arrSize; i++){
      
    outFile.read(reinterpret_cast<char *>(&arr[i]), sizeof(arr[i]));
    if(i % 10 == 0){
      cout << '\n';
    }
    cout << arr[i] << " ";
  }
  cout << "\n\nDone!\n\n";
}
