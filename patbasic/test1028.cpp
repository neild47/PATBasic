//
// Created by neild47 on 18-4-23.
//
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Person {
public:
    string name;
    int year, month, day;

    Person(string name, int year, int month, int day) {
        this->name = std::move(name);
        this->year = year;
        this->month = month;
        this->day = day;
    }

    friend ostream &operator<<(ostream &ostream1, Person &person) {
        ostream1 << person.name << " " << person.year << "/" << person.month << "/" << person.day;
        return ostream1;
    }

    bool operator<(Person &person) {
        if (this->year != person.year) {
            return year < person.year;
        }
        if (this->month != person.month) {
            return month < person.month;
        }

        if (this->day != person.day) {
            return day < person.day;
        }
        return false;
    }
};

static int test1028() {
    int num;
    cin >> num;
    vector<Person> persons;
    string name, time;
    int year, month, day;
    Person lowerBoundPerson("", 1814, 9, 6);
    Person upperBoundPerson("", 2014, 9, 6);
    for (int i = 0; i < num; i++) {
        cin >> name >> time;
        sscanf(time.data(), "%d/%d/%d", &year, &month, &day);
        Person p(name, year, month, day);
        if (p < lowerBoundPerson || upperBoundPerson < p) {
            continue;
        }
        persons.push_back(p);
    }

    sort(persons.begin(), persons.end());

    if (persons.size() == 0) {
        cout << 0 << endl;
    } else {
        cout << persons.size() << " " << persons.front().name << " " << persons.back().name << endl;
    }
    return 0;
}
