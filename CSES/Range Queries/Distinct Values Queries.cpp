/**
 *
 * Author: withtahmid
 *
 **/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL 
#include <debug.h>
#else
#define dbg(...)
#endif
#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
void solve(const int& case_no);
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dbg(__init__());
    bool test_case = not true;
    int tc = 1; if(test_case){cin >> tc;}
    for(int i = 1; i <= tc; ++i){
        dbg(__case__(i));
        solve(i);
    }
    dbg(__elapsed__());
}

const int N = 2e5 + 69;
const int M = 1e7 + 69;

int n, q, nodes = 0, root[N], a[N], segtree[M], L[M], R[M];

int mergeNode(int lc, int rc){
    return lc + rc;
}

void update(int p, int v, int prev_node, int cur_node, int b = 1, int e = n){
    if(b == e){
        segtree[cur_node] = v;
        return;
    }
    int mid = (b + e) >> 1;
     // p on left
    if(p <= mid){
        // keep right child same as previous
       R[cur_node] = R[prev_node];

       // create new node for left child
       L[cur_node] = ++nodes;

       // upadate on left child
       update(p, v, L[prev_node], L[cur_node], b, mid);


    }
    // p on right child
    else{
        
        // keep left child same as previous
        L[cur_node] = L[prev_node];

        // create new node for right child
        R[cur_node] = ++nodes;

        // update right child

        update(p, v, R[prev_node], R[cur_node], mid + 1, e);
    }
    segtree[cur_node] = mergeNode(segtree[L[cur_node]], segtree[R[cur_node]]);
}

int query(int l, int r, int u, int b = 1,  int e = n){
    if(l == b and r == e){
        return segtree[u];
    }
    int mid = (b + e) >> 1;

    if(r <= mid){
        return query(l, r, L[u], b, mid);
    }else if(l > mid){
        return query(l, r, R[u], mid + 1, e);
    }
    int lRes = query(l, mid, L[u], b, mid);
    int rRes = query(mid + 1, r, R[u], mid + 1, e);
    return mergeNode(lRes, rRes);
}


void solve([[maybe_unused]] const int& case_no){
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    map<int, int> last;

    for(int i = 1; i <= n; ++i){
        int x = a[i], pos = last[x], prev_root = root[i - 1];
        if(pos){
            root[i] = ++nodes;
            update(pos, 0, prev_root, root[i]);
            prev_root = root[i];
        }
        root[i] = ++nodes;
        update(i, 1, prev_root, root[i]);
        last[x] = i;
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << query(l, r, root[r]) << "\n";
    }
}
