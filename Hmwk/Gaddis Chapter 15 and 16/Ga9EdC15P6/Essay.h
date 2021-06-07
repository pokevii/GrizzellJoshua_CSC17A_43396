#include "GradedActivity.h"

class Essay : public GradedActivity{
  protected:
    int grammar, spelling, length, content;
  public:
    Essay(){
      grammar = 0;
      spelling = 0;
      length = 0;
      content = 0;
    }
    Essay(int g, int s, int l, int c){
      grammar = g;
      spelling = s;
      length = l;
      content = c;
    }

    void setGrmr(int g) { grammar = g; }
    void setSplng(int s) { spelling = s; }
    void setLngth(int l) { length = l; }
    void setCntnt(int c) { content = c; }
    int getGrmr() { return grammar; }
    int getSplng() { return spelling; }
    int getLngth() { return length; }
    int getCntnt() { return content; }

    void grade();
};