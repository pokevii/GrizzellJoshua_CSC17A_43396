#include <iostream>
#include <iomanip>
using namespace std;

int *getData(int &);         //Return the array size and the array
void prntDat(int *,int);    //Print the integer array
float *median(int *,int);  //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *);     //Print the median Array

int main(){
	int arySize; 
	cin >> arySize;
	int *array = getData(arySize);  //Read in the array data.
	prntDat(array, arySize);        //Output the array.
	float *medArr = median(array, arySize);
	prntMed(medArr);
	return 0;
}

int *getData(int &size){
    int *arr = new int[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    return arr;
}         

void prntDat(int *array,int size){
    for(int i = 0; i < size; i++){
        cout << array[i];
        if(i != size-1){
            cout << " ";
        }
    }
    cout << endl;
}

float *median(int *array,int arySize){
    float result = 0, sum = 0, count = 0;
    float *medArr = new float[arySize+2];
    
    for(int i = 0; i < arySize; i++){
        ++count;
        sum += array[i];
        medArr[i+2] = array[i];
    }
    
    //cout << sum << "/" << count << " = " << sum/count << endl;
    result = sum / count;
    medArr[0] = count + 2;
    medArr[1] = result;
    return medArr;
}

void prntMed(float *medArr){
    cout << medArr[0];
    cout << setprecision(2) << fixed;
    for(int i = 1; i < medArr[0]; i++){
        cout << " " << medArr[i];
    }
}