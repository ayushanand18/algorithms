#include <iostream>
#include <vector>

class SegmentTree {
    vector<int> tree;
    public:
    SegmentTree(int size) {
        tree.resize(4*size+1);
    }
    void build(vector<int> arr, int v, int tl, int tr) {
        if(tl == tr) {
            tree[v] = arr[tl];
        } else {
            int tm = (tl+tr)/2;
            build(arr, 2*v, tl, tm);
            build(arr, 2*v+1, tm+1, tr);
            tree[v] = tree[2*v] + tree[2*v+1];
        }
    }
    int query(int v, int tl, int tr, int l, int r) {
        if(l > r) {
            return 0;
        }
        if(l == tl and r == tr) {
            return tree[v];
        }
        int tm = (tr+tl)/2;
        return query(v*2, tl, tm, l, min(r, tm)) + query(v*2+1, tm+1, tr, max(l, tm+1), r);
    }
    void update(int v, int tl, int tr, int pos, int new_val) {
        if(tl == tr) {
            tree[v] = new_val;
        } else {
            int tm = (tl+tr)/2;
            if(pos <= tm)
                update(2*v, tl, tm, pos, new_val);
            else 
                ipdate(2*v+1, tm+1, tr, pos, new_val);
            tree[v] = tree[2*v]+tree[2*v+1];
        }
    }
}