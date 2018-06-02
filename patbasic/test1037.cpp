//
// Created by neild47 on 18-4-25.
//
#include <algorithm>
#include <iostream>

using namespace std;

class Money {
public:
    int galleon, sickle, knut;
    int sign;

    Money(string s) {
        sscanf(s.data(), "%d.%d.%d", &(this->galleon), &(this->sickle), &(this->knut));
        this->sign = 1;
    }

    Money operator-(Money &other) {
        Money other_money = other;
        Money money = *this;
        if (*this < other) {
            money = other;
            other_money = *this;
            money.sign = -1;
        }

        if (money.knut < other_money.knut || money.knut < 0) {
            money.knut += 29;
            money.sickle--;
        }

        money.knut -= other_money.knut;
        if (money.sickle < 0 || money.sickle < other_money.sickle) {
            money.sickle += 17;
            money.galleon--;
        }
        money.sickle -= other_money.sickle;

        money.galleon -= other_money.galleon;
        return money;
    }

    bool operator<(Money &other) {
        if (this->galleon != other.galleon) return this->galleon < other.galleon;
        if (this->sickle != other.sickle) return this->sickle < other.sickle;
        if (this->knut != other.knut) return this->knut < other.knut;
        return false;
    }

    friend ostream &operator<<(ostream &ostream1, Money &money) {
        if (money.sign != 1) {
            ostream1 << "-";
        }
        ostream1 << money.galleon << "." << money.sickle << "." << money.knut;
        return ostream1;
    }
};


int test0137() {
    string s;
    cin >> s;
    Money money1(s);
    cin >> s;
    Money money2(s);

    Money m = money2 - money1;
    cout << m << endl;
    return 0;
}
