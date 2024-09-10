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
#define int int64_t
typedef long double ld;
typedef pair<int64_t, int64_t> pii;

template < class T, class V >
class SegmentTree {
private:
    vector<V>nodes;
    int N;
    void buildTree(const vector < T > & arr, int stindx, int left, int right) {
        if (left == right) {
            return nodes[stindx].assignLeaf(arr[left]);
        }
        const int lc = (stindx << 1), rc = lc | 1, mid = ((left + right) >> 1);
        buildTree(arr, lc, left, mid);
        buildTree(arr, rc, mid + 1, right);
        nodes[stindx].mergeNode(nodes[lc], nodes[rc]);
    }

    V query(int stindx, int left, int right, int lo, int hi) {
        if (left == lo && right == hi) {
            return nodes[stindx];
        }
        const int lc = (stindx << 1), rc = lc | 1, mid = ((left + right) >> 1);
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
    void update(int stindx, int left, int right, int indx, T value) {
        if (left == right) {
            return nodes[stindx].assignLeaf(value);
        }
        const int lc = (stindx << 1), rc = lc | 1, mid = ((left + right) >> 1);
        if (indx <= mid) {
            update(lc, left, mid, indx, value);
        } else {
            update(rc, mid + 1, right, indx, value);
        }
        nodes[stindx].mergeNode(nodes[lc], nodes[rc]);
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
        assert(nodes.size() >= sgtsz(arr.size()));
        this -> N = (int)arr.size();
        buildTree(arr, 1, 0, this -> N - 1);
    }
    V query(int lo, int hi) {
        assert(0 <= lo); assert(hi < (int)this -> N); assert(lo <= hi);
        return query(1, 0, this -> N - 1, lo, hi);
    }

    void update(int indx, T value) {
        assert(0 <= indx and indx < (int)this -> N);
        update(1, 0, this -> N - 1, indx, value);
    }
};

struct Count {
    
    int p_cnt = 0, t_cnt = 0;
    
    void mergeNode(Count& LC, Count& RC) {
        this -> p_cnt = LC.p_cnt + RC.p_cnt;
        this -> t_cnt = LC.t_cnt + RC.t_cnt;
    }

    void assignLeaf(pii x) {
        p_cnt = x.first > x.second;
        t_cnt = x.first < x.second;
    }

};




struct Sum{
    
    int64_t sum_p = 0;
    int64_t sum_t = 0;
    void mergeNode(Sum& LC, Sum& RC) {
       this -> sum_p = LC.sum_p + RC.sum_p;
       this -> sum_t = LC.sum_t + RC.sum_t;
    }
    void assignLeaf(pii x) {
        this -> sum_p = x.first; 
        this -> sum_t = x.second;
    }
};

struct Programmer {
     int64_t sum = 0;
    void mergeNode(Programmer& LC, Programmer& RC) {
       this -> sum = LC.sum + RC.sum;
    }
    void assignLeaf(pii x) {
        this -> sum = x.first > x.second ? x.first : 0; 
    }
};

struct Tester {
    
    int64_t sum = 0;

    void mergeNode(Tester& LC, Tester& RC) {
       this -> sum = LC.sum + RC.sum;
    }
    void assignLeaf(pii x) {
        this -> sum = x.first < x.second ? x.second : 0; 
    }
};


void solve(const int& tc){
    int n, m;
    cin >> n >> m;
    int ln = n + m + 1;
    vector<pii>v(ln + 5, {0, 0});
    
    for(int i = 1; i <= ln; ++i){
        cin >> v[i].first;
    }
    for(int i = 1; i <= ln; ++i){
        cin >> v[i].second;
    }

    pii zero = {0, 0};

    SegmentTree<pii, Count> cnt(v);
    SegmentTree<pii, Sum> sum(v);
    SegmentTree<pii, Programmer> programmer(v);
    SegmentTree<pii, Tester> tester(v);

    auto programmerIdx = [&](){
        int l = 0, r = ln + 1;
        int indx = ln + 1;
        while(l <= r){
            int mid = (l + r) / 2;
            auto res = cnt.query(0, mid);
            if(res.p_cnt >= n){
                r = mid - 1;
                indx = min(indx, mid);
            }else{
                l = mid + 1;
            }
        }
        return indx;
    };

    auto testerIdx = [&](){
        int l = 0, r = ln + 1;
        int indx = ln + 1;
        while(l <= r){
            int mid = (l + r) / 2;
            auto res = cnt.query(0, mid);
            if(res.t_cnt >= m){
                r = mid - 1;
                indx = min(indx, mid);
            }else{
                l = mid + 1;
            }
        }
        return indx;
    };

    vector<int64_t> res(ln + 10);

    for(int i = 1; i <= ln; ++i){
        cnt.update(i, zero), programmer.update(i, zero), tester.update(i, zero), sum.update(i, zero);
        int pi = programmerIdx();
        int ti = testerIdx();
        int64_t ans = 0;
        
        if(pi < ti){
            auto sum_p = programmer.query(0, pi).sum;
            auto sum_t = tester.query(0, pi).sum;
            
            auto sum_r = sum.query(pi + 1, ln + 1).sum_t;
            ans = sum_p + sum_t + sum_r;
        }else{
            auto sum_p = programmer.query(0, ti).sum;
            auto sum_t = tester.query(0, ti).sum;
            auto sum_r = sum.query(ti + 1, ln + 1).sum_p;
            ans = sum_p + sum_t + sum_r;
        }
        
        res[i] = ans;

        cnt.update(i, v[i]), programmer.update(i, v[i]), tester.update(i, v[i]), sum.update(i, v[i]);
    }
    
    for(int i = 1; i <= ln; ++i){
        cout << res[i] << ' ';
    }

    cout << '\n';

}

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0); 
    dbg(ok());
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        dbg(kes(tc));
        solve(tc);
    }
    dbg(bye());
}
