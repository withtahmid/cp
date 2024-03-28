#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
class _multiset{
    using MS  = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
    MS st;
public:
    _multiset(){st.clear();}
    void insert(T xx){st.insert(xx);}
    void erase(T xx){st.erase(st.upper_bound(xx));}
    void erase(typename MS::iterator xx){st.erase(xx);}
    int order_of_key(T xx){return st.order_of_key(xx);}
    T find_by_order(int xx){return st.find_by_order(xx);}
    typename MS::iterator lower_bound(T xx){return st.upper_bound(xx);}
    typename MS::iterator upper_bound(T xx){return st.lower_bound(xx);}
    size_t size(){return st.size();}
};

const int N = 3e5 + 69;
int64_t a[N];
_multiset < int64_t > seg[4 * N + 5];

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
void update(int node, int l, int r, int idx, int64_t val) {
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

int query(int node, int l, int r, int lx, int rx, int64_t x) {
    if (l > rx || r < lx){
        return 0;
    }
    if (l >= lx && r <= rx){
        return seg[node].order_of_key(x);
    }
    int mid = (l + r) / 2;
    int lRes = query(node * 2, l, mid, lx, rx, x);
    int rRes = query(node * 2 + 1, mid + 1, r, lx, rx, x);
    return lRes + rRes;
}

void solve(const int& tc){
    int64_t n, m, u;
    cin >> n >> m >> u;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    build(1, 1, n);

    while(m--){
        int64_t l, r, v, p;
        cin >> l >> r >> v >> p;
        int k = query(1, 1, n, l, r, v);
        int64_t value = 1LL * u * k / (r - l + 1);
        update(1, 1, n, p, value), a[p] = value;
    }
    for(int i = 1; i <= n; ++i){
        cout << a[i] << '\n';
    }
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
    _multiset<int> st;
    st.insert(1);
    auto x = st.lower_bound(1);
    dbg(typeid(st).name());
}
