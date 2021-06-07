#include <iostream>

using namespace std;
int **getData(int &,int &);                 //Return the 2-D array and its size.
void prntDat(const int* const *,int,int);   //Print the 2-D Array
void destroy(int **,int,int);               //Deallocate memory
int sum(const int * const *, int,int);      //Return the Sum


int main(){
	int** arr;
	int rows, cols, arrSum;
	arr = getData(rows, cols);
	prntDat(arr, rows, cols);
	arrSum = sum(arr, rows, cols);
	cout << arrSum;
	return 0;
}

int **getData(int &rows,int &cols){
    cin >> rows >> cols;
    
    int** arr = new int* [rows];    //Took this from the github lol
    
    for(int r = 0; r < rows; r++){   
        arr[r] = new int[cols];
        for(int c = 0; c < cols; c++){
            cin >> arr[r][c];
        }
    }
    return arr;
}

//I have no idea what const int* const means. But hey, I'll just go with it for now.
void prntDat(const int* const *arr,int rows,int cols){
    //cout << rows << " " << cols << endl;
    
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            cout << arr[r][c];
            if(c != cols-1){
                cout << " ";
            }
        }
        cout << endl;
    }
}

void destroy(int **arr,int rows,int cols){
    delete[] arr;
}

int sum(const int * const *arr, int rows,int cols){
    int result;
    
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            result += arr[r][c];
        }
    }
    
    return result;
}