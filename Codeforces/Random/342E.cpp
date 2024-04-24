#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

struct LCABinaryLift{
    vector<vector<int>> adj, up;
    vector<int>depth;
    int N, LOG;
    void resize(int n){
        this->N = n, this -> LOG = __lg(this->N) + 1;
        adj = vector<vector<int>>(this->N);
        up = vector<vector<int>>(this->N, vector<int>(LOG, -1));
        depth = vector<int>(this->N);
    }
    void add_edge(int u, int v){
        adj[u].emplace_back(v), this -> adj[v].emplace_back(u);
    }
    void attach(int node_to_attach, int node_to_attach_to) {
        int a = node_to_attach, b = node_to_attach_to;
        adj[a].emplace_back(b), adj[b].emplace_back(a);
        up[a][0] = b;
        for(int i = 1; i < LOG; ++i){
            up[a][i] = (up[a][i -1] == -1) ? -1 : up[ up[a][i - 1] ][i - 1];
        }
        depth[a] = depth[b] + 1;
    }
    void lift_dfs(int u, int parent){
        up[u][0] = parent;
        for(int i = 1; i < LOG; ++i){
            up[u][i] = (up[u][i - 1] == -1) ? -1 : up[ up[u][i - 1] ][i - 1];
        }
        for(int v : this->adj[u]){
            if(v != parent){
                depth[v] = depth[u] + 1;
                lift_dfs(v, u);
            }
        }
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
        int lca = get_lca(a, b);
        return depth[a] + depth[b] - (2 * depth[lca]);
    }
    void build(int root = 0, int parent = -1){
        depth[root] = 0;
        this->lift_dfs(root, parent);
    }
};

struct Centroid{
    vector<vector<int>> adj;
    vector<bool> vis;
    vector<int> parent;
    vector<int>sz;
    int N;
    void resize(int n){
        this -> N = n;
        this -> adj = vector<vector<int>>(this -> N , vector<int>());
        parent = vector<int>(this -> N );
        sz = vector<int>(this -> N );
        vis = vector<bool>(this -> N , false);
    }
    void add_edge(int u, int v){
        this -> adj[u].emplace_back(v), this -> adj[v].emplace_back(u);
    }
    int find_subtree_size(int u, int p = -1){
        if(vis[u]){
            return 0;
        }
        this -> sz[u] = 1;
        for(int v : this->adj[u]){
            if(v != p){
                sz[u] += this->find_subtree_size(v, u);
            }
        }
        return this -> sz[u];
    }
    int find_centroid(int u, int p, int n){
        for(int v : this -> adj[u]){
            if(v != p){
                if(not vis[v] and sz[v] > n / 2){
                    return find_centroid(v, u, n);
                }
            }
        }
        return u;
    }
    void decompose(int  u = 0, int p = -1){
        find_subtree_size(u);
        int c = find_centroid(u, -1, sz[u]);
        vis[c] = true;
        parent[c] = p;
        for(int v : this -> adj[c]){
            if(not vis[v]){
                this -> decompose(v, c);
            }
        }
    }
};


vector<int>best(int(2e5 + 10));

Centroid ct;
LCABinaryLift lca;

void update(int v){
    best[v] = 0;
    int u = v;
    while(ct.parent[u] != -1){
        u = ct.parent[u];
        best[u] = min(best[u], lca.get_dist(u, v));
    }
}

int query(int v){
    int ans = best[v];
    int u = v;
    while(ct.parent[u] != -1){
        u = ct.parent[u];
        ans = min(ans, best[u] + lca.get_dist(u, v));
    }
    return ans;
}

void solve(const int& tc){
    int n, q;
    cin >> n >> q;
    ct.resize(n), lca.resize(n);
    for(int i = 0; i < n; ++i){
        best[i] = (1 << 29);
    }
    for(int i = 0; i + 1 < n; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        ct.add_edge(u, v), lca.add_edge(u, v);
    }   

    lca.build(), ct.decompose();
    
    update(0);

    for(int i = 0; i < q; ++i){
        int op, u;
        cin >> op >> u;
        --u;
        dbg(i + 1, op, u);
        if(op == 1){
            update(u);
        }else{
            cout << query(u) << '\n';
        }
    }
}
 
 
int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
 