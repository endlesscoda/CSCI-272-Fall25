// Muhammad Durrani, Cristian Medina Ceballos, Mohab Abdalla
// CSCI 272-01

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "student.h"
#include "course.h"
using namespace std;

int main() {
    Student student;       
    Course courses[5]; 

    // Getting the students name
    string name;
    cout << "Please enter your name: " << endl;
    getline(cin, name);

    // Asking how many courses the student is taking 
    int numCourses;
    cout << "Number of courses currently taking? " << endl;
    cin >> numCourses;

    cin.ignore(); 

    // Validate the number of courses (must be between 1 and 5)
    while (cin.fail() || numCourses < 1 || numCourses > 5) {
        cin.clear(); // Reset the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
        cout << "Invalid input. Please enter a number between 1 and 5: ";
        cin >> numCourses;
    }

    // Loop to collect course information
    for (int i = 0; i < numCourses; i++) {
        string courseName, grade;
        int credits;

        cout << "\nEntering course #" << (i + 1) << ":\n";
        
        // Get the course name
        cout << "Course name: ";
        getline(cin, courseName);

        // Get the number of credit hours
        cout << "Credit hours: ";
        cin >> credits;

        while (cin.fail() || credits < 0) {
            cout << "Please enter a valid number: ";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> credits;
        }

        cout << "Letter grade: ";
        cin >> grade;

        while (!isValidGrade(grade)) {
            cout << "Please enter a valid grade: ";
            cin >> grade;
        }

        cin.ignore();
        courses[i].setData(courseName, credits, grade);
    }

    // GPA Calculation
    double totalPoints = 0;
    int totalCredits = 0;

    cout << "\nStudent:  " << student.getName() << "\n\n";

    // Print the report header
    cout << "------------------ Grade Report ------------------\n";
    cout << "Course    Credits   GradePts   TotalPts" << endl;
    cout << "-------------------------------------------" << endl;

    // Loop through each course to display details and accumulate totals
    for (int i = 0; i < numCourses; i++) {
        cout << left << setw(10) << courses[i].getName()
             << right << setw(6) << courses[i].getCredits()
             << setw(10) << fixed << setprecision(2) << courses[i].getGradePoints()
             << setw(10) << fixed << setprecision(2) << courses[i].getTotalPoints()
             << endl;

        totalPoints += courses[i].getTotalPoints();
        totalCredits += courses[i].getCredits();
    }

    // Compute GPA
    double gpa = (totalCredits > 0) ? totalPoints / totalCredits : 0.0;

    // Print the summary of results
    cout << "-------------------------------------------" << endl;
    cout << "Total Credits:    " << totalCredits << endl;
    cout << "Total Points:    " << fixed << setprecision(2) << totalPoints << endl;
    cout << "Semester GPA:    " << fixed << setprecision(2) << gpa << endl;

    // Determine the student's academic standing based on GPA
    string standing;
    if (gpa >= 3.6) {
        standing = "Dean's List";
    } else if (gpa >= 2.0) {
        standing = "Good Standing";
    } else {
        standing = "Academic Probation";
    }

    // Display the student's final standing
    cout << "Standing:  " << standing << endl;

    return 0;
}

// Cristian Medina Ceballos - 10/17/2025
// This is the first time I have ever worked on a group project related to computer science, and it honestly wasn’t that bad. 
// The code that we wrote was a collective effort from each member of the group, where we coordinated who would do what sections of the code 
// so that it was easier for us and we knew what to focus on. Of course, we would look at each other’s codes and check for any mistakes and correct 
// them if there were any. I feel like this was a starting experience for me and gave me some type of idea on how future projects will be like when it 
// comes to creating codes, whether it be class related or outside of college. This also helped us practice writing codes and understanding how they 
// work while at the same time challenging us. For example, one thing that was tricky for me was understanding how to organize the program using classes 
// and header files, however, on the other hand, one thing that I learned from this project was error handling as well as class interaction. I feel like 
// this project also helped improve our problem-solving skills and collaborating as a group, and overall, this was a good learning experience for not just 
// us, but for the other groups as well.
