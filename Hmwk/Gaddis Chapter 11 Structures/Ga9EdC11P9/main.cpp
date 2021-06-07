/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: grizz
 *
 * Created on April 6, 2021, 10:37 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;

struct Speaker{
    string name, topic;
    int phone, fee;
};

Speaker *getData(int size);
void dispDat(Speaker* s, int size);

int main(int argc, char** argv) {
    int size = 2, index;
    char response;
    cout << "Input the name of the speaker, their phone number, topic, and fee.\n";
    Speaker *s = getData(size);

    dispDat(s, size);
    while(true){
        cout << "Would you like to change any data? (Y/N): ";
        cin >> response;
        cout << endl;
        
        if(response == 'n' || response == 'N'){
            break;
        }
        
        cout << "Enter the index to modify: ";
        cin >> index;

        for(int i = 0; i < size; i++){
            if(index == i){
                cout << "Speaker " << i+1 << endl <<"Name: ";
                cin >> s[i].name;
                cout << endl << "Phone Number: ";
                cin >> s[i].phone;
                cout << endl << "Speaking Topic: ";
                cin >> s[i].topic;
                cout << endl << "Fee Required: ";
                cin >> s[i].fee;
                cout << endl;
                cout << "Index " << i << " successfully modified." << endl;
            }
        }
        dispDat(s, size);
    }

    return 0;
}

Speaker *getData(int size){
    Speaker* s = new Speaker[size];
    
    for(int i = 0; i < size; i++){
        cout << "Speaker " << i+1 << endl <<"Name: ";
        cin >> s[i].name;
        cout << endl << "Phone Number: ";
        cin >> s[i].phone;
        cout << endl << "Speaking Topic: ";
        cin >> s[i].topic;
        cout << endl << "Fee Required: ";
        cin >> s[i].fee;
        cout << endl;
    }
    
    return s;
}

void dispDat(Speaker* s, int size){
    cout << "Index | Name       | Phone     | Topic     | Fee" << endl;
    cout << "------------------------------------------------" << endl;
    for(int i = 0; i < size; i++){
        cout << left << setw(7) << i << setw(13) << s[i].name << setw(12) << 
                s[i].phone << setw(12) << s[i].topic << s[i].fee << endl; 
    }
    cout << "------------------------------------------------" << endl;
}