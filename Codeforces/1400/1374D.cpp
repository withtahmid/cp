/**
 *
 * Author: withtahmid
 *
 **/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...)
#define dbg(...)
#define init(...)
#endif
#define endl '\n'
#define pb push_back
#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define has(x, y) (x.find(y) != x.end())
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
inline auto _max(const auto f, const auto... r){return max({f, r...});}
inline auto _min(const auto f, const auto... r){return min({f, r...});}
inline void print(const auto &...a) { ((cout << a), ...); }
inline void println(const auto &...a) { print(a..., '\n'); }
inline void read(vector<auto>& v) {for(auto& i : v){ cin >> i;}}
inline void read(deque<auto>& v) {for(auto& i : v){ cin >> i;}}
inline bool read(auto &...a) { return (((cin >> a) ? true : false) && ...);}
void solve(int);
void precompute();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init();
    precompute();
    bool test_case = not true;
    int tc = 1; if(test_case){cin >> tc;}
    for(int i = 1; i <= tc; ++i){
        solve(i);
    }
    dbg(__elapsed__());
}
/**************************************************/
template<class T, class V>
class SegmentTree {
  V* nodes;
  int N;

public:
  SegmentTree(const vector<T>&arr) {
    this -> N = (int)arr.size();
    nodes = new V[getSegmentTreeSize(this->N)];
    buildTree(arr, 1, 0, N-1);
  }
  
  ~SegmentTree() {
    delete[] nodes;
  }
  
  V query(int lo, int hi) {
    V result = query(1, 0, N-1, lo, hi);
    return result.query();
  }
  
  void update(int index, T value) {
    update(1, 0, N-1, index, value);
  }
  
  private:  
  void buildTree(const vector<T>&arr, int stIndex, int lo, int hi) {
    if (lo == hi) {
      nodes[stIndex].assignLeaf(arr[lo]);
      return;
    }
    
    int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
    buildTree(arr, left, lo, mid);
    buildTree(arr, right, mid + 1, hi);
    nodes[stIndex].merge(nodes[left], nodes[right]);
  }
  
  V query(int stIndex, int left, int right, int lo, int hi) {
    if (left == lo && right == hi){
      return nodes[stIndex];
    }
    int mid = (left + right) / 2;
    if (lo > mid){
      return query(2*stIndex+1, mid+1, right, lo, hi);
    }
    if (hi <= mid){
      return query(2*stIndex, left, mid, lo, hi);
    }
        
    V leftResult = query(2*stIndex, left, mid, lo, mid);
    V rightResult = query(2*stIndex+1, mid+1, right, mid+1, hi);
    V result;
    result.merge(leftResult, rightResult);
    return result;
  }
  
  int getSegmentTreeSize(int N) {
    int size = 1;
    for (; size < N; size <<= 1);
    return size << 1;
  }
  
  void update(int stIndex, int lo, int hi, int index, T value) {
    if (lo == hi) {
    nodes[stIndex].assignLeaf(value);
    return;
    }
    
    int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
    if (index <= mid){
      update(left, lo, mid, index, value);
    }
    else{
      update(right, mid+1, hi, index, value);
    }
    nodes[stIndex].merge(nodes[left], nodes[right]);
  }
};

/*************************************/ 

struct Node{
    
    long long sum;
    
    void merge(Node a, Node b){
        this -> sum = a.sum + b.sum;
    }

    Node query(){
        return *this;
    }

    void assignLeaf(auto val){
        this -> sum = val;
    }
};

/**************************************************************/ 

const int maxn = (2 * 1e5) + 69;
const int oo = INT_MAX;
void precompute(){}
vector<int>graph[maxn];
vector<ll>score(maxn);
vector<ll>num_chield(maxn);
vector<bool>visited(maxn);
vector<int>dfs_order(maxn);
int dfs_timer = 0;
int dfs(int n){
    visited[n] = true;
    int chield = 1;
    dfs_order[n] = dfs_timer ++;
    for(auto i : graph[n]){
        if(not visited[i]){
           chield += dfs(i);
        }
    }
    return num_chield[n] = chield;
}
void solve(const int case_no){
    int n, q;
    read(n, q);
    for(int i = 0; i < n; ++i){
        read(score[i]);
    }
    for(int i = 0; i + 1 < n; ++i){
        int u, v;
        read(u, v);
        --u, --v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(0);
    vector<int>arr(n);
    for(int i = 0; i < n; ++i){
        arr[dfs_order[i]] = score[i];
    }
    SegmentTree<int, Node> segTree(arr);
    while(q--){
        int mode, l;
        read(mode, l);
        if(mode == 1){
            int val;
            read(val);
            segTree.update(dfs_order[l-1], val);
        }
        else{
            int left = dfs_order[l - 1];
            int right = left + num_chield[l - 1] - 1;
            println(segTree.query(left, right).sum);
        }
    }
}
