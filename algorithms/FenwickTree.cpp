#include <iostream>
#include <vector>

class FenwickTree {
    vector<int> tree;
    public:
    FenwickTree(int size) {
        tree.resize(size+1);
    }
    void add(int num, int idx) {
        idx++; // 1-based indexing, give input for 0-based

        while (idx < tree.size()) {
            tree[idx] += num;
            idx += idx & (-idx);
        }
    }
    int query(int idx) {
        idx++; // 1-based indexing, give input for 0-based

        int res = 0;
        while(idx < tree.size()) {
            res += tree[idx];
            idx -= idx & (-idx);
        }

        return res;
    }
};