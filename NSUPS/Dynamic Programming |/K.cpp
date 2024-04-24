#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

const int N = 500, K = 2e6 + 69;

int k, n, value[N], weight[N];

int64_t dp[K];

// O(N * K)
int64_t large_knapsack(){
    for(int i = 0; i <= k; ++i){
        dp[i] = INT_MIN;
    }
    dp[0] = 0;
    for(int i = 0; i < n; ++i){
        for(int j = k; j >= weight[i]; --j){
            dp[j] = max(dp[j], value[i] + dp[j - weight[i]]);
        }
    }
    return *max_element(dp, dp + K);
}

void solve(const int& tc){
    cin >> k >> n;
    for(int i = 0; i < n; ++i){
        cin >> value[i] >> weight[i];
    }
    cout << large_knapsack() << '\n';
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
