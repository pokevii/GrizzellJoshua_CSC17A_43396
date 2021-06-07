// Implementation for retail.h
#include <iostream>
#include <iomanip>
#include "RetailItem.h"
using namespace std;

void RetailItem::crtItem(){
    RetailItem item1("Jacket", 12, 59.95);
    RetailItem item2("Designer Jeans", 40, 34.95);
    RetailItem item3("Shirt", 20, 24.95);

    cout << setw(16) << left << "Description" << setw(8) << "Stock" << setw(5) << "Price\n";
    cout << setw(16) << item1.desc << setw(8) << item1.stock << setw(8) << item1.cost << endl;
    cout << setw(16) << item2.desc << setw(8) << item2.stock << setw(8) << item2.cost << endl;
    cout << setw(16) << item3.desc << setw(8) << item3.stock << setw(8) << item3.cost << endl;
}