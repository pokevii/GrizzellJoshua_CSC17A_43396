#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

struct Prime{
	unsigned short prime;
	unsigned char power;
};

struct Primes{
	unsigned char nPrimes;
	Prime *prime;
};

Primes *factor(int); // Input an integer, return all prime factors
void prntPrm(Primes *); // Output all prime factors

void problem7(){
  int num;
  do{
    cout << "Input a number to get its prime factors: ";
    cin >> num;
    cout << endl;
  }while(num < 2 || num > 10000);

  Primes *primes = factor(num);
  prntPrm(primes);
  
}

Primes *factor(int num){
    //I'm not sure how to dynamically size this array... :( 
  Prime *p = new Prime[5];
  int count = 0;
  unsigned char nPrimes = 0;
  unsigned char power = 0;

  cout << "Original Number: " << num << endl;
  while(num % 2 == 0){
    //cout << "(" << num << "/" << 2 << ") " << num/2 << endl;
    num /= 2;
    power++;
    p[0] = {2, power};
  }

  //Increase count so we don't overwrite p[0] in the next for loop.
  if(p[0].prime == 2){
    //cout << "p[0].prime is 2! Increasing count...";
    count++;
  }

  //I looked it up, and we can actually do i+2 here instead of i++.
  //Putting i+2 in the for loop skips all even numbers, so it's faster!
  for(unsigned short i = 3; i <= num; i = i+2){
    power = 0;
    while(num % i == 0){
      //cout << "(" << num << "/" << i << ") " << num/i << endl;
      num /= i;
      power++;
    }
    if(power != 0){
      p[count] = {i, power};
      count++;
      nPrimes++;
    }
  }

  Primes *primes = new Primes{nPrimes, p};
  return primes;
}

void prntPrm(Primes *p){

  cout << "Primes: ";
  for(int i = 0; i <= p->nPrimes; i++){
    cout << int(p->prime[i].prime) << "^" << int(p->prime[i].power);
    if(i != p->nPrimes){
      cout << ", ";
    }
  }
  cout << "\n\n";
}