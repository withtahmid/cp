


const int N = 2e5 + 69;
vector<int>adj[N];
int timer = 0, dfs_order[N], child_cnt[N];

void dfs(int u = 0, int par = -1){
    dfs_order[u] = timer++;
    child_cnt[u] = 1;
    for(int v : adj[u]){
        if(v != par){
            dfs(v, u);
            child_cnt[u] += child_cnt[v];
        }
    }
}

int point(const int node){
    return dfs_order[node];
}

pair<int, int> range(const int node){
    return make_pair(dfs_order[node], dfs_order[node] + child_cnt[node] - 1);
}

void generate_order(vector<auto>& ordered_arr, vector<auto>& value_arr){
    assert(ordered_arr.size() == value_arr.size());
    for(int i = 0; i < int(value_arr.size()); ++i){
        ordered_arr[dfs_order[i]] = value_arr[i];
    }
}


