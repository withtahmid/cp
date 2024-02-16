

/*******************************************************/

template < class T, class V >
class LazySegmentTree {
private:
    V * nodes;
    int N;
public:
    LazySegmentTree(const vector < T > & arr, const int sz) {
        this -> N = sz;
        nodes = new V[getSegmentTreeSize(this -> N + 5)];
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
    void buildTree(const vector < T > & arr, int stIndex, int lo, int hi) {
        if (lo == hi) {
            nodes[stIndex].assignLeaf(arr[lo], lo, hi);
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
        const int mid = (left + right) / 2;
        if (lo > mid) {
            return query(2 * stIndex + 1, mid + 1, right, lo, hi);
        }
        if (hi <= mid) {
            return query(2 * stIndex, left, mid, lo, hi);
        }

        V leftResult = query(2 * stIndex, left, mid, lo, mid);
        V rightResult = query(2 * stIndex + 1, mid + 1, right, mid + 1, hi);
        V result;
        result.merge(leftResult, rightResult);
        return result;
    }

    int getSegmentTreeSize(int N) {
        int size = 1;for (; size < N; size <<= 1);return size << 1;
    }
    void updateRange(int stIndex, int left, int right, int lo, int hi, T val) {
        nodes[stIndex].propagate();
        if (left == lo and right == hi) {
            return nodes[stIndex].update(val);
        }
        const int mid = (left + right) / 2;
        if (lo > mid) {
            updateRange(2 * stIndex + 1, mid + 1, right, lo, hi, val);
        }
        else if (hi <= mid) {
            updateRange(2 * stIndex, left, mid, lo, hi, val);
        }
        else{
            updateRange(2 * stIndex, left, mid, lo, mid, val);
            updateRange(2 * stIndex + 1, mid + 1, right, mid + 1, hi, val);
        }
        nodes[stIndex].merge(nodes[left], nodes[right]);
    }
};

/******************/

struct Node {
    int left = -1, right = -1;
    Node* leftChild = nullptr;
    Node* rightChild = nullptr;
    void buildMerge(Node& leftC, Node& rightC) {
         this -> leftChild = &leftC;this -> rightChild = &rightC;
         this -> left = leftC.left; this -> right = rightC.right;
         this -> merge(leftC, rightC);
    }
    Node query(){
        return * this;
    }
    int length(){
        return ((this -> right - this -> left ) + 1);
    }
    bool isLeaf(){
        return (left == right);
    }
    void assignLeaf(auto val, int lo, int hi) {
        this -> left = lo, this -> right = hi; this -> assignLeaf(val);
    }
    /*-----------------------------------------------------------------*/ 

    long long sum = 0LL;
    long long lazy = 0LL;

    void propagate(){
        this -> sum += (this -> length()) * this -> lazy;
        if(not this-> isLeaf()){
            leftChild -> lazy += this->lazy;
            rightChild -> lazy += this->lazy;
        }
        this -> lazy = 0LL;
    }
    void update(auto val){
        this -> sum += val * (this -> length());
        if(not this->isLeaf()){
            this -> leftChild -> lazy += val;
            this -> rightChild -> lazy += val;
        }
    }
    void merge(Node leftC, Node rightC) {
         this -> sum = leftC.sum + rightC.sum;
    }
    void assignLeaf(auto val){
        this -> sum = val;
    }
};

/**
 * 
 * @LazySegmentTree<int, Node> tree(arr);
 * @LazySegmentTree<int, Node> tree(arr, size);
 * 
 * @Zero-based indexing for Query and Update
 * 
 * @Range Query     @tree.query(l, r);
 * @Range Update    @tree.update(l, r, value);
 * 
 * */ 

/*******************************************************/

