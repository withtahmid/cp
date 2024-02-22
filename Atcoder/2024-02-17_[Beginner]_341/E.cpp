/**
 *
 * Author: withtahmid
 * Created: 2024-02-17 17:55:54
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
#define dec(x) setprecision(x)
typedef long long lll;
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
inline string kes(int k){return("Case "+to_string(k)+": ");}
template <class T>inline T scan(){T t;read(t);return t;}
template<class T>
using _set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
void solve(const int& case_no);
void precompute();
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dbg(__init__());
    precompute();
    bool test_case = not true;
    int tc = 1; if(test_case){read(tc);}
    for(int i = 1; i <= tc; ++i){
        dbg(__case__(i));
        solve(i);
    }
    dbg(__elapsed__());
}
const int maxn5 = (1 * 1e5) + 69;
const int maxn6 = (1 * 1e6) + 69;
const int mod7 = (1e9 + 7);
const int mod9 = 998244353;
const int oo = INT_MAX;
const lll OO = LLONG_MAX;
void precompute(){}
void brutforce(){}

struct Node{
    bool good = true;
    int left = -1;
    int right = -1;
    Node(){} 
};
typedef struct Node Node;

class LazySegmentTree {
private:
    vector<Node> tree;
    vector<int> lazy;
    int n;

    void propagate(int node, int start, int end) {
       if(lazy[node] & 1){
            tree[node].left = !tree[node].left;
            tree[node].right = !tree[node].right;
            tree[node].good = true;
        }
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
            int ll = 2 * node, rr = 2 * node + 1;
            tree[node].good &= (tree[ll].right != tree[rr].left);
            tree[node].good &= tree[ll].good and tree[rr].good;
        }
        lazy[node] = 0;
    }

    void updateRangeUtil(int node, int start, int end, int l, int r, int diff) {
        propagate(node, start, end);

        if (start > end || start > r || end < l)
            return;

        if (start >= l && end <= r) {
           tree[node].left = !tree[node].left;
            tree[node].right = !tree[node].right;
            tree[node].good = true;
            int ll = 2 * node, rr = 2 * node + 1;
            if (start != end) {
                lazy[2 * node] += diff;
                lazy[2 * node + 1] += diff;
                tree[node].good &= (tree[ll].right != tree[rr].left);
                tree[node].good &= tree[ll].good and tree[rr].good;
            }
            return;
        }

        int mid = (start + end) / 2;
        updateRangeUtil(2 * node, start, mid, l, r, diff);
        updateRangeUtil(2 * node + 1, mid + 1, end, l, r, diff);

        tree[node].left = tree[2 * node].left;
        tree[node].right = tree[2 * node + 1].right;
        tree[node].good = (tree[2 * node].good and tree[2 * node + 1].good);
        int ll = 2 * node, rr = 2 * node + 1;
        tree[node].good &= (tree[ll].right != tree[rr].left);
    }

    Node queryUtil(int node, int start, int end, int l, int r) {
        propagate(node, start, end);

        if (start > end || start > r || end < l)
            return Node();

        if (start >= l && end <= r)
            return tree[node];

        int mid = (start + end) / 2;
        Node p1 = queryUtil(2 * node, start, mid, l, r);
        Node p2 = queryUtil(2 * node + 1, mid + 1, end, l, r);

        Node res;
        if(p1.left == -1){
            res = p2;
        }
        else if(p2.left == -1){
            res = p1;
        }else{
            res.left = p1.left;
            res.right = p2.right;
            res.good = (p1.good and p2.good) and(p1.right != p2.left);
        }
        return res;
    }

public:
    LazySegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node].good = true;
            tree[node].left = arr[start];
            tree[node].right = arr[start];
            return;
        }

        int mid = (start + end) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);

        int ll = 2 * node, rr = 2 * node + 1;
        tree[node].left = tree[ll].left;
        tree[node].right = tree[rr].right;
        tree[node].good = (tree[ll].good and tree[rr].good);
        tree[node].good &= (tree[ll].right != tree[rr].left);

    }

    void updateRange(int l, int r, int val) {
        updateRangeUtil(1, 0, n - 1, l, r, val);
    }

    Node query(int l, int r) {
        return queryUtil(1, 0, n - 1, l, r);
    }
};

void solve([[maybe_unused]] const int& case_no){
    int n, q;
    read(n, q);
    string str;
    read(str);
    vector<int>v(n);
    for(int i = 0; i < n; ++i){
        v[i]  = (str[i] == '1') ? 1 : 0;
    }
    LazySegmentTree st(v);
    while(q--){
        int op, l, r;
        read(op, l, r);
        if(op == 1){
            st.updateRange(l - 1, r - 1, 1);
        }
        else{
            println(st.query(l - 1, r - 1).good ? "Yes" : "No");
        }
    }
}
