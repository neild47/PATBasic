//
// Created by neild47 on 18-4-4.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct {
    char name[11];
    char id[11];
    int grade;
} student;

pair<student *, student *> getMinMaxGradeStudent(vector<student *> &students) {
    if (students.empty()) return pair<student *, student *>{nullptr, nullptr};
    student *max, *min;
    max = min = students[0];
    for (auto tmp: students) {
        if (max->grade < tmp->grade) {
            if (min != max) {
                delete max;
            }
            max = tmp;
        } else if (min->grade > tmp->grade) {
            if (max != min) {
                delete min;
            }
            min = tmp;
        }
    }
    return pair<student *, student *>{min, max};
}

vector<student *> getStudents() {
    int num;
    cin >> num;
    student *tmp = nullptr;
    vector<student *> students;
    for (int i = 0; i < num; ++i) {
        tmp = new student;
        cin >> tmp->name >> tmp->id >> tmp->grade;
        students.push_back(tmp);
    }
    return students;
}

int main() {
    auto students = getStudents();
    auto min_max_student = getMinMaxGradeStudent(students);
    student *max = min_max_student.second, *min = min_max_student.first;
    cout << max->name << " " << max->id << endl;
    cout << min->name << " " << min->id << endl;
    return 0;
}

