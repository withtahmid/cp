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
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
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
    int tc = 1; if(test_case){cin >> tc;}
    for(int i = 1; i <= tc; ++i){
        dbg(__case__(i));
        solve(i);
    }
    dbg(__elapsed__());
}
const int maxn5 = (1 * 1e5) + 69;
const int maxn6 = (1 * 1e6) + 69;
const int mod = (1e9 + 7); //998244353
const int oo = ((1ULL << 31) - 1);
const  ll OO = ((1ULL << 63) - 1);
void precompute(){}
void brutforce(){}
template < class T, class V >
class SegmentTree {
private:
    vector<V>nodes;
    uint N;
    void buildTree(const vector < T > & arr, uint stIndex, uint left, uint right) {
        if (left == right) {
            return nodes[stIndex].assignLeaf(arr[left]);
        }
        const uint lc = (stIndex << 1), rc = lc | 1, mid = ((left + right) >> 1);
        buildTree(arr, lc, left, mid);
        buildTree(arr, rc, mid + 1, right);
        nodes[stIndex].mergeNode(nodes[lc], nodes[rc]);
    }

    V query(uint stIndex, uint left, uint right, uint lo, uint hi) {
        if (left == lo && right == hi) {
            return nodes[stIndex];
        }
        const uint lc = (stIndex << 1), rc = lc | 1, mid = ((left + right) >> 1);
        if (lo > mid) {
            return query(rc, mid + 1, right, lo, hi);
        }
        if (hi <= mid) {
            return query(lc, left, mid, lo, hi);
        }

        V leftResult = query(lc, left, mid, lo, mid);
        V rightResult = query(rc, mid + 1, right, mid + 1, hi);
        V result;
        result.mergeNode(leftResult, rightResult);
        return result;
    }
    uint sgtsz(uint N) {uint x = 1u; for(; x < N; x <<= 1u);return x << 1u;}
    void update(uint stIndex, uint left, uint right, uint index, T value) {
        if (left == right) {
            return nodes[stIndex].assignLeaf(value);
        }
        const uint lc = (stIndex << 1), rc = lc | 1, mid = ((left + right) >> 1);
        if (index <= mid) {
            update(lc, left, mid, index, value);
        } else {
            update(rc, mid + 1, right, index, value);
        }
        nodes[stIndex].mergeNode(nodes[lc], nodes[rc]);
    }
public:
    SegmentTree(const vector < T > & arr, const uint sz) {
        this -> N = sz;
        nodes.resize(sgtsz(this -> N) + 5);
        buildTree(arr, 1, 0, this -> N - 1);
    }
    SegmentTree(const vector<T>& arr):SegmentTree(arr, (uint) arr.size()){}
    SegmentTree(const uint sz){
        this -> N = sz;
        nodes.resize(sgtsz(this -> N) + 5);
    }
    void assign(const vector<T>& arr){
        assert(nodes.size() >= sgtsz(arr.size()));
        this -> N = (uint)arr.size();
        buildTree(arr, 1, 0, this -> N - 1);
    }
    V query(int lo, int hi) {
        assert(0 <= lo); assert(hi < (int)this -> N); assert(lo <= hi);
        return query(1, 0, this -> N - 1, lo, hi);
    }

    void update(int index, T value) {
        assert(0 <= index and index < (int)this -> N);
        update(1, 0, this -> N - 1, index, value);
    }
};

struct STNode {
    int64_t optimal = -OO, prefx = -OO, suffix = -OO, total = -OO;
    void mergeNode(STNode& LC, STNode& RC) {
        this -> total = (LC.total + RC.total);
        this -> prefx = max(LC.total + RC.prefx, LC.prefx);
        this -> suffix = max(RC.total + LC.suffix, RC.suffix);
        this -> optimal = max({LC.optimal, RC.optimal, LC.suffix + RC.prefx});
    }
    void assignLeaf(uint64_t val) {
        this -> optimal = this -> total = this -> prefx = this -> suffix = val;
    }
};
void solve([[maybe_unused]] const int& case_no){
    int n;
    cin >> n;
    vector<int>v(n);
    for(int& i : v){
        cin >> i;
    }
    SegmentTree<int, STNode>st(v);
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        --l, --r;
        cout << st.query(l, r).optimal << "\n";
    }
}
