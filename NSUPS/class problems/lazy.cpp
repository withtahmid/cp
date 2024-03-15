#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10;
const int M = N << 2;

ll TREE[N << 2];
ll LAZY[N << 2];

void propagate(int idx, int left, int right) {
    if (LAZY[idx] == 0) return;
    TREE[idx] = TREE[idx] + (LAZY[idx] * (right - left + 1));
    if (left != right) {
        LAZY[idx * 2] += LAZY[idx];
        LAZY[idx * 2 + 1] += LAZY[idx];
    }
    LAZY[idx] = 0;
}

void build(int idx, int left, int right, vector < int > & v) {
    if (left == right) {
        TREE[idx] = v[left];
        return;
    }
    int mid = (left + right) / 2;
    int left_idx = idx * 2;
    int right_idx = idx * 2 + 1;
    build(left_idx, left, mid, v);
    build(right_idx, mid + 1, right, v);
    TREE[idx] = TREE[left_idx] + TREE[right_idx];
}
ll query(int idx, int left, int right, int ql, int qr) {
    
    propagate(idx, left, right);

    if (left > right || left > qr || right < ql) {
        return 0;
    }
    if (left >= ql && right <= qr) {
        return TREE[idx];
    }

    int mid = (left + right) / 2;
    int left_idx = idx * 2;
    int right_idx = idx * 2 + 1;

    ll ansL = query(left_idx, left, mid, ql, qr);
    ll ansR = query(right_idx, mid + 1, right, ql, qr);

    return ansL + ansR;

}

// range update
void update(int idx, int left, int right, int ql, int qr, int value) {
    propagate(idx, left, right);

    if (left > right || left > qr || right < ql) {
        return;
    }
    if (left >= ql && right <= qr) {
        LAZY[idx] += value;
        propagate(idx, left, right);
        return;
    }

    int mid = (left + right) / 2;
    int left_idx = idx * 2;
    int right_idx = idx * 2 + 1;

    update(left_idx, left, mid, ql, qr, value);
    update(right_idx, mid + 1, right, ql, qr, value);

    TREE[idx] = TREE[left_idx] + TREE[right_idx];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int n, q;
        cin >> n >> q;
        vector < int > v(n, 0);
        build(1, 0, n - 1, v);
        for (int i = 0; i < M; ++i) {
            TREE[i] = LAZY[i] = 0;
        }
        cout << "Case " << tc << ":\n";
        while (q--) {
            int op, l, r;
            cin >> op >> l >> r;
            if (op == 0) {
                int val;
                cin >> val;
                update(1, 0, n - 1, l, r, val);
            } else {
                cout << query(1, 0, n - 1, l, r) << "\n";
            }
        }
    }
}