/**
 *
 * Author: withtahmid
 * Created: 2023-10-13 15:57:51
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
#define mem(x, y) memset(x, y, sizeof(x))
typedef int_fast64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline constexpr auto _max(const auto f, const auto... r){return max({f, r...});}
inline constexpr auto _min(const auto f, const auto... r){return min({f, r...});}
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
    dbg(__elapsed__());
}

const int MAXN = 1e7 + 5;
int spf[MAXN];

void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;

    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

void precompute(){
    sieve();
}

vector<int> factorize(int n)
{
    vector<int> temp;
    int prev = -1;
    while (n != 1)
    {
        if (prev != spf[n]) {
            temp.pb(spf[n]);
            prev = spf[n];
        }
        n = n / spf[n];
    }    
    return temp;
}


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


struct Node{
    int gcd;
    void merge(Node a, Node b){
        this -> gcd = __gcd(a.gcd, b.gcd);
    }

    Node query(){
        return *this;
    }

    void assignLeaf(auto val){
        this -> gcd = val;
    }
};


void solve(const int case_no){
    int n, k;
    cin >> n >> k;
    vector<int>v(n);
    for(int& i : v){
        cin >> i;
    }

    // dbg(v);
    SegmentTree<int, Node> st(v);

    // dbg(factorize(120));

    int res = 0;

    map<int, int>mp;

    for(int l = 0, r = 0; r < n; ++r){
        auto facto = factorize(v[r]);
        for(auto& i : facto){
            ++mp[i];
        }

        while(len(mp) > k){
             auto facto = factorize(v[l]);
             for(auto& i : facto){
                --mp[i];
                if(mp[i] == 0){
                    mp.erase(i);
                }
             }
             ++l;
        }
        if( l <= r and len(mp) == k and st.query(l, r).gcd == 1)

    }
    cout << res << endl;
}