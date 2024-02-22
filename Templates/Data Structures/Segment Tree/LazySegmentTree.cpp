

template < class T, class V >
class LazySegmentTree {
private:
    V * nodes;
    int N;
public:
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
        return query(1, 0, N - 1, lo, hi).query();
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
            nodes[stIndex].assignLeaf(arr[lo], lo);
            return;
        }
        int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
        buildTree(arr, left, lo, mid);
        buildTree(arr, right, mid + 1, hi);
        nodes[stIndex].buildMerge(nodes[left], nodes[right]);
    }

    V query(int stIndex, int left, int right, int lo, int hi) {
        nodes[stIndex].propagate();
        if (left == lo && right == hi) {
            return nodes[stIndex];
        }
        int mid = (left + right) / 2;
        if (lo > mid) {
            return query(2 * stIndex + 1, mid + 1, right, lo, hi);
        }
        if (hi <= mid) {
            return query(2 * stIndex, left, mid, lo, hi);
        }
        V result;
        result.merge(query(2 * stIndex, left, mid, lo, mid), query(2 * stIndex + 1, mid + 1, right, mid + 1, hi));
        return result;
    }
    void updateRange(int stIndex, int left, int right, int lo, int hi, T val) {
        nodes[stIndex].propagate();
        if (left > right || left > hi || right < lo){
            return;
        }
        if (left >= lo && right <= hi) {
            return nodes[stIndex].update(val);
        }
        int mid = (left + right) / 2;
        updateRange(2 * stIndex, left, mid, lo, hi, val);
        updateRange(2 * stIndex + 1, mid + 1, right, lo, hi, val);
        nodes[stIndex].merge(nodes[2 * stIndex], nodes[2 * stIndex + 1]);
    }
};

struct LSTNode1 {
    int leftIndx = -1, rightIndx = -1; 
    LSTNode1* leftChild = nullptr; 
    LSTNode1* rightChild = nullptr;
    void buildMerge(LSTNode1& leftC, LSTNode1& rightC) {
        this -> leftChild = &leftC;this -> rightChild = &rightC;
        this -> leftIndx = leftC.leftIndx; 
        this -> rightIndx = rightC.rightIndx;
        this -> merge(leftC, rightC);
    }
    LSTNode1 query(){return * this;}
    long long nodeLength(){return ((this->rightIndx-this->leftIndx)+1LL);}
    bool isLeaf(){return (leftIndx == rightIndx);}
    void assignLeaf(auto val, int idx) {
        this -> leftIndx =  this -> rightIndx = idx; 
        this -> assignLeaf(val);
    }
    /*---*/ 

    ll sum = 0LL;
    ll lazy = 0LL;

    void propagate(){
        assert(leftIndx != -1 and rightIndx != -1);
        this -> sum += ((this -> nodeLength()) * this -> lazy);
        if(not this -> isLeaf()){
            leftChild -> lazy += this->lazy;
            rightChild -> lazy += this->lazy;
        }
        this -> lazy = 0LL;
    }
    void update(ll val){
        assert(leftIndx != -1 and rightIndx != -1);
        this -> sum += (val * (this -> nodeLength()));
        if(not this->isLeaf()){
            this -> leftChild -> lazy += val;
            this -> rightChild -> lazy += val;
        }
    }
    void merge(LSTNode1 leftC, LSTNode1 rightC) {
        this -> sum = leftC.sum + rightC.sum;
    }
    void assignLeaf(ll val){
        this -> sum = val;
        this -> lazy = 0LL;
    }
};

/**
 * 
 * @LazySegmentTree<int, LSTNode1> tree(arr);
 * @LazySegmentTree<int, LSTNode1> tree(arr, size);
 * 
 * @Zero-based indexing for Query and Update
 * 
 * @Range Query     @tree.query(l, r);
 * @Range Update    @tree.update(l, r, value);
 * 
 * */ 