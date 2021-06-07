class GradedActivity{
  protected:
    float score;
  public:
    GradedActivity(){
      score = 0.0f;
    }
    GradedActivity(float s){
      score = s;
    }
    void setScore(float s){
      score = s;
    }

    float getScore() const{
      return score;
    }
    char getLetterGrade() const;
};