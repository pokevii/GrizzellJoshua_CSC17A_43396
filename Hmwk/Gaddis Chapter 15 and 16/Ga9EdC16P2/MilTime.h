#include "Time.h"

class MilTime : public Time{
  protected:
    int milHrs;
    int milSecs;
  public:
    class BadHour { };
    class BadSeconds { };
    MilTime(){
      milHrs = 0;
      milSecs = 0;
    }
    MilTime(int hr, int sec){
      if(hr < 2400 && hr > 0) {
        milHrs = hr;
      }else{
        throw BadHour();
      }

      if(sec < 60 && sec > 0){
        milSecs = sec;
      } else {
        throw BadSeconds();
      }

      int mins = hr % 100;
      setHour((hr - mins) / 100);
      setMin(mins);
      setSec(sec);
      
    }
    void setTime();
    int getMHr();
    int getSHr();
};