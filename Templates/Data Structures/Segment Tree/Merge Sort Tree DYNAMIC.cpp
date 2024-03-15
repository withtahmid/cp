
const int N = 1e5 + 5;
int n, q, a[N];
multiset < int > seg[4 * N + 5];
void build(int node, int l, int r) {
    if (l == r) {
        seg[node].insert(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    for (int i = l; i <= r; i++) seg[node].insert(a[i]);
    return;
}
void update(int node, int l, int r, int idx, int val) {
    if (l == r) {
        seg[node].erase(a[idx]);
        seg[node].insert(val);
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid){
        update(node * 2, l, mid, idx, val);
    }

    else{
        update(node * 2 + 1, mid + 1, r, idx, val);
    }
    seg[node].erase(a[idx]);
    seg[node].insert(val);
    return;
}
int query(int node, int l, int r, int lx, int rx, int x) {
    if (l > rx || r < lx){
        return INT_MAX;
    }
    if (l >= lx && r <= rx) {
        auto it = seg[node].lower_bound(x);
        return (it == seg[node].end()) ? INT_MAX : *it;
    }
    int mid = (l + r) / 2;
    int lRes = query(node * 2, l, mid, lx, rx, x);
    int rRes = query(node * 2 + 1, mid + 1, r, lx, rx, x);
    return min(lRes, rRes);
}

// build(1,1,n);
// update(1,1,n,idx,val);
// query(1,1,n,l,r,x);
// point update
// range query l, r, x -> smallest v[i] >= x between l and r

// INT_MAX -> no result