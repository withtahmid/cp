#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 10) + 10;
const int mod = 1000000007;

int n, m, dp[110][12][N];

int fn(int pos, int prev, int mask){
    if(pos >= m){
        return (mask == ((1 << n) - 1)) ? 1 : 0;
    }
    
    int& res = dp[pos][prev][mask];

    if(res != -1){
        return res;
    }

    res = (mask == ((1 << n) - 1)) ?  1 : 0;
    
    if(prev != 9){
        res = (res + fn(pos + 1, prev + 1, mask | (1 << (prev + 1)))) % mod;
    }
    if(prev != 0){
        res = (res + fn(pos + 1, prev - 1, mask | (1 << (prev - 1)))) % mod;
    }
    
    return res;
}

void solve(const int& tc){
   
    cin >> ::n >> ::m;
   
    int res = 0;
   
    memset(dp, -1, sizeof(dp));
   
    for(int i = 1; i < n; ++i){
        res = (res + fn(1, i, (1 << i))) % mod;
    }
   
    cout << res << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
