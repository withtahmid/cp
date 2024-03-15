#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define dbg(...)
#endif

vector<int> isPrime;
void sieve(const int N){
	isPrime.resize(N + 69, true);
	isPrime[1] = false;
	for(int i = 4; i <= N; i += 2){
		isPrime[i] = false;
	}
	for(int i = 3; i * i <= N; i += 2){
		for(int j = i * i; j <= N; j += (i << 1)){
			isPrime[j] = false;
		}
	}
}

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
        assert(0 <= lo); assert(hi < (int)this -> N); assert(lo <= hi);
        return query(1, 0, this -> N - 1, lo, hi);
    }
    void assign(const vector<T>& arr){
        assert(nodes.size() >= sgtsz(arr.size()));
        this -> N = (uint)arr.size();
        buildTree(arr, 1, 0, this -> N - 1);
    }
    void set(int index, T value) {
        assert(0 <= index and index < this->N);
        updatePoint(1, 0, this -> N - 1, index, value);
    }
    void update(int lo, int hi, T value){
        assert(0 <= lo); assert(hi < (int)this -> N); assert(lo <= hi);
        updateRange(1, 0, this -> N - 1, lo, hi, value);
    }
};

struct LSTNode {

    int64_t sum = 0, lazy = -1;

    void propagate(uint& left, uint& right, LSTNode& LC, LSTNode& RC){
    	if(this -> lazy == -1){
    		return;
    	}
        this -> sum = (right - left + 1) * this -> lazy;
        if(left != right){
            LC.lazy = (this -> lazy);
            RC.lazy = (this -> lazy);
        }
        this -> lazy = -1;
    }
    
    void updateNode(uint& left, uint& right, LSTNode& LC, LSTNode& RC, int64_t val){
        this -> lazy = val;
        this -> propagate(left, right, LC, RC);
    }

    void mergeNode(LSTNode& LC, LSTNode& RC) {
        this -> sum = (LC.sum + RC.sum);
    }

    void assignLeaf(int64_t val){
        this -> sum = val;
        this -> lazy = -1;
    }
};

void solve(const int& tc){
	int n, q;
	cin >> n >> q;
	vector<int>v(n);
	for(auto& i : v){
		cin >> i;
		i = (isPrime[i] ? 1 : 0);
	}
	LazySegmentTree<int, LSTNode> st(v);
	cout << "Case " << tc <<":\n";
	while(q--){
		int op, l, r;
		cin >> op >> l >> r;
		if(op == 0){
			int x;
			cin >> x;
			st.update(l - 1, r - 1, isPrime[x]);
		}else{
			cout << st.query(l - 1, r - 1).sum << "\n";
		}
	}

}

signed main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dbg(__init__());
	sieve(1000000);
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i){
		solve(i);
	}
	dbg(__elapsed__());
}