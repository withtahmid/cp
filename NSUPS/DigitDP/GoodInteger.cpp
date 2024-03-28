#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

const int maxDigit = 15;
const int maxSum = 140;
int64_t dp[maxDigit][2][maxSum][maxSum];

int64_t fn(const string& s, int pos, int tight, int rem, int sum, int targetSum){
    if(pos == -1){
        return rem % targetSum == 0 and sum == targetSum ? 1 : 0;
    }
    int64_t& res = dp[pos][tight][rem][sum];
    if(res != -1){
        return res;
    }
    res = 0;
    int hi = tight ? s[pos] - '0' : 9;
    for(int i = 0; i <= hi; ++i){
        res += fn(s, pos - 1,(tight&&(i==hi)), ((rem * 10 ) + i) % targetSum, sum + i,  targetSum);
    }
    return res;
}

int64_t go(string s){
    
    reverse(s.begin(), s.end());
    int64_t res = 0;
    for(int sum = 1; sum < maxSum; ++sum){
        memset(dp,-1, sizeof(dp));
        res += fn(s, int(s.size()) - 1, 1, 0, 0, sum);
    }
    return res;
}


void solve(const int& tc){
    string R;
    cin >> R;
    cout << go(R) << '\n';
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
