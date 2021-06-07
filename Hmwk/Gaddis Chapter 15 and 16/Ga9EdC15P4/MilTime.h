#include "Time.h"

class MilTime : public Time{
  protected:
    int milHrs;
    int milSecs;
  public:
    MilTime(){
      milHrs = 0;
      milSecs = 0;
    }
    MilTime(int hr, int sec){
      milHrs = hr;
      milSecs = sec;

      int mins = hr % 100;
      setHour((hr - mins) / 100);
      setMin(mins);
      setSec(sec);
      
    }
    void setTime();
    int getMHr();
    int getSHr();
};