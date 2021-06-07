#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct Weather{
    string month;
    int hiTemp, loTemp, rain;
    float avgTemp;
};

Weather getData(Weather* w);
void findHi(Weather* w);
void findLo(Weather* w);
void findAvg(Weather* w);
void tempAvg(Weather* w);

int main(){
    Weather w[12];
    getData(w);
    
    findAvg(w);
    findLo(w);
    findHi(w);
    tempAvg(w);
    
	return 0;
}

Weather getData(Weather* w){
    for(int i = 0; i < 12; i++){
        cin >> w[i].month >> w[i].rain >> w[i].loTemp >> w[i].hiTemp;
        w[i].avgTemp = (w[i].loTemp + w[i].hiTemp) / 2;
    }
    
    /*
    for(int i = 0; i < 12; i++){
        cout << setw(9) << left << w[i].month << setw(3) << w[i].rain << setw(3) << w[i].loTemp << right << setw(3) << w[i].hiTemp << endl;
    }
    */
    
    return *w;
}

void findHi(Weather* w){
    int highest = -10000;
    string hiMonth;
    
    for(int i = 0; i < 12; i++){
        if(w[i].hiTemp > highest){
            highest = w[i].hiTemp;
            hiMonth = w[i].month;
        }
    }
    
    cout << "Highest Temperature " << hiMonth << "  " << highest << " Degrees Fahrenheit" << endl;
}

void findLo(Weather* w){
    int lowest = 10000;
    string loMonth;
    
    for(int i = 0; i < 12; i++){
        if(w[i].loTemp < lowest){
            lowest = w[i].loTemp;
            loMonth = w[i].month;
        }
    }
    
    cout << "Lowest  Temperature " << loMonth << "  " << lowest << " Degrees Fahrenheit" << endl;
}

void findAvg(Weather* w){
    float sum = 0;
    
    for(int i = 0; i < 12; i++){
        sum += w[i].rain;
    }
    
    cout << fixed << showpoint << setprecision(1);
    cout << "Average Rainfall " << sum / 12 << " inches/month" << endl;
}

void tempAvg(Weather* w){
    float tempSum = 0;
    
    
    for(int i = 0; i < 12; i++){
        tempSum += w[i].hiTemp;
        tempSum += w[i].loTemp;
    }
    
    cout << noshowpoint << setprecision(0);
    cout << "Average Temperature for the year " << round(tempSum / 24.0) << " Degrees Fahrenheit" << endl;
}