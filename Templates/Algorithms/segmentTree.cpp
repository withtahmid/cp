/**************************************************************/

template < class T, class V >
class SegmentTree {
  V * sgtree;
  int N;

  public:
    SegmentTree(T arr[], int N) {
      this -> N = N;
      this -> sgtree = new V[getSegmentTreeSize(N)];
      buildTree(arr, 1, 0, N - 1);
    }

    ~SegmentTree() {
      delete[] sgtree;
    }

  V query(int lo, int hi) {
    V result = query(1, 0, N - 1, lo, hi);
    return result.query();
  }

  void update(int index, T value) {
    update(1, 0, N - 1, index, value);
  }

  private:
    void buildTree(T arr[], int stIndex, int lo, int hi) {
      if (lo == hi) {
        sgtree[stIndex].assignLeaf(arr[lo]);
        return;
      }

      int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
      buildTree(arr, left, lo, mid);
      buildTree(arr, right, mid + 1, hi);
      sgtree[stIndex].merge(sgtree[left], sgtree[right]);
    }

  V query(int stIndex, int left, int right, int lo, int hi) {
    if (left == lo && right == hi) {
      return sgtree[stIndex];
    }

    int mid = (left + right) / 2;
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
    int size = 1;
    for (; size < N; size <<= 1);
    return size << 1;
  }

  void update(int stIndex, int lo, int hi, int index, T value) {
    if (lo == hi) {
      sgtree[stIndex].assignLeaf(value);
      return;
    }

    int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
    if (index <= mid) {
      update(left, lo, mid, index, value);
    } else {
      update(right, mid + 1, hi, index, value);
    }

    sgtree[stIndex].merge(sgtree[left], sgtree[right]);
  }
};

/****************/

struct Node {

  void merge(Node a, Node b) {

  }
  auto query() {
    return * this;
  }
  void assignLeaf(auto val) {

  }
};

/**************************************************************/