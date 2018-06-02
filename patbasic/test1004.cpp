//
// Created by neild47 on 18-4-4.
//
#include <iostream>

using namespace std;

typedef struct {
    char name[11];
    char id[11];
    int grade;
} student;

int test1004() {
    student *max = nullptr;
    student *min = nullptr;
    int num;
    cin >> num;
    student *tmp = nullptr;
    for (int i = 0; i < num; ++i) {
        tmp = new student;
        cin >> tmp->name >> tmp->id >> tmp->grade;
        if (max == nullptr && min == nullptr) {
            max = min = tmp;
        } else {
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
            } else {
                delete tmp;
            }
        }
    }
    cout << max->name << " " << max->id << endl;
    cout << min->name << " " << min->id << endl;
    return 0;
}

