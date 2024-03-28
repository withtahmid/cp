#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif



const int maxDigit = 22;
pair<int, int64_t> dp[maxDigit][2][9 * 20];

pair<int, int64_t> MAX(pair<int, int64_t> a, pair<int, int64_t> b){
    if(a.first == b.first){
        if(a.second > b.second){
            return a;
        }
        return b;
    }
    if(a.first > b.first){
            return a;
    }
    return b;
}

pair<int, int64_t> fn(const string& s, int pos, int tight, int sum, int64_t num){
    if(pos == -1){
        return make_pair(sum, num);
    }
    pair<int, int64_t>& res = dp[pos][tight][sum];
    if(res.first != -1 and res.second != -1){
        return res;
    }
    res = make_pair(0, 0);
    int hi = tight ? s[pos] - '0' : 9;
    // iterate from bigger to smaller number 
    for(int i = hi; i >= 0; --i){
        res = MAX(res, fn(s, pos - 1,(tight&&(i==hi)), sum + i, num * 10  + i));
    }
    return res;
}

pair<int, int64_t> go(string s){
    reverse(s.begin(), s.end());
    return fn(s, int(s.size()) - 1, 1, 0, 0);
}



void solve(const int& tc){
    string R;
    cin >> R;
    auto res = go(R);
    cout << res.second << '\n';
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(dp,-1, sizeof(dp));
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
