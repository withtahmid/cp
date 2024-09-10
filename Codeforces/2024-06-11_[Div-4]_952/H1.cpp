#include <bits/stdc++.h>
using namespace std;

void solve(const int& tc){
    
    int n, m;
    
    cin >> n >> m;
    
    vector<string>g(n);
    
    for(int i = 0; i < n; ++i){
        cin >> g[i];
    }
    
    auto ids = vector<vector<int>>(n, vector<int>(m, -1));
    
    auto valid = [&](int i, int j) -> bool{
        return (0 <= i && i < n && 0 <= j && j < m) && (g[i][j] == '#') && ids[i][j] == -1 ? true : false;
    };

    const int x[] = { +0, +1, +0, -1 };
    const int y[] = { -1, +0, +1, +0 };

    auto dfs = [&](auto& dfs, int& cnt, int& id,  int i, int j) -> void{
        ids[i][j] = id;
        ++cnt;
        for(int d = 0; d < 4; ++d){
            int ni = x[d] + i, nj = y[d] + j;
            if(valid(ni, nj)){
                dfs(dfs, cnt, id, ni, nj);
            }
        }
    };


    int id = 0;
    vector<int> points((n * m) + 69);
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j){
        if(g[i][j] == '.' || ids[i][j] != -1){
            continue;
        }
        ++id;
        int cnt = 0;
        dfs(dfs, cnt, id,  i, j);
        points[id] = cnt;
    }

    int res = 0;

    for(int i = 0; i < n; ++i){
        set<int>used;
        int tot = 0;
        for(int j = 0; j < m; ++j){
            if(g[i][j] == '#' && !used.count(ids[i][j])){
                tot += points[ids[i][j]];
                used.insert(ids[i][j]);
            }
            if(i > 0 && g[i - 1][j] == '#' && !used.count(ids[i - 1][j])){
                tot += points[ids[i - 1][j]];
                used.insert(ids[i - 1][j]);
            }
            if((i + 1 < n) && g[i + 1][j] == '#' && !used.count(ids[i + 1][j])){
                tot += points[ids[i + 1][j]];
                used.insert(ids[i + 1][j]);
            }
            tot += g[i][j] != '#';
        }
        res = max(res, tot);
    }


    for(int j = 0; j < m; ++j){
        set<int>used;
        int tot = 0;
        for(int i = 0; i < n; ++i){
            if(g[i][j] == '#' && !used.count(ids[i][j])){
                tot += points[ids[i][j]];
                used.insert(ids[i][j]);
            }
            if(j > 0 && g[i][j - 1] == '#' && !used.count(ids[i][j - 1])){
                tot += points[ids[i][j - 1]];
                used.insert(ids[i][j - 1]);
            }
            if((j + 1 < m) && g[i][j + 1] == '#' && !used.count(ids[i][j + 1])){
                tot += points[ids[i][j + 1]];
                used.insert(ids[i][j + 1]);
            }
            tot += g[i][j] != '#';
        }
        res = max(res, tot);
    }
    cout << res << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0); 
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
