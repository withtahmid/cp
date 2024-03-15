

/**************************************************/
template<class T, class V>
class SegmentTree {
  V* nodes;
  int N;

public:
  SegmentTree(const vector<T>&arr) {
    this->N = (int)arr.size() + 5;
    nodes = new V[getSegmentTreeSize(this->N)];
    buildTree(arr, 1, 0, N-1);
  }
  
  ~SegmentTree() {
    delete[] nodes;
  }
  
  V query(int lo, int hi) {
    V result = query(1, 0, N-1, lo, hi);
    return result.query();
  }
  
  void update(int index, T value) {
    update(1, 0, N-1, index, value);
  }
  
  private:  
  void buildTree(const vector<T>&arr, int stIndex, int lo, int hi) {
    if (lo == hi) {
      nodes[stIndex].assignLeaf(arr[lo]);
      return;
    }
    
    int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
    buildTree(arr, left, lo, mid);
    buildTree(arr, right, mid + 1, hi);
    nodes[stIndex].merge(nodes[left], nodes[right]);
  }
  
  V query(int stIndex, int left, int right, int lo, int hi) {
    if (left == lo && right == hi)
      return nodes[stIndex];
        
    int mid = (left + right) / 2;
    if (lo > mid)
      return query(2*stIndex+1, mid+1, right, lo, hi);
    if (hi <= mid)
      return query(2*stIndex, left, mid, lo, hi);
        
    V leftResult = query(2*stIndex, left, mid, lo, mid);
    V rightResult = query(2*stIndex+1, mid+1, right, mid+1, hi);
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
        nodes[stIndex].assignLeaf(value);
        return;
    }
    
    int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
    if (index <= mid){
      update(left, lo, mid, index, value);
    }
    else{
      update(right, mid+1, hi, index, value);
    }
    
    nodes[stIndex].merge(nodes[left], nodes[right]);
  }
};

/********/ 
const ll p = 31, mod = LLONG_MAX;
ll power(ll x, ll y){ 
     ll val = 1;
     while (y > 0){ 
         if (y % 2 != 0) {
             val = (val * x) % mod; 
         }
         y = y / 2; 
         x = (x * x) % mod;
     } 
     return val; 
 }
/*******/ 

struct Node{
    
    ll fr, rv , len;
    
    void merge(Node a, Node b){
        if(a.len != 0 and b.len != 0){
            this -> fr = (((power(p, a.len) * b.fr) % mod) + a.fr) % mod;
            this -> rv = (((power(p, b.len) * a.rv) % mod) + b.rv) % mod;
            this -> len = a.len + b.len;
        }
        else if(a.len == 0){
            *this = b;
        }
        else{
            *this = a;
        }
    }
    Node query(){
        return *this;
    }
    void assignLeaf(auto val){
        fr = val, rv = val, len = 1;
    }
};

/**************************************************************/ 