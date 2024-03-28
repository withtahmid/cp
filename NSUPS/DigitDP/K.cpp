#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif



const int maxDigit = 22;

int dp[maxDigit][2][20 * 9];

int mx = 0;
int64_t result = 0;

int fn(const string& s, int pos, int tight, int sum, int64_t number){
    if(pos == -1){
        if(sum > ::mx){
            ::mx = sum;
            ::result = number;
        }
        return sum;
    }
    int& res = dp[pos][tight][sum];
    if(res != -1){
        return res;
    }
    res = 0;
    int hi = tight ? s[pos] - '0' : 9;

    // iterate from bigger to smaller number 
    for(int i = hi; i >= 0; --i){
        res = max(res, fn(s, pos - 1,(tight&&(i==hi)), sum + i, (number * 10) + i));
    }
    return res;
}


void solve(const int& tc){
    string R;
    cin >> R;
    reverse(R.begin(), R.end());
    memset(dp,-1, sizeof(dp));
    fn(R, R.length() - 1, 1, 0, 0);
    cout << ::result << '\n';
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
