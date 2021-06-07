#include <iostream>
using namespace std;

class RetailItem{
    private:
        string desc;
        int stock;
        float cost;
    public:
    RetailItem(string d, int s, float c){
        desc = d; stock = s; cost = c;
    }
    RetailItem(){
        desc = ""; stock = 0; cost = 0.0;
    }
    
    void crtItem();
    string getDesc(){return desc;}
    int getStock(){return stock;}
    float getCost(){return cost;}
};