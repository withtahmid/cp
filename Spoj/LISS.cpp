#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

const int N = 1e5 + 69, mod = 1000000007;

template < class T, class V >
class SegmentTree {
private:
    vector<V>nodes;
    int N;
    void buildTree(const vector < T > & arr, int stIndex, int left, int right) {
        if (left == right) {
            return nodes[stIndex].assignLeaf(arr[left]);
        }
        const int lc = (stIndex << 1), rc = lc | 1, mid = ((left + right) >> 1);
        buildTree(arr, lc, left, mid);
        buildTree(arr, rc, mid + 1, right);
        nodes[stIndex].mergeNode(nodes[lc], nodes[rc]);
    }

    V query(int stIndex, int left, int right, int lo, int hi) {
        if (left == lo && right == hi) {
            return nodes[stIndex];
        }
        const int lc = (stIndex << 1), rc = lc | 1, mid = ((left + right) >> 1);
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
    int sgtsz(int N) {int x = 1u; for(; x < N; x <<= 1u);return x << 1u;}
    void update(int stIndex, int left, int right, int index, T value) {
        if (left == right) {
            return nodes[stIndex].assignLeaf(value);
        }
        const int lc = (stIndex << 1), rc = lc | 1, mid = ((left + right) >> 1);
        if (index <= mid) {
            update(lc, left, mid, index, value);
        } else {
            update(rc, mid + 1, right, index, value);
        }
        nodes[stIndex].mergeNode(nodes[lc], nodes[rc]);
    }
public:
    SegmentTree(const vector < T > & arr, const int sz) {
        this -> N = sz;
        nodes.resize(sgtsz(this -> N) + 5);
        buildTree(arr, 1, 0, this -> N - 1);
    }
    SegmentTree(const vector<T>& arr):SegmentTree(arr, (int) arr.size()){}
    SegmentTree(const int sz){
        this -> N = sz;
        nodes.resize(sgtsz(this -> N) + 5);
    }
    void assign(const vector<T>& arr){
        assert(nodes.size() >= sgtsz(arr.size()));
        this -> N = (int)arr.size();
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

struct CNT {
    int64_t res = 0LL;
    void mergeNode(CNT& LC, CNT& RC) {
        this -> res = (LC.res + RC.res) % mod;
    }
    void assignLeaf(int64_t val) {
        this -> res = val;
    }
};

struct MAX {
    int res = 0LL;
    void mergeNode(MAX& LC, MAX& RC) {
        this -> res = max(LC.res, RC.res);
    }
    void assignLeaf(int val) {
        this -> res = val;
    }
};

vector<int>t(int(N), 0);

int n;

void run_case(){
    vector<pair<int, int>> a(n);
    vector<int>dp(n, 0), dp2(n, 0);
    for(int i = 0; i < n; ++i){
        cin >> a[i].first, a[i].second = i; 
    }

    auto b = a;
    reverse(b.begin(), b.end());
    SegmentTree<int, MAX> mx(t), mx2(t);
    
    for(int i = 0; i < n; ++i){
        int res_1 = mx.query(0, a[i].first - 1).res;
        dp[i] = res_1 + 1;
        mx.update(a[i].first, dp[i]);

        int res_2 = mx2.query(0, b[i].first - 1).res;
        dp2[i] = res_2 + 1;
        mx2.update(b[i].first, dp2[i]);
    }
    reverse(dp2.begin(), dp2.end());
    int res = 1;
    for(int i = 0; i <= n; ++i){
        if(dp[i] == dp2[i]){
            res = max(res, dp[i]);
        }
    }
    cout << (2 * res) - 1 << '\n';
} 

void solve(int& tc){
    while(cin >> n){
        run_case();
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
