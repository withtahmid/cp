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

/*******************************************************/

template < class T, class V >
class LazySegmentTree {
private:
    V * nodes;
    int N;
public:
    LazySegmentTree(const vector < T > & arr, const int sz) {
        this -> N = sz;
        nodes = new V[this->getSegmentTreeSize(this -> N + 5)];
        buildTree(arr, 1, 0, N - 1);
    }

    LazySegmentTree(const vector< T >& arr)
        :LazySegmentTree(arr, (int)arr.size()){}
    ~LazySegmentTree() {
        delete[] nodes;
    }

    V query(int lo, int hi) {
        assert(0 <= lo); assert(hi < N); assert(lo <= hi);
        return query(1, 0, N - 1, lo, hi).query();
    }

    void update(int lo, int hi, T value){
        assert(0 <= lo); assert(hi < N); assert(lo <= hi);
        updateRange(1, 0, N - 1, lo, hi, value);
    }

private:
    int getSegmentTreeSize(int N) {
        int size = 1;for(; size < N; size <<= 1);return size << 1;
    }
    void buildTree(const vector < T > & arr, int stIndex, int lo, int hi) {
        if (lo == hi) {
            nodes[stIndex].assignLeaf(arr[lo], lo);
            return;
        }

        int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
        buildTree(arr, left, lo, mid);
        buildTree(arr, right, mid + 1, hi);
        nodes[stIndex].buildMerge(nodes[left], nodes[right]);
    }

    V query(int stIndex, int left, int right, int lo, int hi) {
        nodes[stIndex].propagate();
        if (left == lo && right == hi) {
            return nodes[stIndex];
        }
        int mid = (left + right) / 2;
        if (lo > mid) {
            return query(2 * stIndex + 1, mid + 1, right, lo, hi);
        }
        if (hi <= mid) {
            return query(2 * stIndex, left, mid, lo, hi);
        }

        V leftResult = query(2 * stIndex, left, mid, lo, mid);
        V rightResult = query(2 * stIndex + 1, mid + 1, right, mid + 1, hi);
        V result;
        result.merge(leftResult, rightResult);
        return result;
    }

    void updateRange(int stIndex, int left, int right, int lo, int hi, T val) {
        nodes[stIndex].propagate();
        if (left == lo && right == hi) {
            return nodes[stIndex].update(val);
        }
        const int mid = (left + right) / 2;
        if (lo > mid) {
            updateRange(2 * stIndex + 1, mid + 1, right, lo, hi, val);
        }
        else if (hi <= mid) {
            updateRange(2 * stIndex, left, mid, lo, hi, val);
        }
        else{
            updateRange(2 * stIndex, left, mid, lo, mid, val);
            updateRange(2 * stIndex + 1, mid + 1, right, mid + 1, hi, val);
        }
        nodes[stIndex].merge(nodes[2 * stIndex], nodes[2 * stIndex + 1]);
    }
};

/******************/

struct Node {
    ll left = -1, right = -1;
    Node* leftChild = nullptr;
    Node* rightChild = nullptr;
    void buildMerge(Node& leftC, Node& rightC) {
        this -> leftChild = &leftC;
        this -> rightChild = &rightC;
        this -> left = leftC.left; 
        this -> right = rightC.right;
        this -> merge(leftC, rightC);
    }
    Node query(){
        return * this;
    }
    long long length(){
        return ((this -> right - this -> left ) + 1LL);
    }
    bool isLeaf(){
        return (left == right);
    }
    void assignLeaf(auto val, int idx) {
        this -> left =  this -> right = idx; this -> assignLeaf(val);
    }
    /*-----------------------------------------------------------------*/ 

    ll sum = 0LL;
    ll lazy = 0LL;

    void propagate(){
        assert(left != -1 and right != -1);
        this -> sum += ((this -> length()) * this -> lazy);
        if(not this -> isLeaf()){
            leftChild -> lazy += this->lazy;
            rightChild -> lazy += this->lazy;
        }
        this -> lazy = 0LL;
    }
    void update(ll val){
        assert(left != -1 and right != -1);
        this -> sum += (val * (this -> length()));
        if(not this->isLeaf()){
            this -> leftChild -> lazy += val;
            this -> rightChild -> lazy += val;
        }
    }
    void merge(Node leftC, Node rightC) {
        this -> sum = leftC.sum + rightC.sum;
    }
    void assignLeaf(ll val){
        this -> sum = val;
        this -> lazy = 0LL;
    }
};

/**
 * 
 * @LazySegmentTree<int, Node> tree(arr);
 * @LazySegmentTree<int, Node> tree(arr, size);
 * 
 * @Zero-based indexing for Query and Update
 * 
 * @Range Query     @tree.query(l, r);
 * @Range Update    @tree.update(l, r, value);
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
template < class T > T scan(){T t; cin >> t; return t;} 
#define kes(x) "Case " + to_string(x) + ":"
void solve([[maybe_unused]] const int case_no){
    println(kes(case_no));
    int n, q;
    read(n, q);
    LazySegmentTree<ll, Node> segTree(vector<ll>(n, 0LL));
    // for(int i = 0; i < 50000; ++i){
    //     segTree.update(0, n -1, 1000);
    // }
    // dbg(segTree.query(0, n /2).sum);
    while(q--){
        int op, l, r;
        read(op, l, r);
        if(op == 0LL){
            segTree.update(l, r, scan<int>());
        }else{
            println(segTree.query(l, r).sum);
        }
    }
    // map<int, int>mp;
    // for(int i = 100; i < n; ++i){
    //     mp[segTree.query(i - 100, i).sum]++;
    // }
    // dbg(mp);
}
