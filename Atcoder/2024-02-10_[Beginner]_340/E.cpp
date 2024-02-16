/**
 *
 * Author: withtahmid
 * Created: 2024-02-10 17:49:14
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
    bool test_case = not true;
    int tc = 1; if(test_case){read(tc);}
    for(int i = 1; i <= tc; ++i){
        dbg(__case__(i));
        solve(i);
    }
    dbg(__elapsed__());
    return 0;
}
const int maxn5 = (1 * 1e5) + 69;
const int maxn6 = (1 * 1e6) + 69;
const int mod7 = (1e9 + 7);
const int mod9 = 998244353;
const int oo = INT_MAX;
const ll OO = LLONG_MAX;
void precompute(){}
void brutforce(){}

/*******************************************************/

template < class T, class V >
class LazySegmentTree {
private:
    V * nodes;
    int N;
public:
    LazySegmentTree(const vector < T > & arr, const int sz) {
        this -> N = sz;
        nodes = new V[getSegmentTreeSize(this -> N + 5)];
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
    void buildTree(const vector < T > & arr, int stIndex, int lo, int hi) {
        if (lo == hi) {
            nodes[stIndex].assignLeaf(arr[lo], lo, hi);
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
        const int mid = (left + right) / 2;
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

    int getSegmentTreeSize(int N) {
        int size = 1;for (; size < N; size <<= 1);return size << 1;
    }
    void updateRange(int stIndex, int left, int right, int lo, int hi, T val) {
        nodes[stIndex].propagate();
        if (left == lo and right == hi) {
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
        nodes[stIndex].merge(nodes[left], nodes[right]);
    }
};

/******************/

struct Node {
    int left = -1, right = -1;
    Node* leftChild = nullptr;
    Node* rightChild = nullptr;
    void buildMerge(Node& leftC, Node& rightC) {
         this -> leftChild = &leftC;this -> rightChild = &rightC;
         this -> left = leftC.left; this -> right = rightC.right;
         this -> merge(leftC, rightC);
    }
    Node query(){
        return * this;
    }
    int length(){
        return ((this -> right - this -> left ) + 1);
    }
    void assignLeaf(auto val, int lo, int hi) {
        this -> left = lo, this -> right = hi; this -> assignLeaf(val);
    }
    /*-------------------------------------------------------------*/ 

    long long sum = 0LL;
    long long lazy = 0LL;

    void propagate(){
        this -> sum += (this -> length()) * lazy;
        if(left != right){
            leftChild -> lazy += this->lazy;
            rightChild -> lazy += this->lazy;
        }
        this -> lazy = 0LL;
    }
    void update(auto val){
        this -> sum += val * (this -> length());
        if(left != right){
            this -> leftChild -> lazy += val;
            this -> rightChild -> lazy += val;
        }
    }
    void merge(Node leftC, Node rightC) {
         this -> sum = leftC.sum + rightC.sum;
    }
    void assignLeaf(auto val){
        this -> sum = val;
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

void solve([[maybe_unused]] const int case_no){
    int n, m;
    read(n, m);
    vector<int>a(n), b(m);
    read(a, b);
    LazySegmentTree<int, Node> tree(a);

    for(int i = 0; i < m; ++i){
        int ball = tree.query(b[i], b[i]).sum;
        tree.update(b[i], b[i] , -1LL * ball);
        tree.update(0, n - 1, ball / n);
        ball %= n;
        if(ball != 0){
            ll mnn = min(n - b[i] - 1, ball);
            ball -= mnn;
            if(b[i] + 1 < n){
                tree.update(b[i] + 1, b[i] + mnn, 1);
            }
            if(ball != 0){
                tree.update(0, ball - 1, 1);
            }
        }
    }

    for(int i = 0; i < n; ++i){
        print(tree.query(i, i).sum, " ");
    }
    println();
}
