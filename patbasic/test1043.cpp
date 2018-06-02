//
// Created by neild47 on 18-4-26.
//
#include <iostream>
#include <algorithm>

using namespace std;

char cmap[] = {'P', 'A', 'T', 'e', 's', 't'};

int test1043() {
    int count[6] = {0};
    int c;
    while (scanf("%c", &c) && c != '\n') {
        switch (c) {
            case 'P':
                count[0]++;
                break;
            case 'A':
                count[1]++;
                break;
            case 'T':
                count[2]++;
                break;
            case 'e':
                count[3]++;
                break;
            case 's':
                count[4]++;
                break;
            case 't':
                count[5]++;
                break;
        }
    }
    int mm = *min_element(count, count + 6);
    for (int i = 0; i < 6; i++) {
        count[i] -= mm;
    }
    for (int i = 0; i < mm; i++) {
        cout << "PATest";
    }
    while (true) {
        bool isHave = false;
        for (int i = 0; i < 6; i++) {
            if (count[i] > 0) {
                isHave = true;
                cout << cmap[i];
                count[i]--;
            }
        }
        if (!isHave) {
            break;
        }
    }
    cout << endl;
    return 0;
}
