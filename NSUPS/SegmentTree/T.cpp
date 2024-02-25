/**
 *
 * Author: withtahmid
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
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
// inline void print(const auto& a){cout<<a;}
// inline void print(const vector<auto>& v){for(auto&i:v){print(i);print(" ");}}
// inline void print(const auto &...a) {((print(a)), ...);}
// inline void println(const auto &...a) {print(a..., '\n');}
// inline bool read(auto& x){return(cin >> x) ? true : false;}
// inline bool read(pair<auto, auto>& p){ return (read(p.first) and read(p.second));}
// inline bool read(vector<auto>& v) {bool x = true; for(auto&i:v){x&=read(i);} return x;}
// inline bool read(auto &...a) {return (((read(a))?true:false)&&...);}
// inline string kes(int k){return("Case "+to_string(k)+": ");}
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
    bool test_case = not true;
    int tc = 1; if(test_case){cin >> tc;}
    for(int i = 1; i <= tc; ++i){
        dbg(__case__(i));
        solve(i);
    }
    dbg(__elapsed__());
}
const int maxn5 = (1 * 1e5) + 69;
const int maxn6 = (1 * 1e6) + 69;
const int mod = (1e9 + 7); //998244353
const int oo = ((1ULL << 31) - 1);
const  ll OO = ((1ULL << 63) - 1);
void precompute(){}
void brutforce(){}
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

    int query(int lo, int hi, int k) {
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

    int query(int stIndex, int left, int right, int lo, int hi, int k) {
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

        int leftResult = query(2 * stIndex, left, mid, lo, mid, k);
        int rightResult = query(2 * stIndex + 1, mid + 1, right, mid + 1, hi, k);
       	return leftResult + rightResult;
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

    vector<int>vec;
    void merge(const STNode& LC,const STNode& RC) {
    	const auto& vl = LC.vec, vr = RC.vec;
        int i = 0, j = 0;
        while(i < vl.size() and j < vr.size()){
        	if(vl[i] < vr[j]){
        		this->vec.push_back(vl[i++]);
        	}else{
        		this->vec.push_back(vr[j++]);
        	}
        }
        while( i < vl.size()){
        	this-> vec.push_back(vl[i ++]);
        }
        while(j < vr.size()){
        	this -> vec.push_back(vr[j ++]);
        }
    }

    int query(int k) {
        auto lb = lower_bound(this->vec.begin(), this->vec.end(), k + 1 );
        return (this->vec.end() - lb);
    }

    void assignLeaf(int val) {
        this -> vec.push_back(val);
    }
};

void solve([[maybe_unused]] const int& case_no){
    int n;
    cin >> n;
    vector<int>v(n);
    for(int& i : v){
    	cin >> i;
    }
    SegmentTree<int, STNode> sgt(v);
    int q;
    cin >> q;
    while(q--){
    	int l, r, k;
    	cin >> l >> r >> k;
    	cout << sgt.query(l - 1, r - 1, k) << "\n";
    }
}
