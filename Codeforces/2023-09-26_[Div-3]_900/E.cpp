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
#define mem(x, y) memset(x, y, sizeof(x))
typedef int_fast64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline constexpr auto max(const auto f, const auto... r){return max({f, r...});}
inline constexpr auto min(const auto f, const auto... r){return min({f, r...});}
inline void operator>>(istream& istream, vector<auto>&v){for(auto& i:v){cin>>i;}}
void solve(int);
void precompute();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init();
    precompute();
    bool test_case = true;
    int tc = 1; if(test_case){cin >> tc;}
    for(int i = 1; i <= tc; ++i){
        solve(i);
    }
    dbg(__elapsed__);
}
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

/*****************************/ 

struct Node{

    ll sum;
    
    void merge(Node a, Node b){
        this -> sum = a.sum & b.sum;
    }

    Node query(){
        return *this;
    }

    void assignLeaf(auto val){
        this -> sum = val;
    }
};
/**************************************************************/ 

void solve(const int case_no){
    int n;
    cin >> n;
    vector<int>v(n);
    cin >> v;
    SegmentTree<int, Node> tree(v);
    int q;
    cin >> q;
    for(int i = 1; i <= q; ++i){
        int left, k;
        cin >> left >> k;
        int l = left - 1, r = n - 1;
        int ans = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            int res = tree.query(left - 1, mid).sum;
            if(res >= k){
                l = mid + 1;
                ans = max(ans, mid);
            }
            else{
                r = mid - 1;
            }
        }
        cout << (ans == -1 ? ans : ans + 1) << " ";
    }
    cout << endl;
}
