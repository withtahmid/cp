/**
 * https://vjudge.net/problem/CSES-1648
 * Segment Tree point update Range sum query
 * 
 * */

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5 + 10;
ll segTree[N << 2];

void build(int idx, int left, int right, vector < int > & v) {
    if (left == right) {
        segTree[idx] = v[left];
        return;
    }
    int mid = (left + right) / 2;
    int left_idx = idx * 2;
    int right_idx = idx * 2 + 1;
    build(left_idx, left, mid, v);
    build(right_idx, mid + 1, right, v);
    segTree[idx] = segTree[left_idx] + segTree[right_idx];
}
ll query(int idx, int left, int right, int ql, int qr) {

    // range with no overlap
    if (left > right || left > qr || right < ql) {
        return 0;
    }
    // range with full overlap
    if (left >= ql && right <= qr) {
        return segTree[idx];
    }

    // range with partial overlap

    int mid = (left + right) / 2;
    int left_idx = idx * 2;
    int right_idx = idx * 2 + 1;

    ll ansL = query(left_idx, left, mid, ql, qr);
    ll ansR = query(right_idx, mid + 1, right, ql, qr);

    return ansL + ansR;

}

// point update
void update(int idx, int left, int right, int pos, int value) {
    if (left == right) {
        segTree[idx] = value;
        return;
    }

    int mid = (left + right) / 2;
    int left_idx = idx * 2;
    int right_idx = idx * 2 + 1;

    // position is on left child
    if (pos <= mid) {
        update(left_idx, left, mid, pos, value);
    } // position is on right child
    else {
        update(right_idx, mid + 1, right, pos, value);
    }
    segTree[idx] = segTree[left_idx] + segTree[right_idx];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector < int > v(n);
    for (auto & i: v) {
        cin >> i;
    }
    build(1, 0, n - 1, v);

    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            update(1, 0, n - 1, l - 1, r);
        } else {
            cout << query(1, 0, n - 1, l - 1, r - 1) << "\n";
        }
    }
}

/*
Segment Tree
Problem: https://vjudge.net/problem/CSES-1648
Source Code: https://ideone.com/uxbGfy

Lazy Segment Tree
Problem: https://vjudge.net/problem/LightOJ-1164
Source Code: https://ideone.com/RyWcqW

*/