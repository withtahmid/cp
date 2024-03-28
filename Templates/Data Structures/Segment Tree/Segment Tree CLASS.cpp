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
        nodes.resize(sgtsz(this -> N) + 5);
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

    void update(int index, T value) {
        assert(0 <= index and index < (int)this -> N);
        update(1, 0, this -> N - 1, index, value);
    }
};

struct STNode {
    int64_t res = 0LL;
    void mergeNode(STNode& LC, STNode& RC) {
        this -> res = (LC.res + RC.res);
    }
    void assignLeaf(int64_t val) {
        this -> res = val;
    }
};

/**
 * 
 * @SegmentTree<int, STNode> tree(v);
 * @Range Query @tree.query(l, r);
 * @Point Update @tree.update(i, value);
 * 
 * */ 