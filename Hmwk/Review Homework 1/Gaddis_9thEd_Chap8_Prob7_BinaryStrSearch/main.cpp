#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

/*
 * 
 */
void stringSort(string names[], int arrSize);
bool binaryStrSearch(string names[], string srchName, int arrSize);

int main(int argc, char** argv) {
    //ew an all caps variable name! we don't like those
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
    "Griffin, Jim", "Stamey, Marty", "Rose, Geri", "Taylor, Terri", 
    "Johnson, Jill", "Allison, Jeff", "Looney, Joe", "Wolfe, Bill", "James, Jean",
    "Weaver, Jim", "Pore, Bob", "Rutherford, Greg", "Javens, Renee",
    "Harrison, Rose", "Setzer, Cathy", "Pike, Gordon", "Holland, Beth"};
    string name;
    
    //Sort the array of names.
    stringSort(names, NUM_NAMES);
    
    //Get the name from the user.
    cout << "Enter the name to search for: ";
    getline(cin, name);
    
    //Binary search the input name.
    if(binaryStrSearch(names, name, NUM_NAMES)){
        cout << name << " was found in the array.\n";
    } else {
        cout << name << " was not found in the array.\n";
    }
}

//I didn't learn how to do sorting, (I had Conrad) so I did honestly look this 
//up online. But hey, that's a pretty valuable skill to have as a coder: 
//knowing how to look stuff up correctly. I know the types of sorting and what
//they do, but not actually how to code them myself. I commented through the
//function to help me understand what it does.

void stringSort(string names[], int arrSize){
    //Sorts the names in ascending order.
    int minIndex;
    string firstName; //(this means the first name in the ARRAY, not their actual first name)
    
    //begin looping on each of the elements until the second to last one.
    for(int i = 0; i < arrSize - 1; i++){
        //initialize a couple variables here
        firstName = names[i];
        minIndex = i;
        
        //loop over all remaining elements of the array.
        for(int index = i+1; index < arrSize; index++){
            
            //check if the current string element is less than firstName
            if(names[index] < firstName){
                firstName = names[index];
                minIndex = index;
                
            }
        }
        //put the i element to its final position
        names[minIndex] = names[i];
        //put the lowest value first.
        names[i] = firstName;
    }
}
bool binaryStrSearch(string names[], string srchName, int arrSize){
    int index = 0, maxIndex = arrSize - 1, middle;
    
    while(index <= maxIndex){
        middle = (index + maxIndex) / 2;
        
        //if the middle index matches the searched name return true
        if(names[middle] == srchName){
            return true;
            
        //search the lower half of the array
        } else if (names[middle] > srchName){
        maxIndex = middle - 1;
        
        //search the upper half of the array
        } else {
            index = middle + 1;
        } 
    }
    //return false if the number is not found
    return false;
}