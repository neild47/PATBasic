//
// Created by neild47 on 18-4-4.
//
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

struct Student {
    int age;
    int grade;
};

void getStudent(Student *&pStudent) {
    if (pStudent == nullptr) {
        pStudent = new Student;
    }
    pStudent->age = 123;
}

int test1009() {
    Student *s = nullptr;
    getStudent(s);
    cout << s->age << " " << s->grade << endl;
    return 0;
}
