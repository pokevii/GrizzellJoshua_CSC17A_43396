#include <iostream>
#include <iomanip>
using namespace std;

struct MovieData{
    string title, directr;
    int year, runtime;
};

MovieData *getData(int &size);
void prntDat(MovieData* md, int size);

int main(){
    int size;
    cout << "This program reviews structures\n";
    cout << "Input how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes).\n";
    cin >> size;
    
    MovieData *md = getData(size);
    prntDat(md, size);
    
    //your code here
	return 0;
}

MovieData *getData(int &size){
    MovieData *md = new MovieData[size];
    
    for(int i = 0; i < size; i++){
        cin.ignore();  //We have to use cin.ignore() so getline will ignore leading whitespace.
        getline(cin, md[i].title); 
        getline(cin, md[i].directr); 
        cin >> md[i].year;
        cin >> md[i].runtime;
    }
    
    return md;
}

void prntDat(MovieData* md, int size){
    for(int i = 0; i < size; i++){
        cout << endl;
        cout << left << setw(11) << "Title:" << md[i].title << endl;
        cout << setw(11) << "Director:" << md[i].directr << endl;
        cout << setw(11) << "Year:" << md[i].year << endl;
        cout << setw(11) << "Length:" << md[i].runtime << endl;
    }
}