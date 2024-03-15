

const int N = 2e5 + 69;
const int M = 1e7 + 69;
typedef struct {
    
    int res = 0;

}Node;

int n, q, nodes = 0, root[N], a[N] , L[M], R[M];
Node segtree[M];

inline void merge(Node& IT, Node& LC, Node& RC){
    IT.res = LC.res + RC.res;
}

void update(int p, int v, int prev_node, int cur_node, int b = 1, int e = n){
    if(b == e){
        segtree[cur_node].res = v;
        return;
    }
    int mid = (b + e) >> 1;
    if(p <= mid){
       R[cur_node] = R[prev_node];
       L[cur_node] = ++nodes;
       update(p, v, L[prev_node], L[cur_node], b, mid);


    }
    else{
        L[cur_node] = L[prev_node];
        R[cur_node] = ++nodes;
        update(p, v, R[prev_node], R[cur_node], mid + 1, e);
    }
    merge(segtree[cur_node], segtree[L[cur_node]], segtree[R[cur_node]]);
}

Node query(int l, int r, int u, int b = 1,  int e = n){
    if(l == b and r == e){
        return segtree[u];
    }
    int mid = (b + e) >> 1;
    if(r <= mid){
        return query(l, r, L[u], b, mid);
    }else if(l > mid){
        return query(l, r, R[u], mid + 1, e);
    }
    Node res, lRes = query(l, mid, L[u], b, mid), rRes = query(mid + 1, r, R[u], mid + 1, e);
    merge(res, lRes, rRes) ;
    return res;
}

/**
 * update(pos, value, prev_root, new_root)
 * query(l, r, root_no)
 * 
 * */