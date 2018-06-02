//
// Created by neild47 on 18-5-8.
//
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Student {
public:
    string name;
    int p = -1;
    int g1 = -1;
    int g2 = -1;
    int g = -1;

    Student(string name, int p) {
        this->name = std::move(name);
        this->p = p;
    }

    void flush() {
        if (g1 > g2) {
            g = static_cast<int>(round(0.4 * g1 + 0.6 * g2));
        } else {
            g = g2;
        }
    }

    friend ostream &operator<<(ostream &ostream1, Student &s) {
        ostream1 << s.name << " " << s.p << " " << s.g1 << " " << s.g2 << " " << s.g;
        return ostream1;
    }
};

int test1080() {
    int p, m, n;
    cin >> p >> m >> n;
    map<string, Student> students;
    for (int i = 0; i < p; i++) {
        string name;
        int mark;
        cin >> name >> mark;
        if (mark >= 200) {
            students.insert(make_pair(name, Student(name, mark)));
        }
    }

    for (int i = 0; i < m; i++) {
        string name;
        cin >> name;
        int mark;
        cin >> mark;
        auto s = students.find(name);
        if (s != students.end()) {
            (*s).second.g1 = mark;
        }
    }

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        int mark;
        cin >> mark;
        auto s = students.find(name);
        if (s != students.end()) {
            (*s).second.g2 = mark;
        }
    }

    vector<Student> student_v;
    for (auto iter = students.begin(); iter != students.end(); iter++) {
        (*iter).second.flush();
        if ((*iter).second.g >= 60) {
            student_v.push_back((*iter).second);
        }
    }

    sort(student_v.begin(), student_v.end(), [](Student &s1, Student &s2) {
        if (s1.g != s2.g) {
            return s1.g > s2.g;
        } else {
            return s1.name < s2.name;
        }
    });

    for (Student &s:student_v) {
        cout << s << endl;
    }
    return 0;
}
