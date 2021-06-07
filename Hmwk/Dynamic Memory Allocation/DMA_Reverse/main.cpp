#include <iostream>

using namespace std;
int *getData(int &);               //Fill the array
int *sort(const int *,int);         //Sort smallest to largest
int *reverse(const int *,int);  //Sort in reverse order
void prntDat(const int *,int); //Print the array

int main(){
    int *array;
    int arrSize;
    cin >> arrSize;
    array = getData(arrSize);       //Read in data
    array = sort(array, arrSize);   //Sort array
    prntDat(array, arrSize);
    cout << endl;
    array = reverse(array, arrSize);
    prntDat(array, arrSize);
	return 0;
}

int *getData(int &arrSize){
    int *array = new int[arrSize];
    for(int i = 0; i < arrSize; i++){
        cin >> array[i];
    }
    return array;
}

int *sort(const int *arr,int arrSize){
    int *arrSort = new int[arrSize];
    
    for(int i = 0; i < arrSize; i++){
        arrSort[i] = arr[i];
    }
    
    for(int i = 0; i < arrSize-1; i++){
        for(int j = i+1; j < arrSize; j++){
            if(arrSort[i] > arrSort[j]){
                arrSort[i] = arrSort[i]^arrSort[j];
                arrSort[j] = arrSort[i]^arrSort[j];
                arrSort[i] = arrSort[i]^arrSort[j];
            }
        }
    }
    return arrSort;
}

int *reverse(const int *arr,int arrSize){
    int *arrRev = new int[arrSize];
    for(int i = 0; i < arrSize; i++){
        arrRev[i] = arr[i];
    }
    
    for(int i = 0; i < arrSize-1; i++){
        for(int j = i+1; j < arrSize; j++){
            if(arrRev[i] < arrRev[j]){
                arrRev[i] = arrRev[i]^arrRev[j];
                arrRev[j] = arrRev[i]^arrRev[j];
                arrRev[i] = arrRev[i]^arrRev[j];
            }
        }
    }
    return arrRev;
}

void prntDat(const int *array,int arrSize){
    for(int i = 0; i < arrSize; i++){
        cout << array[i];
        if(i != arrSize-1){
            cout << " ";
        }
    }
}