

struct Centroid{
    vector<vector<int>> adj;
    vector<bool> vis;
    vector<int> parent, level;
    vector<int>sz;
    int N;
    Centroid(){}
    Centroid(int n){this->resize(n);}
    void resize(int n){
        this -> N = n;
        this -> adj = vector<vector<int>>(this -> N , vector<int>());
        parent = level = vector<int>(this -> N );
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
    void decompose(int  u = 0, int p = -1, int lvl = 0){
        find_subtree_size(u);
        int c = find_centroid(u, -1, sz[u]);
        vis[c] = true;
        parent[c] = p;
        level[c] = lvl;
        for(int v : this -> adj[c]){
            if(not vis[v]){
                this -> decompose(v, c, lvl + 1);
            }
        }
    }
};

/**
 * Centroid ct;
 * ct.resize(size), ct.resize(adjlist);
 * ct.edge(u, v);
 * ct.decompose(root, parent_of_root);
 * ct.parent[u] 
 * */