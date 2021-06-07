class Inventory{
  private:
    int itemNumber;
    int quantity;
    double cost;
    double totalCost;
  public:
    Inventory(int i, int q, double c){
      itemNumber = i;
      quantity = q;
      cost = c;
      totalCost = c * q;
    }
    Inventory(){
      itemNumber = 0;
      quantity = 0;
      cost = 0;
      totalCost = 0;
    }
    
    void setItemNumber(int i) { itemNumber = i; }
    void setQuantity(int q) { quantity = q; }
    void setCost(double c) { cost = c; }
    void setTotalCost(double t) { totalCost = t; }
    int getItemNumber() { return itemNumber; }
    int getQuantity() { return quantity; }
    double getCost() { return cost; }
    double getTotalCost() { return totalCost; }
};