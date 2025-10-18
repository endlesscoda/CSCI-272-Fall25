// Muhammad Durrani, Cristian Medina Ceballos
// 10/17/2025
// CSCI 272-01

#include <iostream>
#include <string>
using namespace std;


class Student {
private:
    string Studentname;

public:
    void setName(string n) {
        Studentname = n;
    }

    string getName() {
        return Studentname;
    }
};
