#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

map<int, map<int, int>> arr, rowdp;
map<int, int>dp;
int n, m;

int fn(int i, int j){
    if(i >= n or  j >= m){
        return 0;
    }
    if(rowdp[i].find(j) != rowdp[i].end()){
        return rowdp[i][j];
    }
    rowdp[i][j] = fn(i, j + 1);
    return rowdp[i][j] = max(rowdp[i][j], fn(i, j + 2) + arr[i][j]);
}
int fn(int i){
    if(i >= n){
        return 0;
    }
    if(dp.find(i) != dp.end()){
        return dp[i];
    }
    int& res = dp[i];
    if(res != -1){
        return res;
    }
    res = fn(i + 1);
    return res = max(res, fn(i + 2) + fn(i, 0));
}

void solve(const int& tc){
    while(cin >> n >> m){
        if(n == 0 and m == 0){
            break;
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin >> arr[i][j];
            }
        }
        dp.clear(), rowdp.clear();
        cout << fn(0) << '\n';
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
