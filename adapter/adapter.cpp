#include <iostream>
#include <string>

class OldGradingSystem {
    
public:

    virtual void giveScore(int score)
    {
        std::cout << "Student scored " << score << " out of 100" << std::endl;
    }

};

class LetterGradingSystem {
    
public:

    void giveLetterGrade(const std::string& grade)
    {
        std::cout << "Student got grade: " << grade << std::endl;
    }

};

class GradingAdapter : public OldGradingSystem {
    
private:

    LetterGradingSystem* letterSystem;

public:

    GradingAdapter()
    {
        letterSystem = new LetterGradingSystem();
    }
    
    void giveScore(int score) override
    {
        std::string grade;
        
        if(score >= 90) grade = "A";
        else if(score >= 80) grade = "B";
        else if(score >= 70) grade = "C";
        else if(score >= 60) grade = "D";
        else grade = "F";
        
        letterSystem->giveLetterGrade(grade);
    }

    ~GradingAdapter()
    {
        delete letterSystem;
    }

};

int main()
{
    OldGradingSystem* student1 = new OldGradingSystem();
    student1->giveScore(85);
    delete student1;
    
    OldGradingSystem* student2 = new GradingAdapter();
    student2->giveScore(85);
    delete student2;
    
    return 0;
}