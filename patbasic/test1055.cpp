//
// Created by neild47 on 18-4-29.
//
#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
public:
    int tall;
    string name;

    Student(int tall, string name) : tall(tall), name(std::move(name)) {}


    bool operator<(Student &other) {
        if (tall != other.tall) {
            return tall > other.tall;
        } else {
            return name < other.name;
        }
    }
};

static int test1055() {
    int num, row;
    cin >> num >> row;
    vector<Student> students;

    string s;
    int t;
    for (int i = 0; i < num; i++) {
        cin >> s >> t;
        students.emplace_back(t, s);
    }

    sort(students.begin(), students.end());

    vector<list<Student>> ans;
    for (int i = 0; i < row; i++) {
        int nrow = num / row;
        if (i == row - 1) nrow = num / row + num % row;
        list<Student> student_row;
        auto iter = students.rbegin() + nrow - 1;
        student_row.push_back(*iter);
        iter--;
        for (int j = 1; j < nrow; j++) {
//            cout << (*iter).name << endl;
            student_row.push_front(*iter);
            iter--;
            j++;
            if (j != nrow) {
//                cout << (*iter).name << endl;
                student_row.push_back(*iter);
                iter--;
            }
        }

        for (int j = 0; j < nrow; j++) {
            students.pop_back();
        }
        ans.push_back(student_row);
    }

    for (auto iter = ans.rbegin(); iter != ans.rend(); iter++) {
        auto ii = (*iter).begin();
        cout << (*ii).name;
        ii++;
        while (ii != (*iter).end()) {
            cout << " " << (*ii).name;
            ii++;
        }
        cout << endl;
    }
    return 0;
}

