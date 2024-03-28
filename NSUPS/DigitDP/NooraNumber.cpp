#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif


const int maxDigit = 20;
const int N = (1 << 10) + 10;
int64_t dp[maxDigit][2][2][N];

inline bool isNoora(int& mask){
    int mx = 10;
    int cnt = 0;
    for(int i = 9; i >= 0; --i){
        if(mx == 10 and ((mask >> i) & 1)) mx = i;
        if((mask >> i) & 1) ++cnt;
    }
    return mx == cnt ? true : false;
}

int64_t fn(const string& s, int pos, int tight = 1, int zero = 1, int mask = 0){
    if(pos == -1){
        return isNoora(mask) ? 1  : 0;
    }
    int64_t& res = dp[pos][tight][zero][mask];
    if(res != -1 and not tight){
        return res;
    }
    res = 0;
    int hi = tight ? s[pos] - '0' : 9;
    for(int i = 0; i <= hi; ++i){
        res += fn(s, pos - 1,(tight&&(i==hi)), zero&&(i==0), zero&&(i==0) ? mask : mask | (1 << i));
    }
    return res;
}

int64_t go(string s){
    reverse(s.begin(), s.end());
    return fn(s, int(s.size()) - 1);
}

void solve(const int& tc){
    string R;
    cin >> R;
    cout << go(R) << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(dp,-1, sizeof(dp));
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
