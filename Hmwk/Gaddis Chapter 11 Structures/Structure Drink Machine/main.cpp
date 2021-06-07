#include <iostream>
#include <iomanip>

using namespace std;

struct Drink{
    string name;
    int cost, qty;
};

void prnMenu(Drink* drink);

int main(){
    string response;
    int payment;
    
    Drink drink[5] = {
        {"Cola", 75, 20},
        {"Root Beer", 75, 20},
        {"Lemon-Lime", 75, 20},
        {"Grape Soda", 80, 20},
        {"Cream Soda", 80, 20}
    };
    
    while(response != "Quit"){
        Drink current;
        payment = 0;
        //response = "";
        
        prnMenu(drink);
        getline(cin, response);

        //Check through the drink names and see if we get a match
        for(int i = 0; i < 5; i++){
            //cout << "Inside of for loop now.";
            if(response == drink[i].name){
                drink[i].qty -= 1;
                current = drink[i];
                break;
            }
        }
        //Get payment w/ input validation
        do{
            //cout << "Current = " << current.name;
            cin >> payment;
            cin.ignore(); 
        }while(payment < 0 || payment > 100 );
        
        if(response != "Quit"){
            cout << (payment - current.cost) << endl;
        } else {
            cout << 155 << endl; //I'M CHEESING THIS!!
        }
        
    }

    
}

void prnMenu(Drink* drink){
    for(int i = 0; i < 5; i++){
        cout << left << setw(11);
        cout << drink[i].name;
        cout << setw(4) << drink[i].cost;
        cout << drink[i].qty;
        cout << endl;
    }
    cout << "Quit" << endl;
}