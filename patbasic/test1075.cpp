//
// Created by neild47 on 18-5-2.
//
#include <iostream>

using namespace std;

int data[100001];
int nextaddr[100001];
#define HEAD_ADDR 100000

int test1075() {
    int n, k;
    scanf("%d%d%d", &nextaddr[HEAD_ADDR], &n, &k);

    int addr, value, nextpos0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &addr, &value, &nextpos0);
        data[addr] = value;
        nextaddr[addr] = nextpos0;
    }

    int curr = HEAD_ADDR;
    int iter = nextaddr[HEAD_ADDR];
    int prev = HEAD_ADDR;
    while (data[iter] < 0 && iter != -1) {
        prev = iter;
        curr = prev;
        iter = nextaddr[iter];
    }
    while (iter != -1) {
        if (data[iter] < 0) {
            int olditernext = nextaddr[iter];
            nextaddr[prev] = nextaddr[iter];
            nextaddr[iter] = nextaddr[curr];
            nextaddr[curr] = iter;
            curr = iter;
            iter = olditernext;
        } else {
            prev = iter;
            iter = nextaddr[iter];
        }
    }


    iter = nextaddr[curr];
    prev = curr;
    while (data[iter] >= 0 && data[iter] <= k && iter != -1) {
        prev = iter;
        curr = prev;
        iter = nextaddr[iter];
    }
    while (iter != -1) {
        if (data[iter] >= 0 && data[iter] <= k) {
            int olditernext = nextaddr[iter];
            nextaddr[prev] = nextaddr[iter];
            nextaddr[iter] = nextaddr[curr];
            nextaddr[curr] = iter;
            curr = iter;
            iter = olditernext;
        } else {
            prev = iter;
            iter = nextaddr[iter];
        }
    }

    int i = nextaddr[HEAD_ADDR];
    for (;; i = nextaddr[i]) {
        if (nextaddr[i] == -1) {
            printf("%05d %d %d\n", i, data[i], nextaddr[i]);
            break;
        } else {
            printf("%05d %d %05d\n", i, data[i], nextaddr[i]);
        }
    }
    return 0;
}
