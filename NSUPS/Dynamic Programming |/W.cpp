#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

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
        this -> nodes = vector<V>(sgtsz(sz));
    }
    void assign(const vector<T>& arr){
        this -> N = (int)arr.size();
        buildTree(arr, 1, 0, this -> N - 1);
    }
    V query(int lo, int hi) {
        return query(1, 0, this -> N - 1, lo, hi);
    }

    void update(int index, T value) {
        update(1, 0, this -> N - 1, index, value);
    }
};

struct STNode {
    int res = 0LL;
    void mergeNode(STNode& LC, STNode& RC) {
        this -> res = max(LC.res, RC.res);
    }
    void assignLeaf(int val) {
        this -> res = val;
    }
};


const int N = 1e5 + 69;
int fr_dp[N], rv_dp[N];

void lis_table(vector<int>& v){
    
    const int n = int(v.size());
    
    vector<pair<int, int>> a(n), b(n);
    
    for(int i = 0; i < n; ++i){
        a[i].first = v[i], a[i].second = i; 
        b[i].first = v[i], b[i].second = n - i - 1; 
    }

    auto srt = [](vector<pair<int, int>>& v){
        sort(v.begin(), v.end(), [&](pair<int, int> x, pair<int, int> y){
            if(x.first == y.first){
                return x.second > y.second;
            }
            return x.first < y.first;
        });
    };

    srt(a),  srt(b);

    SegmentTree<int, STNode> fr_sgTree(n), rv_sgTree(n);
    
    for(int i = 0; i < n; ++i){
        
        int fr_res = fr_sgTree.query(0, a[i].second).res;
        fr_dp[a[i].second] = fr_res + 1;
        fr_sgTree.update(a[i].second, fr_dp[a[i].second]);

        int rv_res = rv_sgTree.query(0, b[i].second).res;
        rv_dp[n - b[i].second - 1] = rv_res + 1;
        rv_sgTree.update(b[i].second, rv_dp[n - b[i].second - 1]);
    }
} 

void solve(int& tc){
    int n;
    while(cin >> n){

        vector<int>v(n);
        for(int& i :  v){
            cin >> i;
        }

        lis_table(v);

        int res = 0;
        for(int i = 0; i < n; ++i){
            res = max(res, (min(fr_dp[i], rv_dp[i]) * 2) - 1);
        }
        
        cout << res << '\n';
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
