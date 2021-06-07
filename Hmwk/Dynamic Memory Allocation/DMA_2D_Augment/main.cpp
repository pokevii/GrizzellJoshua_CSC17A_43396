#include <iostream>

using namespace std;
int **getData(int &,int &);//Get the Matrix Data
void printDat(const int * const *,int,int);//Print the Matrix
int **augment(const int * const *,int,int);//Augment the original array
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory

int main(){
	int **arr;
	int rows, cols;
    
    arr = getData(rows, cols);
    printDat(arr, rows, cols);
    arr = augment(arr, rows, cols);
    printDat(arr, rows, cols);
	return 0;
}

int **getData(int &rows,int &cols){
    cin >> rows >> cols;
    
    int** arr = new int* [rows];
    
    for(int r = 0; r < rows; r++){   
        arr[r] = new int[cols];
        for(int c = 0; c < cols; c++){
            cin >> arr[r][c];
        }
    }
    return arr;
}

void printDat(const int* const *arr,int rows,int cols){
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

int **augment(const int * const *arr,int rows,int cols){
    int** augArr = new int*[rows];
    
    for(int r = 0; r < rows; r++){
        augArr[r] = new int[cols];
        for(int c = 0; c < cols; c++){
            if(r == 0 || c == 0){
                augArr[r][c] = 0;
            } else {
                augArr[r][c] = arr[r-1][c-1];
            }
        }
    }
    
    return augArr;
}