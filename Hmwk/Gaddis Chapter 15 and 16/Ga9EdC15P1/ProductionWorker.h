#include "Employee.h"
using namespace std;

class ProductionWorker : public Employee{
  private:
    int shift;
    float payRate;
  public:
    ProductionWorker(int s, float rate){
      shift = s;
      payRate = rate;
      
    }
    int getShft() { return shift; }
    float getPyRt() { return payRate; }
    void setShft(int s) { shift = s; }
    void setPyRt(float rate) { payRate = rate; }

    void crtEmp(string name, string date, int ID);
    void prnEmp();
};