#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node { ll lazy, a, b; };
const int mx = 100005;
node tree[4 * mx];

void build(ll v, ll tl, ll tr) {
    if(tl == tr) {
        tree[v].a = 100;
        tree[v].b = tl * 100;
    } else {
        ll tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        tree[v].a = tree[2 * v].a + tree[2 * v + 1].a;
        tree[v].b = tree[2 * v].b + tree[2 * v + 1].b;
    }
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll val) {
    if(tree[v].lazy != 0) {
        tree[v].a += (tr - tl + 1) * tree[v].lazy;
        tree[v].b += (tl + tr) * (tr - tl + 1) / 2 * tree[v].lazy;
        if(tl != tr) {
            tree[2 * v].lazy += tree[v].lazy;
            tree[2 * v + 1].lazy += tree[v].lazy;
        }
        tree[v].lazy = 0;
    }

    if(tl > tr || tl > r || tr < l) {
        return;
    }

    if(tl >= l && tr <= r) {
        tree[v].a += (tr - tl + 1) * val;
        tree[v].b += (tl + tr) * (tr - tl + 1) / 2 * val;
        if(tl != tr) {
            tree[2 * v].lazy += val;
            tree[2 * v + 1].lazy += val;
        }
        return;
    }

    ll tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, r, val);
    update(2 * v + 1, tm + 1, tr, l, r, val);
    tree[v].a = tree[2 * v].a + tree[2 * v + 1].a;
    tree[v].b = tree[2 * v].b + tree[2 * v + 1].b;
}

ll query(ll v, ll tl, ll tr, ll l, ll r) {
    if(tree[v].lazy != 0) {
        tree[v].a += (tr - tl + 1) * tree[v].lazy;
        tree[v].b += (tl + tr) * (tr - tl + 1) / 2 * tree[v].lazy;
        if(tl != tr) {
            tree[2 * v].lazy += tree[v].lazy;
            tree[2 * v + 1].lazy += tree[v].lazy;
        }
        tree[v].lazy = 0;
    }

    if(tl > tr || tl > r || tr < l) {
        return 0;
    }

    if(tl >= l && tr <= r) {
        return tree[v].b - (l - 1) * tree[v].a;
    }
    ll tm = (tl + tr) / 2;
    return query(2 * v, tl, tm, l, r)
        + query(2 * v + 1, tm + 1, tr, l, r);
}

void run_case() {
    memset(tree, 0, sizeof(tree));

    ll n, q;
    cin >> n >> q;

    build(1, 1, n);

    while(q--) {
        string s;
        ll i, j, u;
        cin >> s;
        if(s == "change") {
            cin >> i >> j >> u;
            update(1, 1, n, i, j, u);
        } else {
            cin >> i >> j;
            cout << query(1, 1, n, i, j) << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        cout << "Case " << tc << ":\n";
        run_case();
    }
}