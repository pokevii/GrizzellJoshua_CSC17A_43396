#include <iostream>
#include <iomanip>
using namespace std;

struct Division {
    string name;
    float qSales[4], annSale, avgSale; 
};

void getData(Division d);

int main(int argc, char** argv) {
    Division eastDv = {"East"}, 
        westDv = {"West"}, 
        northDv = {"North"}, 
        southDv = {"South"};

    getData(northDv);
    cout << endl;
    getData(westDv);
    cout << endl;
    getData(eastDv);
    cout << endl;
    getData(southDv);

    return 0;
}

void getData(Division d){
    float sum = 0.0;
    string order[4] = {"first-quarter", "second-quarter", "third-quarter", "fourth-quarter"};

    cout << d.name << endl;
    
    for(int i = 0; i < 4; i++){
        cout << "Enter " << order[i] << " sales:";
        do{
            cin >> d.qSales[i];
        } while (d.qSales[i]<0);
        sum += d.qSales[i];
        cout << endl;
    }
    
    cout << fixed  << showpoint << setprecision(2);
    cout << "Total Annual sales:$" << sum << endl;
    cout << "Average Quarterly Sales:$" << sum / 4.0;
}