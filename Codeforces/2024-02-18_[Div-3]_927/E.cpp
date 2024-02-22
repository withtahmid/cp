/**
 *
 * Author: withtahmid
 * Created: 2024-02-18 18:02:51
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
    bool test_case = true;
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
const ll OO = LLONG_MAX;
void precompute(){}
void brutforce(){}
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
        V result;
        result.merge(query(2 * stIndex, left, mid, lo, mid), query(2 * stIndex + 1, mid + 1, right, mid + 1, hi));
        return result;
    }
    void updateRange(int stIndex, int left, int right, int lo, int hi, T val) {
        nodes[stIndex].propagate();
        if (left > right || left > hi || right < lo){
            return;
        }
        if (left >= lo && right <= hi) {
            return nodes[stIndex].update(val);
        }
        int mid = (left + right) / 2;
        updateRange(2 * stIndex, left, mid, lo, hi, val);
        updateRange(2 * stIndex + 1, mid + 1, right, lo, hi, val);
        nodes[stIndex].merge(nodes[2 * stIndex], nodes[2 * stIndex + 1]);
    }
};

struct Node {
    int leftIndx = -1, rightIndx = -1; 
    Node* leftChild = nullptr; 
    Node* rightChild = nullptr;
    void buildMerge(Node& leftC, Node& rightC) {
        this -> leftChild = &leftC;this -> rightChild = &rightC;
        this -> leftIndx = leftC.leftIndx; 
        this -> rightIndx = rightC.rightIndx;
        this -> merge(leftC, rightC);
    }
    Node query(){return * this;}
    long long nodeLength(){return ((this->rightIndx-this->leftIndx)+1LL);}
    bool isLeaf(){return (leftIndx == rightIndx);}
    void assignLeaf(auto val, int idx) {
        this -> leftIndx =  this -> rightIndx = idx; 
        this -> assignLeaf(val);
    }    

    int sum = 0LL;
    int lazy = 0LL;
    
    void propagate(){
        assert(leftIndx != -1 and rightIndx != -1);
        this -> sum += (this -> lazy);
        if(not this -> isLeaf()){
            leftChild -> lazy += this->lazy;
            rightChild -> lazy += this->lazy;
        }
        this -> lazy = 0LL;
    }
    void update(ll val){
        assert(leftIndx != -1 and rightIndx != -1);
        this -> sum += (val);
        if(not this->isLeaf()){
            this -> leftChild -> lazy += val;
            this -> rightChild -> lazy += val;
        }
    }

    void merge(Node leftC, Node rightC) {
        this -> sum = max(leftC.sum, rightC.sum);
    }
    
    void assignLeaf(ll val){
        this -> sum = val;
        this -> lazy = 0LL;
    }
};

struct Node22 {
    int leftIndx = -1, rightIndx = -1; 
    Node22* leftChild = nullptr; 
    Node22* rightChild = nullptr;
    void buildMerge(Node22& leftC, Node22& rightC) {
        this -> leftChild = &leftC;this -> rightChild = &rightC;
        this -> leftIndx = leftC.leftIndx; 
        this -> rightIndx = rightC.rightIndx;
        this -> merge(leftC, rightC);
    }
    Node22 query(){return * this;}
    long long nodeLength(){return ((this->rightIndx-this->leftIndx)+1LL);}
    bool isLeaf(){return (leftIndx == rightIndx);}
    void assignLeaf(auto val, int idx) {
        this -> leftIndx =  this -> rightIndx = idx; 
        this -> assignLeaf(val);
    }    

    int right_most = 0;
    int lazy = -1;
    void propagate(){
        assert(leftIndx != -1 and rightIndx != -1);
        this -> right_most = max(this -> right_most, this -> lazy);
        if(not this -> isLeaf()){
            this->leftChild->lazy = max(this->leftChild->lazy, this->lazy);
            this->rightChild->lazy = max(this->rightChild->lazy, this->lazy);
        }
        this -> lazy = -1;
    }
    void update(int val){
        assert(leftIndx != -1 and rightIndx != -1);
        this -> right_most = max(this -> right_most, val);
        if(not this->isLeaf()){
            this->leftChild->lazy = max(this->leftChild->lazy, val);
            this->rightChild->lazy = max(this->rightChild->lazy, val);
        }
    }
    void merge(Node22 leftC, Node22 rightC) {
        this -> right_most = max(leftC.right_most, rightC.right_most);
    }
    void assignLeaf(int val){
        this -> right_most = max(this->right_most, val);
        this -> lazy = -1;
    }
};


int dp[maxn6];

int fn(int i, const int n, auto& indexTree, auto& resTree){
    if(i >= n){
        return 0;
    }
    auto& res = dp[i];
    if(res != -1){
        return res;
    }
    res = fn(i + 1, n, indexTree, resTree);
    int r = indexTree.query(i, i).right_most;
    res = max(res, fn(r + 1, n, indexTree, resTree) + resTree.query(i, i).sum);
    return res;
}

void solve([[maybe_unused]] const int& case_no){
    int n, m;
    read(n, m);
    vector<int>idx(n);
    for(int i = 0; i < n; ++i){
        idx[i] = i, dp[i] = -1;
    }

    LazySegmentTree<int, Node> resTree(vector<int>(n, 0));
    LazySegmentTree<int, Node22> indexTree(idx);

    vector<pii>queries(m);
    
    for(auto& p : queries){
        read(p.first, p.second);
        --p.first, --p.second;
    }

    sort(all(queries));

    for(const auto& [l, r] : queries){
        resTree.update(l, r, 1);
        auto rmax = indexTree.query(l, r).right_most;
        indexTree.update(l, r, max(r, rmax));
    }

    println(fn(0, n, indexTree, resTree));
}
