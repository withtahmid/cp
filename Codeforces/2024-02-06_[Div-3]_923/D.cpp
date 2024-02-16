/**
 *
 * Author: withtahmid
 * Created: 2024-02-06 20:41:28
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
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define has(x, y) (x.find(y) != x.end())
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
inline void print(const auto &...a) {((cout << a), ...);}
inline void println(const auto &...a) {print(a..., '\n');}
inline bool read(auto &...a) {return (((cin >> a) ? true : false) && ...);}
inline void read(pair<auto, auto>& p){read(p.first, p.second);}
inline void read(vector<auto>& v) {for(auto& i : v){read(i);}}
void solve(int);
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
    return 0;
}
const int maxn = (2 * 1e5) + 69;
const int mod = (1e9 + 7);
const int oo = INT_MAX;
const ll OO = LLONG_MAX;
void precompute(){}
/**************************************************/
template<class T, class V>
class SegmentTree {
  V* nodes;
  int N;

public:
  SegmentTree(const vector<T>&arr) {
    this -> N = (int)arr.size() + 5;
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
    
    pii min, max;
    
    void merge(Node a, Node b){
        vector<pii> x = { a.min, a.max, b.min, b.max };
        sort(all(x), [](pii p, pii q){
            return p.first < q.first;
        });
        this -> min = x.front();
        this -> max = x.back();   
    }
    Node query(){
        return *this;
    }

    void assignLeaf(auto val){
        min = max = val;
    }
};

// SegmentTree<int, Node> tree(arr);
/**************************************************************/ 
void solve([[maybe_unused]] const int case_no){
    int n;
    read(n);
    vector<pii>v(n);
    for(int i = 0; i < n; ++i){
        read(v[i].first);
        v[i].second = i;
    }
    SegmentTree<pii, Node> tree(v);
    int q;
    read(q);
    while(q--){
        int l, r;
        read(l, r);
        auto res = tree.query(l - 1, r - 1);
        if(res.min.first == res.max.first){
            println("-1 -1");
        }else{
            println(res.min.second + 1 ," ", res.max.second + 1);
        }
    }
}