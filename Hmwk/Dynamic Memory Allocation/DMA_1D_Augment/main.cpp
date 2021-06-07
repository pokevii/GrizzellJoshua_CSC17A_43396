#include <iostream>

using namespace std;

int *getData(int &);//Read the array
int *augment(const int *,int);//Augment and copy the original array
void prntAry(const int *,int);//Print the array

int main(){
	int* arr;
	int arrSize;
	cin >> arrSize;
	arr = getData(arrSize);
	prntAry(arr, arrSize);
	cout << endl;
	
	arr = augment(arr, arrSize);
	prntAry(arr, arrSize+1);
	return 0;
}

int *getData(int &arrSize){
    int* arr = new int[arrSize];
    for(int i = 0; i < arrSize; i++){
        cin >> arr[i];
    }
    
    return arr;
}

int *augment(const int *arr,int arrSize){
    int* augAry = new int[arrSize+1];
    augAry[0] = 0;
    for(int i = 0; i < arrSize+1; i++){
        augAry[i+1] = arr[i];
    }
    return augAry;
}

void prntAry(const int *arr,int arrSize){
    for(int i = 0; i < arrSize; i++){
        cout << arr[i];
        if(i != arrSize-1){
            cout << " ";
        }
    }
}