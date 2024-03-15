#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define dbg(...)
#endif

bool read(auto &...x) { return (((cin >> x) ? 1 : 0) && ...); }
void print(const auto &...x) {((cout << x), ...); }
void println(const auto &...x) { print(x..., '\n'); }


template < class T, class V >
class LazySegmentTree {
private:
    vector<V> nodes;
    int N;
    V dmy;
    int sgtsz(int x) { return (x << 2);}
    void buildTree(const vector < T > & arr, int stIndex, int left, int right) {
        if (left == right) {
            return nodes[stIndex].assignLeaf(arr[left]);
        }
        const int lc = (stIndex << 1), rc = lc | 1, mid = ((left + right) >> 1);
        buildTree(arr, lc, left, mid);
        buildTree(arr, rc, mid + 1, right);
        nodes[stIndex].mergeNode(nodes[lc], nodes[rc]);
    }
    void propagate(int& stIndex, int& left, int& right){
        if(left == right){
            return nodes[stIndex].propagate(left, right, dmy, dmy);
        }
        nodes[stIndex].propagate(left, right,  nodes[stIndex << 1], nodes[(stIndex << 1) + 1]);
    }
    V query(int stIndex, int left, int right, int lo, int hi) {
        this-> propagate(stIndex, left, right);
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
    void updatePoint(int stIndex, int left, int right, int index, T value) {
        this-> propagate(stIndex, left, right);
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
    void updateRange(int stIndex, int left, int right, int lo, int hi, T val) {
        this-> propagate(stIndex, left, right);
        if (left > right || left > hi || right < lo){
            return;
        }
        const int lc = (stIndex << 1), rc = lc | 1, mid = ((left + right) >> 1);
        if (left >= lo && right <= hi) {
            bool l = left == right;
            return nodes[stIndex].updateNode(left, right, (l ? dmy : nodes[lc]), (l ? dmy : nodes[rc]), val);
        }
        updateRange(lc, left, mid, lo, hi, val);
        updateRange(rc, mid + 1, right, lo, hi, val);
        nodes[stIndex].mergeNode(nodes[lc], nodes[rc]);
    }
public:
    LazySegmentTree(const int n){
        this -> N = n;
        nodes.resize(this->sgtsz(this -> N) + 5);
    }
    LazySegmentTree(const vector < T > & arr, const int sz) {
        this -> N = sz;
        nodes.resize(this->sgtsz(this -> N) + 5);
        buildTree(arr, 1, 0, this -> N - 1);
    }
    LazySegmentTree(const vector< T >& arr):LazySegmentTree(arr, (int)arr.size()){}

    V query(int lo, int hi) {
        return query(1, 0, this -> N - 1, lo, hi);
    }
    void assign(const vector<T>& arr){
        this -> N = (int)arr.size();
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

    int on = 0, off = 0, lazy = 0;

    void propagate(int& left, int& right, LSTNode& LC, LSTNode& RC){
       	if(this -> lazy){
       		swap(this -> on, this -> off);
       	}
        if(left != right){
          LC.lazy ^= (this -> lazy);
          RC.lazy ^= (this -> lazy);  
        }
        this -> lazy = 0;
    }
    
    void updateNode(int& left, int& right, LSTNode& LC, LSTNode& RC, int val){
        this -> lazy ^= 1;
        this -> propagate(left, right, LC, RC);
    }

    void mergeNode(LSTNode& LC, LSTNode& RC) {
        this -> on = (LC.on + RC.on), this -> off = (LC.off + RC.off);
    }

    void assignLeaf(int val){
        this -> on = 0, this -> off = 1;
    }
};

void solve(const int& tc){
	int n, q;
	read(n, q);
	LazySegmentTree<int, LSTNode> st(vector<int>(n, 0));
	while(q--){
		int o, l, r;
		read(o, l, r);
		if(o == 0){
			st.update(l - 1, r - 1, 1);
		}else{
			println(st.query(l - 1, r - 1).on);
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dbg(__init__());
	int t = 1;
	// cin >> t;
	for(int i = 1; i <= t; ++i){
		solve(i);
	}
	dbg(__elapsed__());
}