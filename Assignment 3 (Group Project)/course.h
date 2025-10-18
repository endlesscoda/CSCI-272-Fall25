// Muhammad Durrani, Cristian Medina Ceballos
// 10/17/2025
// CSCI 272-01

#include <iostream>
#include <string>
using namespace std;


class Course{
private:
    string coursename;
    int credits;
    string lettergrade;
    double gradePoints;

public:
    Course() {
        coursename = "";
        credits = 0;
        lettergrade = "";
        gradePoints = 0.0;
    }

    void setData(string n, int c, string g) {
        coursename = n;
        credits = c;
        lettergrade = g;

        if (g == "A+") gradePoints = 4.0;
        else if (g == "A") gradePoints = 3.7;
        else if (g == "B+") gradePoints = 3.3;
        else if (g == "B") gradePoints = 3.0;
        else if (g == "B-") gradePoints = 2.7;
        else if (g == "C+") gradePoints = 2.3;
        else if (g == "C") gradePoints = 2.0;
        else if (g == "C-") gradePoints = 1.7;
        else if (g == "D") gradePoints = 1.0;
        else gradePoints = 0.0; 
    }

    string getName() { return coursename; }
    int getCredits() { return credits; }
    string getGrade() { return lettergrade; }
    double getGradePoints() { return gradePoints; }
    double getTotalPoints() { return credits * gradePoints; }
};

bool isValidGrade(string g) {
    string validGrades[] = {"A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"};
    for (int i = 0; i < 10; i++) {
        if (g == validGrades[i]) return true;
    }
    return false;
}
