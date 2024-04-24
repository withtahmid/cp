#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

struct LCA{
    vector<vector<int>> adj, up;
    vector<int>depth, intime, outtime;
    int N, LOG, timer = 0;
    LCA(){}
    LCA(int n){this->resize(n);}
    void resize(int n){
        this->N = n, this -> LOG = __lg(this->N) + 1;
        adj = vector<vector<int>>(this->N);
        up = vector<vector<int>>(this->N, vector<int>(LOG, -1));
        depth = outtime = intime  = vector<int>(this->N);
    }
    void add_edge(int u, int v){
        adj[u].emplace_back(v), this -> adj[v].emplace_back(u);
    }
    void attach(int node_to_attach, int node_to_attach_to) {
        int a = node_to_attach, b = node_to_attach_to;
        adj[a].emplace_back(b), adj[b].emplace_back(a);
        up[a][0] = b;
        for(int i = 1; i < LOG; ++i){
            up[a][i] = (up[a][i - 1] == -1) ? -1 : up[ up[a][i - 1] ][i - 1];
        }
        depth[a] = depth[b] + 1;
    }
    bool is_ancestor(int ancestor, int decedent){
        return (bool)((intime[ancestor] <= intime[decedent]) and (outtime[ancestor] >= outtime[decedent]));
    }
    void lift_dfs(int u, int parent){
        up[u][0] = parent;
        intime[u] = ++this->timer;
        for(int i = 1; i < LOG; ++i){
            up[u][i] = (up[u][i - 1] == -1) ? -1 : up[ up[u][i - 1] ][i - 1];
        }
        for(int v : this->adj[u]){
            if(v != parent){
                depth[v] = depth[u] + 1;
                lift_dfs(v, u);
            }
        }
        outtime[u] = ++this->timer;
    }
    int kth(int u, int k){
        for(int i = LOG - 1; i >= 0; --i){
            if(u == -1){
                return -1;
            }
            if((1 << i) <= k){
                u = up[u][i], k -= (1 << i);
            }
        }
        return u;
    }
    int get_lca(int a, int b){
        if(depth[a] < depth[b]){
            swap(a, b);
        }
        int k = depth[a] - depth[b];
        a = kth(a, k);
        if(a == b){
            return a;
        }
        for(int i = LOG - 1; i >= 0; --i){
            if(up[a][i] != up[b][i]){
                a = up[a][i], b = up[b][i];
            }
        }
        return up[a][0];
    }
    int get_dist(int a, int b){
        return depth[a] + depth[b] - (2 * depth[get_lca(a, b)]);
    }
    void build(int root = 0, int parent = -1){
        depth[root] = 0;
        this->lift_dfs(root, parent);
    }
};

void dfs(int u, vector<int64_t>& result, vector<vector<int>>& adj, int par = -1){
    for(int v : adj[u]){
        if(v != par){
            dfs(v, result, adj, u);
            result[u] += result[v];
        }
    }
}

void solve(const int& tc){
    int n, q;
    cin >> n >> q;
    dbg(n, q);
    LCA lca(n);
    for(int i = 0; i + 1 < n; ++i){
        int u, v;
        cin >> u >> v;
        lca.add_edge(u - 1, v - 1);
    }
    lca.build();

    vector<int64_t>result(n, 0);

    while(q--){
        int a, b;
        cin >> a >> b;
        --a, --b;
        int lca_ab = lca.get_lca(a, b);
        ++result[a], ++result[b], --result[lca_ab];
        if(lca_ab != 0){
            --result[lca.up[lca_ab][0]];
        }
    }
    
    dfs(0, result, lca.adj, -1);

    for(int i = 0; i < n; ++i){
        cout << result[i] << ' ';
    }
    cout << '\n';

}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
