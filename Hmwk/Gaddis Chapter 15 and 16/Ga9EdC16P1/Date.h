using namespace std;

class Date{
  private:
    static const string months[];
    int month, day, year;
  public:
    class InvalidDay { };
    class InvalidMonth { };
    void setMonth(int m);
    void setDay(int d);
    void setYear(int y);
    void prnDate();
};