#include <iostream>
#include <iomanip>
#include "Inventory.cpp"
using namespace std;

int main() {
  Inventory inv;
  cout << "Inventory 1:\n  Item Number: #" << inv.getItemNumber();
  cout << "\n  Quantity: " << inv.getQuantity();
  cout << "\n  Cost: $" << setprecision(2) << fixed << inv.getCost();
  cout << "\n  Total Cost: $" << inv.getTotalCost();
  
  int i, q; 
  double c, t;
  cout << "\n\nNow it's your turn!\nInput item number: ";
  cin >> i;
  cout << "Input quantity: ";
  cin >> q;
  cout << "Input cost: ";
  cin >> c;
  Inventory inv2(i, q, c);
  cout << "\nInventory 2:\n  Item Number: #" << inv2.getItemNumber();
  cout << "\n  Quantity: " << inv2.getQuantity();
  cout << "\n  Cost: $" << setprecision(2) << fixed << inv2.getCost();
  cout << "\n  Total Cost: $" << inv2.getTotalCost() << endl;
}