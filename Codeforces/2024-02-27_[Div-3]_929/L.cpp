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
const int mod = (1e9 + 7); //998244353
const int oo = ((1ULL << 31) - 1);
const  ll OO = ((1ULL << 63) - 1);
void precompute(){}
void brutforce(){}


template < class T, class V >
class LazySegmentTree {
private:
    vector<V> nodes;
    uint N;
    V dmy;
    uint sgtsz(uint N) {uint x = 1;for(; x < N; x <<= 1);return x << 1;}
    void buildTree(const vector < T > & arr, uint stIndex, uint left, uint right) {
        if (left == right) {
            return nodes[stIndex].assignLeaf(arr[left]);
        }
        const uint lc = (stIndex << 1), rc = lc | 1, mid = ((left + right) >> 1);
        buildTree(arr, lc, left, mid);
        buildTree(arr, rc, mid + 1, right);
        nodes[stIndex].mergeNode(nodes[lc], nodes[rc]);
    }
    void propagate(uint& stIndex, uint& left, uint& right){
        if(left == right){
            return nodes[stIndex].propagate(left, right, dmy, dmy);
        }
        nodes[stIndex].propagate(left, right,  nodes[stIndex << 1], nodes[(stIndex << 1) + 1]);
    }
    V query(uint stIndex, uint left, uint right, uint lo, uint hi) {
        this-> propagate(stIndex, left, right);
        if (left == lo && right == hi) {
            return nodes[stIndex];
        }
        const uint lc = (stIndex << 1), rc = lc | 1, mid = ((left + right) >> 1);
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
    void updatePoint(uint stIndex, uint left, uint right, uint index, T value) {
        this-> propagate(stIndex, left, right);
        if (left == right) {
            return nodes[stIndex].assignLeaf(value);
        }
        const uint lc = (stIndex << 1), rc = lc | 1, mid = ((left + right) >> 1);
        if (index <= mid) {
            update(lc, left, mid, index, value);
        } else {
            update(rc, mid + 1, right, index, value);
        }
        nodes[stIndex].mergeNode(nodes[lc], nodes[rc]);
    }
    void updateRange(uint stIndex, uint left, uint right, uint lo, uint hi, T val) {
        this-> propagate(stIndex, left, right);
        if (left > right || left > hi || right < lo){
            return;
        }
        const uint lc = (stIndex << 1), rc = lc | 1, mid = ((left + right) >> 1);
        if (left >= lo && right <= hi) {
            bool l = left == right;
           return nodes[stIndex].updateNode(left, right, (l ? dmy : nodes[lc]), (l ? dmy : nodes[rc]), val);
        }
        updateRange(lc, left, mid, lo, hi, val);
        updateRange(rc, mid + 1, right, lo, hi, val);
        nodes[stIndex].mergeNode(nodes[lc], nodes[rc]);
    }
public:
    LazySegmentTree(const uint n){
        this -> N = n;
        nodes.resize(this->sgtsz(this -> N) + 5);
    }
    LazySegmentTree(const vector < T > & arr, const uint sz) {
        this -> N = sz;
        nodes.resize(this->sgtsz(this -> N) + 5);
        buildTree(arr, 1, 0, this -> N - 1);
    }
    LazySegmentTree(const vector< T >& arr):LazySegmentTree(arr, (int)arr.size()){}

    V query(int lo, int hi) {
        return query(1, 0, this -> N - 1, lo, hi);
    }
    void assign(const vector<T>& arr){
        this -> N = (uint)arr.size();
        buildTree(arr, 1, 0, this -> N - 1);
    }
    void set(int index, T value) {
        updatePoint(1, 0, this -> N - 1, index, value);
    }
    void update(int lo, int hi, T value){
        updateRange(1, 0, this -> N - 1, lo, hi, value);
    }
};

struct LSTNode {

    int64_t sum = 0, sqSum = 0, cng = -1, inc = 0;

    // sqSum 	= (a₁² + a₂² + ... + aₙ²) + 2x(a₁ + a₂ + ... + aₙ) + nx²
	// 			= sqSum + 2Sx + nx²

    void propagate(uint& left, uint& right, LSTNode& LC, LSTNode& RC){
    	if(this -> cng != -1){
    		this -> sum = this -> cng * (right - left + 1);
    		this -> sqSum = this -> sum * this -> cng;
    		if(left != right){
    			LC.inc = RC.inc = 0;
    			LC.cng = RC.cng =  this -> cng;
    		}
    	}
    	if(this -> inc != 0){
    		this -> sqSum += (2 * (this -> inc) * this ->sum) + ((right - left + 1) * (this -> inc * this -> inc));
    		if(left != right){
    			LC.inc += this -> inc;
    			RC.inc += this -> inc;
    		}
    	}
    	this -> cng = -1, this -> inc  = 0;
    }
    
    void updateNode(uint& left, uint& right, LSTNode& LC, LSTNode& RC, int64_t val){
    	auto x = val & (~(1ULL << 50)) & (~(1ULL << 51));
    	if(((val >> 50) & 1)){
    		this -> cng = x;
    	}else{
			this -> inc += x;
    	}
        this -> propagate(left, right, LC, RC);
    }
    void mergeNode(LSTNode& LC, LSTNode& RC) {
        this -> sum = (LC.sum + RC.sum);
        this -> sqSum = (LC.sqSum + RC.sqSum);
    }

    void assignLeaf(int64_t val){
        this -> sum = val;
        this -> sqSum = (val * val);
    }
};


void solve([[maybe_unused]] const int& case_no){
    int n, q;
    read(n, q);
    vector<int64_t>v(n);
    read(v);
    LazySegmentTree<int64_t, LSTNode> st(v);
    println("Case ", case_no, ":");
    while(q--){
    	int op, l, r;
    	read(op, l, r);
    	if(op == 1){
    		int64_t x;
    		read( x);
    		st.update(l - 1, r -1, x | (1ULL << 51));

    	}else if(op == 0){
    		int64_t x;
    		read(x);
    		st.update(l - 1, r -1, x | (1ULL << 50));
    	}else{
    		println(st.query(l - 1, r - 1).sqSum);
    	}
    }
}
