/**
 *
 * Author: withtahmid
 *
 **/
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#ifdef LOCAL 
#include <debug.h>
#else
#define local(...) 
#define debug(...)
#define dbg(...)
#endif
#define pb push_back
#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define has(x, y) (x.find(y) != x.end())
#define decimal(x) setprecision(x)
#define int ll
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
inline void print(const auto& a){cout<<a;}
inline void print(const vector<auto>& v){for(auto&i:v){print(i);print(" ");}}
inline void print(const auto &...a) {((print(a)), ...);}
inline void println(const auto &...a) {print(a..., '\n');}
inline bool read(auto& x){return(cin >> x) ? true : false;}
inline bool read(pair<auto, auto>& p){ return (read(p.first) and read(p.second));}
inline bool read(vector<auto>& v) {bool x = true; for(auto&i:v){x&=read(i);} return x;}
inline bool read(auto &...a) {return (((read(a))?true:false)&&...);}
template<class T>
using _set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
void solve(int);
void precompute();
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dbg(__init__());
    precompute();
    bool test_case = true;
    int tc = 1; if(test_case){cin >> tc;}
    for(int i = 1; i <= tc; ++i){
        dbg(__case__(i));
        solve(i);
    }
    dbg(__elapsed__());
    return 0;
}

class LazySegmentTree {
private:
    vector<int> tree;
    vector<int> lazy;
    int n;

    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node] * (end - start + 1);
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void updateRangeUtil(int node, int start, int end, int l, int r, int diff) {
        propagate(node, start, end);

        if (start > end || start > r || end < l)
            return;

        if (start >= l && end <= r) {
            tree[node] += diff * (end - start + 1);
            if (start != end) {
                lazy[2 * node] += diff;
                lazy[2 * node + 1] += diff;
            }
            return;
        }

        int mid = (start + end) / 2;
        updateRangeUtil(2 * node, start, mid, l, r, diff);
        updateRangeUtil(2 * node + 1, mid + 1, end, l, r, diff);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int queryUtil(int node, int start, int end, int l, int r) {
        propagate(node, start, end);

        if (start > end || start > r || end < l)
            return 0;

        if (start >= l && end <= r)
            return tree[node];

        int mid = (start + end) / 2;
        int p1 = queryUtil(2 * node, start, mid, l, r);
        int p2 = queryUtil(2 * node + 1, mid + 1, end, l, r);

        return p1 + p2;
    }

public:
    LazySegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void build(vector<int>& arr, int stIndex, int lo, int hi) {
        if (lo == hi) {
            tree[stIndex] = arr[lo];
            return;
        }

        int mid = (lo + hi) / 2, left = stIndex * 2, right = 2 * stIndex + 1;
        build(arr, left, lo, mid);
        build(arr, right, mid + 1, hi);
        tree[stIndex] = tree[left] + tree[right];
    }

    void updateRange(int l, int r, int val) {
        updateRangeUtil(1, 0, n - 1, l, r, val);
    }

    int query(int l, int r) {
        return queryUtil(1, 0, n - 1, l, r);
    }
};

const int maxn5 = (1 * 1e5) + 69;
const int maxn6 = (1 * 1e6) + 69;
const int mod7 = (1e9 + 7);
const int mod9 = 998244353;
const int oo = INT_MAX;
const ll OO = LLONG_MAX;
void precompute(){}
void brutforce(){}
template<class T>T scan(){T t; cin >> t; return t;} 
void solve([[maybe_unused]] const int case_no){
    println("Case ", case_no, ":");
    ll n, q;
    read(n, q);
    dbg(n, q);
    vector<int>v(n, 0LL);
    LazySegmentTree segTree(v);
    while(q--){
        ll op, l, r;
        read(op, l, r);
        if(op == 0LL){
            segTree.updateRange(l, r, scan<ll>());
        }else{
            println(segTree.query(l, r));
        }
    }
}
