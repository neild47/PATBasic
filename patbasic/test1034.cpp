//
// Created by neild47 on 18-4-24.
//

#include <algorithm>
#include <iostream>

using namespace std;

static long gcd(long a, long b) {
    if (a == 0 || b == 0) {
        return 1;
    }
    long x = a > b ? a : b;
    long y = a > b ? b : a;
    long r = x % y;
    while (r != 0) {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}

static long lcm(long a, long b) {
    return a * b / gcd(a, b);
}

class Num {
public:
    int sign;
    long fenzi, fenmu;

    Num(string &s) {
        sscanf(s.data(), "%ld/%ld", &(this->fenzi), &(this->fenmu));
        this->sign = 1;
        if (this->fenzi < 0) {
            this->sign = -1;
            this->fenzi = -this->fenzi;
        }
        long g = gcd(this->fenzi, this->fenmu);
        this->fenzi /= g;
        this->fenmu /= g;
    }

    Num() {
        this->sign = 1;
        this->fenzi = 1;
        this->fenmu = 1;
    }

    void flush() {
        if (this->fenzi < 0) {
            this->sign = -this->sign;
            this->fenzi = -this->fenzi;
        }
        long g = gcd(this->fenzi, this->fenmu);
        this->fenzi /= g;
        this->fenmu /= g;
    }

    friend ostream &operator<<(ostream &ostream1, Num &num) {
        if (num.fenmu == 0) {
            ostream1 << "Inf";
            return ostream1;
        }
        long zhengshu = num.fenzi / num.fenmu;
        long fenzi = num.fenzi % num.fenmu;
        if (num.sign == -1) {
            ostream1 << "(-";
        }
        if (zhengshu != 0) {
            ostream1 << zhengshu;
        }

        if (fenzi == 0 && zhengshu != 0) {

        } else if (fenzi == 0) {
            ostream1 << "0";
        } else {
            if (zhengshu != 0) {
                ostream1 << " ";
            }
            ostream1 << fenzi << "/" << num.fenmu;
        }

        if (num.sign == -1) {
            ostream1 << ")";
        }

        return ostream1;
    }
};


static Num add(Num &num1, Num &num2) {
    Num num;
    long fenmu = lcm(num1.fenmu, num2.fenmu);
    long fenzi1 = num1.sign * num1.fenzi * (fenmu / num1.fenmu);
    long fenzi2 = num2.sign * num2.fenzi * (fenmu / num2.fenmu);
    num.fenzi = fenzi1 + fenzi2;
    num.fenmu = fenmu;
    num.flush();

    return num;
}

static Num sub(Num &num1, Num &num2) {
    Num num;
    long fenmu = lcm(num1.fenmu, num2.fenmu);
    long fenzi1 = num1.sign * num1.fenzi * (fenmu / num1.fenmu);
    long fenzi2 = num2.sign * num2.fenzi * (fenmu / num2.fenmu);
    num.fenzi = fenzi1 - fenzi2;
    num.fenmu = fenmu;
    num.flush();
    return num;
}

static Num mul(Num &num1, Num &num2) {
    Num num;
    long fenmu = lcm(num1.fenmu, num2.fenmu);
    long fenzi1 = num1.sign * num1.fenzi * (fenmu / num1.fenmu);
    long fenzi2 = num2.sign * num2.fenzi * (fenmu / num2.fenmu);
    num.fenzi = fenzi1 * fenzi2;
    num.fenmu = fenmu * fenmu;
    num.flush();
    return num;
}

static Num div(Num &num1, Num &num2) {
    Num num;
    if (num2.fenzi == 0) {
        num.fenmu = 0;
        return num;
    }
    long fenmu = lcm(num1.fenmu, num2.fenmu);
    long fenzi1 = num1.fenzi * (fenmu / num1.fenmu);
    long fenzi2 = num2.fenzi * (fenmu / num2.fenmu);
    num.fenzi = fenzi1 * fenmu;
    num.fenmu = fenmu * fenzi2;
    num.sign = num1.sign * num2.sign;
    num.flush();
    return num;
}

static int test1034() {
    string s;
    cin >> s;
    Num num1(s);
    cin >> s;
    Num num2(s);

    Num n = add(num1, num2);
    cout << num1 << " + " << num2 << " = " << n << endl;
    n = sub(num1, num2);
    cout << num1 << " - " << num2 << " = " << n << endl;
    n = mul(num1, num2);
    cout << num1 << " * " << num2 << " = " << n << endl;
    n = div(num1, num2);
    cout << num1 << " / " << num2 << " = " << n << endl;
    return 0;
}
