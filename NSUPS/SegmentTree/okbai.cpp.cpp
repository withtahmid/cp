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
// template <class T>inline T scan(){T t;read(t);return t;}
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
class LazySegmentTree {
private:
    V * nodes;
    int N;
    V dummy;
public:
	LazySegmentTree(const int n){
		this -> N = n;
        nodes = new V[this->getSegmentTreeSize(this -> N + 5)];
	}
    LazySegmentTree(const vector < T > & arr, const int sz) {
        this -> N = sz;
        nodes = new V[this->getSegmentTreeSize(this -> N + 5)];
        buildTree(arr, 1, 0, N - 1);
    }

    LazySegmentTree(const vector< T >& arr)
        :LazySegmentTree(arr, (int)arr.size()){}
    ~LazySegmentTree() {
        delete[] nodes;
    }

    V query(int lo, int hi) {
        assert(0 <= lo); assert(hi < N); assert(lo <= hi);
        return query(1, 0, N - 1, lo, hi);
    }

    void assign(const vector<T>&arr, int n){
    	this -> N = n;
    	int x = this->getSegmentTreeSize(this -> N + 5);
    	for(int i = 0; i < x; ++i){
    		nodes[i].one = 0, nodes[i].lazy = -1;
    	}
    	buildTree(arr, 1, 0, N - 1);
    }

    void update(int lo, int hi, T value){
        assert(0 <= lo); assert(hi < N); assert(lo <= hi);
        updateRange(1, 0, N - 1, lo, hi, value);
    }

private:
    int getSegmentTreeSize(int N) {
        int size = 1;for(; size < N; size <<= 1);return size << 1;
    }
    void buildTree(const vector < T > & arr, int stIndex, int lo, int hi) {
        if (lo == hi) {
            nodes[stIndex].assignLeaf(arr[lo]);
            return;
        }
        const int mid = (lo + hi) >> 1, lc = stIndex << 1, rc = (stIndex << 1) + 1;
        buildTree(arr, lc, lo, mid);
        buildTree(arr, rc, mid + 1, hi);
        nodes[stIndex].merge(nodes[lc], nodes[rc]);
    }
    void propagate(int& stIndex, int& left, int& right){
    	if(left == right){
    		nodes[stIndex].propagate(left, right, dummy, dummy);
    	}else{
    		nodes[stIndex].propagate(left, right,  nodes[stIndex << 1], nodes[(stIndex << 1) + 1]);
    	}
    }
    V query(int stIndex, int left, int right, int lo, int hi) {
        this-> propagate(stIndex, left, right);
        if (left == lo && right == hi) {
            return nodes[stIndex];
        }
 		const int mid = (left + right) >> 1, lc = stIndex << 1, rc = (stIndex << 1) + 1;
        if (lo > mid) {
            return query(rc, mid + 1, right, lo, hi);
        }
        if (hi <= mid) {
            return query(lc, left, mid, lo, hi);
        }
        V lres = query(lc, left, mid, lo, mid);
        V rres = query(rc, mid + 1, right, mid + 1, hi);
        V result;
        result.merge(lres, rres);
        return result;
    }
    void updateRange(int stIndex, int left, int right, int lo, int hi, T val) {
        this-> propagate(stIndex, left, right);
        if (left > right || left > hi || right < lo){
            return;
        }
        if (left >= lo && right <= hi) {
            nodes[stIndex].update(val);
            return this-> propagate(stIndex, left, right);
        }

        const int mid = (left + right) >> 1, lc = (stIndex << 1), rc = (stIndex << 1) + 1;
        updateRange(lc, left, mid, lo, hi, val);
        updateRange(rc, mid + 1, right, lo, hi, val);
        nodes[stIndex].merge(nodes[lc], nodes[rc]);
    }
};

struct LSTNode1 {
    
    int one = 0, lazy = -1;
    
    void propagate(const int& left, const int& right,  LSTNode1& lc, LSTNode1& rc){
       	int x = this -> lazy;
       	if(x == -1){
       		return;
       	}
       	this -> lazy = -1;

       	if(x == 2){
       		this -> one = ((right - left + 1) - this -> one);
       	}else if(x == 1){
       		this -> one = ((right - left + 1));
       	}else{
       		this -> one = 0;
       	}

        if(left == right){
           return;
        }
        
        if(x == 2){
        	if(lc.lazy == 2){
        		lc.lazy = -1;
        	}else{
        		lc.lazy = abs(lc.lazy ^ 1);
        	}

        	if(rc.lazy == 2){
        		rc.lazy = -1;
        	}else{
        		rc.lazy = abs(rc.lazy ^ 1);
        	}
        }else{
        	lc.lazy = x;
        	rc.lazy = x;
        }

    }
    void update(int& val){
    	this -> lazy = val;
    }
    void merge(const LSTNode1& lc, const LSTNode1& rc) {
        this -> one = (lc.one + rc.one);
    }

    void assignLeaf(int val){
        this -> one = val;
        this -> lazy = -1;
    }
};

void solve([[maybe_unused]] const int& case_no){
    int m;
    cin >> m;
    vector<int>v;
    for(int i = 0; i < m; ++i){
    	int n;
    	string s;
    	cin >> n >> s;
    	while(n--){
    		for(char& c : s){
    			v.push_back(c - '0');
    		}
    	}
    }
    LazySegmentTree<int, LSTNode1> sgt(v);
    int q;
    cin >> q;
    int numq = 0;
    cout << "Case " << case_no <<":\n";
    while(q--){
    	char op;
    	int l, r;
    	cin >> op >> l >> r;
    	if(op == 'F'){
    		sgt.update(l, r, 1);
    	}else if(op == 'E'){
    		sgt.update(l, r, 0);
    	}else if(op == 'I'){
    		sgt.update(l, r, 2);
    	}else{
    		cout << "Q" << ++ numq <<": " << sgt.query(l, r).one << "\n";
    	}
    }
}
