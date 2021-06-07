class TestScores{
  private:
    int test1;
    int test2;
    int test3;
  public:
    TestScores(int t1, int t2, int t3){
      test1 = t1;
      test2 = t2;
      test3 = t3;
    }
    TestScores(){
      test1 = 0;
      test2 = 0;
      test3 = 0;
    }
    
    void setTest1(int t1) { test1 = t1; }
    void setTest2(int t2) { test2 = t2; }
    void setTest3(int t3) { test3 = t3; }
    int getTest1() { return test1; }
    int getTest2() { return test2; }
    int getTest3() { return test3; }

    float getAvg(){
      float avg = (test1 + test2 + test3) / 3;
      return avg;
    }
};