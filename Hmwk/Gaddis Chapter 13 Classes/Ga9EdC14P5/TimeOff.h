#include <iostream>
using namespace std;

class TimeOff{
  private:
    string empName;
    int empID;

    NumDays sickTaken;
    NumDays vacTaken;
    NumDays unpaidTaken;
    NumDays maxSickDays;
    NumDays maxVacation;
    NumDays maxUnpaid;
  public:
    //Constructors (i think i made too many)
    TimeOff(string name, int ID, NumDays sick, NumDays vac, NumDays unpaid, NumDays mSick, NumDays mVac, NumDays mUnpaid){
      empName = name;
      empID = ID;

      sickTaken = sick;
      vacTaken = vac;
      unpaidTaken = unpaid;
      maxSickDays = mSick;
      if(mVac > 240) mVac = 240;
      maxVacation = mVac;
      maxUnpaid = mUnpaid;
    }
    TimeOff(string name, int ID, NumDays sick, NumDays vac, NumDays unpaid){
      empName = name;
      empID = ID;

      sickTaken = sick;
      vacTaken = vac;
      unpaidTaken = unpaid;
      maxSickDays = 0;
      maxVacation = 0;
      maxUnpaid = 0;
    }
    TimeOff(string name, int ID){
      empName = name;
      empID = ID;

      sickTaken = 0;
      vacTaken = 0;
      unpaidTaken = 0;
      maxSickDays = 0;
      maxVacation = 0;
      maxUnpaid = 0;
    }
    //Mutators
    void setSick(NumDays n) { sickTaken = n; }
    void setVac(NumDays n) { vacTaken = n; }
    void setUnpd(NumDays n) { unpaidTaken = n; }
    void setMSic(NumDays n) { maxSickDays = n; }
    void setMVac(NumDays n) { 
      if(n > 240) n = 240;
      maxVacation = n;
    }
    void setMUnp(NumDays n) { maxVacation = n; }
    //Accessors
    NumDays getSick() { return sickTaken; }
    NumDays getVac() { return vacTaken; }
    NumDays getUnpd() { return unpaidTaken; }
    NumDays getMSic() { return maxSickDays; }
    NumDays getMVac() { return maxVacation; }
    NumDays getMUnp() { return maxUnpaid; }
}