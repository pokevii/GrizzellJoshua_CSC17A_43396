#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

int *encrypt(int *arr);
int *decrypt(int *arr);

/*          
*   PROBLEM 4
*/   

void problem4(){
  int num;
  int digit[4];
  bool confirm = true;
  int response;

  do{
    cout << "Type 1 to encrypt a number. Type 2 to decrypt a number: ";
    cin >> response;
  }while(response > 2 || response < 1);

  do{
    do{
      cout << "Enter a number (digits must be from 0 to 7): ";
      cin >> num;
    }while(num > 9999);
    
    digit[0] = ((num / 1000) % 100);
    digit[1] = ((num / 100) % 10);
    digit[2] = ((num / 10) % 10);
    digit[3] = num % 10;

    for(int i = 0; i <= 3; i++){
      if(digit[i] == 8 || digit[i] == 9){
        cout << "Invalid number in digit " << i+1 << "!\n"; 
        confirm = false;
        break;
      } else {
        confirm = true;
      }
    }
  } while(confirm == false);
  
  if(response == 1){
    int* modNum = encrypt(digit);
    cout << "Encrypted code: ";
    for(int i = 0; i <= 3; i++){
      cout << modNum[i];
    }
  }  else if(response == 2) {
    int* modNum = decrypt(digit);
    cout << "Decrypted number: ";
    for(int i = 0; i <= 3; i++){
      cout << modNum[i];
    }
  }
  cout << endl;
}

int *encrypt(int *arr){
  int temp;
  int* modArr = new int[4];

  for(int i = 0; i <= 3; i++){
    modArr[i] = arr[i];
  }

  for(int i = 0; i <= 3; i++){
    modArr[i] = (modArr[i] + 5) % 8;
  }

  temp = modArr[0];
  modArr[0] = modArr[2];
  modArr[2] = temp;

  temp = modArr[1];
  modArr[1] = modArr[3];
  modArr[3] = temp;

  return modArr;
}

int *decrypt(int *arr){
  int temp;
  int* modArr = new int[4];

  for(int i = 0; i <= 3; i++){
    modArr[i] = arr[i];
  }

  for(int i = 0; i <= 3; i++){
    modArr[i] = (modArr[i] - 5) % 8;
    if(modArr[i] < 0){
      modArr[i] += 8;
    }
  }

  temp = modArr[0];
  modArr[0] = modArr[2];
  modArr[2] = temp;

  temp = modArr[1];
  modArr[1] = modArr[3];
  modArr[3] = temp;

  return modArr;
}