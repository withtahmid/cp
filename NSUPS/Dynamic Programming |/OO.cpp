#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

const int N = 1e5 + 69;
int64_t dp[N];
int n, m;
int64_t fn(vector<int64_t>& v, int i = 0){
    if(i >= int(v.size())){
        return 0;
    }
    int64_t& res = dp[i];
    if(res != -1){
        return res;
    }
    res = fn(v, i + 1);
    return res = max(res, fn(v, i + 2) + v[i]);
}
void solve(const int& tc){
    while(cin >> n >> m){
        if(n == 0 and m == 0){
            break;
        }
        vector<vector<int64_t>>arr(n, vector<int64_t>(m));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin >> arr[i][j];
            }
        }
        vector<int64_t>col(n);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < arr[i].size(); ++j){
                dp[j] = -1;
            }
            col[i] = fn(arr[i]);
        }
        for(int j = 0; j < col.size(); ++j){
            dp[j] = -1;
        }
        cout << fn(col) << '\n';
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
