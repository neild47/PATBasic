//
// Created by neild47 on 18-4-29.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Question {
public:
    int id;
    int count;
    int mark;

    vector<char> ans;

    Question(int id, int mark) : id(id), count(0), mark(mark) {
    }

    bool operator<(Question &other) {
        if (count != other.count) {
            return count > other.count;
        } else {
            return id < other.id;
        }
    }
};

int test1058() {
    int n_students, n_questions;
    cin >> n_students >> n_questions;
    vector<Question> questions;
    questions.reserve(n_questions);
    for (int i = 1; i <= n_questions; i++) {
        int mark;
        cin >> mark;
        questions.emplace_back(i, mark);
        cin >> mark;
        cin >> mark;
        for (int j = 0; j < mark; j++) {
            char c;
            cin >> c;
            while (c == ' ') {
                cin >> c;
            }
            questions.back().ans.push_back(c);
        }
    }

    for (int i = 0; i < n_students; i++) {
        int s_mark = 0;
        for (int j = 0; j < n_questions; j++) {
            char c;
            cin >> c;
            while (c != '(') {
                cin >> c;
            }
            int co;
            cin >> co;
            if (co == questions[j].ans.size()) {
                bool iserr = false;
                while (c != ')') {
                    cin >> c;
                    while (c == ' ') {
                        cin >> c;
                    }
                    if (c == ')') break;
                    if (!binary_search(questions[j].ans.begin(), questions[j].ans.end(), c)) {
                        iserr = true;
                    }
                }
                if (iserr) {
                    questions[j].count++;
                } else {
                    s_mark += questions[j].mark;
                }
            } else {
                questions[j].count++;
            }
        }
        cout << s_mark << endl;
    }
    sort(questions.begin(), questions.end());
    if ((*questions.begin()).count == 0) {
        cout << "Too simple" << endl;
    } else {
        auto iter = questions.begin();
        cout << (*iter).count << " " << (*iter).id;
        iter++;
        while ((*iter).count == (*questions.begin()).count && iter != questions.end()) {
            cout << " " << (*iter).id;
            iter++;
        }
    }
    return 0;
}

