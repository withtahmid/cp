


const int N = 10000 + 69;
const int LOG = __lg(N) + 1;
vector<vector<int>>adj(N);
int up[N][LOG], depth[N];
 
void lift_dfs(int u, int parent,  vector<vector<int>>& adj){
    up[u][0] = parent;
    for(int i = 1; i < LOG; ++i){
        up[u][i] = (up[u][i -1] == -1) ? -1 : up[ up[u][i -1] ][i -1];
    }
    for(auto v : adj[u]){
        if(v != parent){
            depth[v] = depth[u] + 1;
            lift_dfs(v, u, adj);
        }
    }
}

void attach(int node_to_attach, int node_to_attach_to) {
    int a = node_to_attach, b = node_to_attach_to;
    ::adj[a].emplace_back(b), ::adj[b].emplace_back(a);

    up[a][0] = b;

    for(int i = 1; i < LOG; ++i){
        up[a][i] = (up[a][i -1] == -1) ? -1 : up[ up[a][i -1] ][i -1];
    }
    depth[a] = depth[b] + 1;
}

int ancestorKth(int u, int k){
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
    a = ancestorKth(a, k);
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

void init_binaryLifting(int v = 0){
    depth[v] = 0;
    lift_dfs(v, -1, adj);
}

