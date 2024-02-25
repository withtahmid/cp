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
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
// inline void print(const auto& a){cout<<a;}
// inline void print(const vector<auto>& v){for(auto&i:v){print(i);print(" ");}}
// inline void print(const auto &...a) {((print(a)), ...);}
// inline void println(const auto &...a) {print(a..., '\n');}
// inline bool read(auto& x){return(cin >> x) ? true : false;}
// inline bool read(pair<auto, auto>& p){ return (read(p.first) and read(p.second));}
// inline bool read(vector<auto>& v) {bool x = true; for(auto&i:v){x&=read(i);} return x;}
// inline bool read(auto &...a) {return (((read(a))?true:false)&&...);}
template<class T>
using _set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
void solve(int);
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
    return 0;
}

template < class T, class V >
class SegmentTree {
private:
    vector<V>nodes;
    uint32_t N;
    void buildTree(const vector < T > & arr, uint32_t stIndex, uint32_t left, uint32_t right) {
        if (left == right) {
            return nodes[stIndex].assignLeaf(arr[left]);
        }
        const uint32_t lc = (stIndex << 1), rc = lc + 1, mid = ((left + right) >> 1);
        buildTree(arr, lc, left, mid);
        buildTree(arr, rc, mid + 1, right);
        nodes[stIndex].mergeNode(nodes[lc], nodes[rc]);
    }

    V query(uint32_t stIndex, uint32_t left, uint32_t right, uint32_t lo, uint32_t hi) {
        if (left == lo && right == hi) {
            return nodes[stIndex];
        }
        const uint32_t lc = (stIndex << 1), rc = lc + 1, mid = ((left + right) >> 1);
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

    uint32_t sgtsz(uint32_t N) {
        uint32_t size = 1u; for(; size < N; size <<= 1u);return size << 1u;
    }

    void update(uint32_t stIndex, uint32_t left, uint32_t right, uint32_t index, T value) {
        if (left == right) {
            return nodes[stIndex].assignLeaf(value);
        }
        const uint32_t lc = (stIndex << 1), rc = lc + 1, mid = ((left + right) >> 1);
        if (index <= mid) {
            update(lc, left, mid, index, value);
        } else {
            update(rc, mid + 1, right, index, value);
        }
        nodes[stIndex].mergeNode(nodes[lc], nodes[rc]);
    }
public:
    SegmentTree(const vector < T > & arr, const uint32_t sz) {
        this -> N = sz;
        nodes.resize(sgtsz(this -> N) + 5);
        buildTree(arr, 1, 0, N - 1);
    }
    SegmentTree(const vector<T>& arr):SegmentTree(arr, (uint32_t) arr.size()){}
    SegmentTree(const uint32_t sz){
        this -> N = sz;
        nodes.resize(sgtsz(this -> N) + 5);
    }
    void assign(const vector<T>& arr){
        assert(nodes.size() >= sgtsz(arr.size()));
        this -> N = (uint32_t)arr.size();
        buildTree(arr, 1, 0, N - 1);
    }
    V query(uint32_t lo, uint32_t hi) {
        assert(0 <= lo); assert(hi < N); assert(lo <= hi);
        return query(1, 0, N - 1, lo, hi);
    }

    void update(uint32_t index, T value) {
        assert(0 <= index and index < this->N);
        update(1, 0, N - 1, index, value);
    }
};

struct Node {
    int32_t neg = 0, pos = 0, zero = 0;
    void mergeNode(Node& LC, Node& RC) {
        this -> neg = LC.neg + RC.neg;
        this -> pos = LC.pos + RC.pos;
        this -> zero = LC.zero + RC.zero;
    }
    void assignLeaf(int32_t val) {
        this -> neg = (val < 0);
        this -> pos = (val > 0);
        this -> zero = (val == 0);
    }
};

/**
 * 
 * @SegmentTree<int, Node> tree(arr);
 * @SegmentTree<int, Node> tree(arr, size);
 * 
 * @Zero-based indexing for Query and Update
 * 
 * @Range Query     @tree.query(l, r);
 * @Point Update    @tree.update(i, value);
 * 
 * */ 

/*******************************************************/



const int maxn5 = (1 * 1e5) + 69;
const int maxn6 = (1 * 1e6) + 69;
const int mod7 = (1e9 + 7);
const int mod9 = 998244353;
const int oo = INT_MAX;
const ll OO = LLONG_MAX;
void precompute(){}
void brutforce(){}
void solve([[maybe_unused]] const int case_no){
    int n, k;
    while(cin >> n >> k){
        vector<int32_t>v(n);
        for(int32_t& i : v){
            cin >> i;
        }
        SegmentTree<int32_t, Node> tree(v);
        string res = "";
        while(k--){
            char x;
            int32_t l, r;
            cin >> x >> l >> r;
            if(x == 'C'){
                tree.update(l -1, r);
            }else{
                Node q = tree.query(l - 1, r -1);
                if(q.zero != 0){
                    res += '0';
                }else if(q.neg & 1){
                    res += '-';
                }else{
                    res += '+';
                }
            }
        }
        cout << res << '\n';
    }
    Node x;
    dbg(sizeof(x) / sizeof(int32_t));
}
