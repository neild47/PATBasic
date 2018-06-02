//
// Created by neild47 on 18-4-18.
//
#include <cstring>
#include <cstdio>
#include <cstdlib>

typedef struct {
    double danjia;
    double shuliang;
    double zongjia;
} Pie;

static int compare(const void *pie1, const void *pie2) {
    const auto *p1 = static_cast<const Pie *>(pie1);
    const auto *p2 = static_cast<const Pie *>(pie2);
    if (p1->danjia == p2->danjia) {
        return 0;
    } else if (p1->danjia > p2->danjia) {
        return -1;
    } else {
        return 1;
    }
}

Pie pies[1000];

int test1020() {
    int n, xuqiu;
    scanf("%d%d", &n, &xuqiu);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &pies[i].shuliang);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%lf", &pies[i].zongjia);
        pies[i].danjia = pies[i].zongjia / pies[i].shuliang;
    }

    qsort(pies, n, sizeof(Pie), compare);

    int idx = 0;
    double shouyi = 0;
    while (xuqiu > 0 && idx < n) {
        if (pies[idx].shuliang <= xuqiu) {
            xuqiu -= pies[idx].shuliang;
            shouyi += pies[idx].zongjia;
            idx++;
        } else {
            shouyi += pies[idx].danjia * xuqiu;
            break;
        }
    }
    printf("%.2f\n", shouyi);
    return 0;
}
