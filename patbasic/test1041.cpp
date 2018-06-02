//
// Created by neild47 on 18-4-26.
//
#include <iostream>

using namespace std;

static int mapToSite[1001];
static long mapToId[1001];

int test1041() {
    int n;
    cin >> n;
    long tmpID;
    int tmpS;
    int tmpSite;
    for (int i = 0; i < n; i++) {
        cin >> tmpID >> tmpS >> tmpSite;
        mapToSite[tmpS] = tmpSite;
        mapToId[tmpS] = tmpID;
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmpS;
        cout << mapToId[tmpS] << " " << mapToSite[tmpS] << endl;
    }
    return 0;
}