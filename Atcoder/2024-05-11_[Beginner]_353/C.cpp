#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL 
#include <debug.h>
#else
#define dbg(...)
#endif

#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define has(v, x) ((v.find(x) != v.end()))
typedef long double ld;
typedef pair<int, int> pii;
#define int int64_t

const int mod = 100000000;

int64_t brut(auto& v){
    int n = len(v);
    int64_t res = 0;    
    for(int i = 0; i < n; ++i) for(int j = i + 1; j < n; ++j){
        res += (v[i] + v[j]) % mod;
    }
    return res;
}
template < class T, class V >
class SegmentTree {
private:
    V * nodes;
    int N;

public:
    SegmentTree(const vector < T > & arr, const int sz) {
        this -> N = sz;
        nodes = new V[getSegmentTreeSize(this -> N)];
        buildTree(arr, 1, 0, N - 1);
    }
    SegmentTree(const vector<T>& arr):
        SegmentTree(arr, (int) arr.size()){}
    ~SegmentTree() {
        delete[] nodes;
    }

    pair<int, long long>  query(int lo, int hi, int k) {
        assert(0 <= lo); assert(hi < N); assert(lo <= hi);
        return query(1, 0, N - 1, lo, hi, k);
    }

    void update(int index, T value) {
         assert(0 <= index); assert(index < N);
        update(1, 0, N - 1, index, value);
    }

    private:
        void buildTree(const vector < T > & arr, int stIndex, int lo, int hi) {
            if (lo == hi) {
                nodes[stIndex].assignLeaf(arr[lo]);
                return;
            }

            int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
            buildTree(arr, left, lo, mid);
            buildTree(arr, right, mid + 1, hi);
            nodes[stIndex].merge(nodes[left], nodes[right]);
        }

    pair<int, long long>  query(int stIndex, int left, int right, int lo, int hi, int k) {
        if (left == lo && right == hi) {
            return nodes[stIndex].query(k);
        }
        int mid = (left + right) / 2;
        if (lo > mid) {
            return query(2 * stIndex + 1, mid + 1, right, lo, hi, k);
        }
        if (hi <= mid) {
            return query(2 * stIndex, left, mid, lo, hi, k);
        }

        pair<int, long long> leftResult = query(2 * stIndex, left, mid, lo, mid, k);
        pair<int, long long> rightResult = query(2 * stIndex + 1, mid + 1, right, mid + 1, hi, k);
        return make_pair(leftResult.first + rightResult.first, leftResult.second + rightResult.second);

    }

    int getSegmentTreeSize(int N) {
        int size = 1;
        for (; size < N; size <<= 1);
        return size << 1;
    }

    void update(int stIndex, int lo, int hi, int index, T value) {
        if (lo == hi) {
            return nodes[stIndex].assignLeaf(value);
        }

        int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
        if (index <= mid) {
            update(left, lo, mid, index, value);
        } else {
            update(right, mid + 1, hi, index, value);
        }
        nodes[stIndex].merge(nodes[left], nodes[right]);
    }
};

struct STNode {

    vector<long long>vec;
    vector<long long>pref;

    void merge(const STNode& LC,const STNode& RC) {
        const auto& vl = LC.vec, vr = RC.vec;
        
        this -> vec.resize(vl.size() + vr.size());
        
        std::merge(vl.begin(), vl.end(), vr.begin(), vr.end(), this->vec.begin());
        
        this -> pref = this -> vec;
        
        partial_sum(this->pref.begin(), this->pref.end(), this->pref.begin());
    }

    pair<int, long long> query(int k) {
        int indx = (upper_bound(this->vec.begin(), this->vec.end(), k) - this->vec.begin()) - 1;
        return make_pair(indx + 1, this->pref[indx]);
    }

    void assignLeaf(int val) {
        this -> vec = vector<long long>({val});
        this -> pref = vector<long long>({val});
    }
};


int64_t fn(vector<int>& v){
    const int n = len(v);
    vector<int64_t>pf(n);
    pf[0] = v[0];
    for(int i = 1; i < n; ++i){
        pf[i] = pf[i - 1] + v[i];
    }
    SegmentTree<int, STNode> sgt(v);
    int64_t res = 0;
    for(int i = 0; i + 1 < n; ++i){
        int tg = mod - v[i] - 1;
        auto [cnt, sum] = sgt.query(i + 1, n - 1, tg);
        res += (cnt * v[i]) + sum;

        int big = (n - i) - cnt - 1;
        
        int bigsum = (pf.back() - pf[i]) - sum;
        
        int tot = ((big * v[i]) + bigsum) - (big * mod);
        res += tot;

    }
    return res;
}
void solve(const int& case_no){
    int n;
    cin >> n;
    vector<int>v(n);
    for(int& i : v){
        cin >> i;
    }
    
    dbg(brut(v) == fn(v));

    cout << fn(v) << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0); 
    dbg(ok());
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        dbg(kes(tc));
        solve(tc);
    }
    dbg(bye());
}
