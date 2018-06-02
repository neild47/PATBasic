//
// Created by neild47 on 18-4-23.
//
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

class Node {
public:
    string addr_s;
    string value;
    string next_s;

    Node(string addr_s, string value, string next_s) {
        this->addr_s = std::move(addr_s);
        this->value = std::move(value);
        this->next_s = std::move(next_s);
    }

    bool operator<(const struct Node &n) {
        return addr_s < n.addr_s;
    }

    friend ostream &operator<<(ostream &ostream1, const Node &node) {

        ostream1 << node.addr_s << " " << node.value << " " << node.next_s;
        return ostream1;
    }
};

int test1025() {
    int firstAddr;
    int n, k;
    cin >> firstAddr >> n >> k;
    map<int, Node> nodes;
    vector<Node *> node_list;

    string addr, value, next;
    for (int i = 0; i < n; i++) {
        cin >> addr >> value >> next;
        nodes.insert(make_pair(atoi(addr.data()), Node(addr, value, next)));
    }

    while (firstAddr != -1) {
        auto no = nodes.find(firstAddr);
        node_list.push_back(&((*no).second));
        firstAddr = atoi((*no).second.next_s.data());
    }

    auto iter = node_list.begin();
    while (iter + k < node_list.end()) {
        reverse(iter, iter + k);
        iter += k;
    }

    for (int i = 0; i < node_list.size() - 1; i++) {
        (*(node_list[i])).next_s = (*(node_list[i + 1])).addr_s;
        cout << *node_list[i] << endl;
    }

    (*node_list[node_list.size() - 1]).next_s = "-1";
    cout << *node_list[node_list.size() - 1] << endl;
    return 0;
}
