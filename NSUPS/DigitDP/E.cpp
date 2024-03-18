#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif


const int POS = 10;
const int offset = 45;
int64_t dp[POS][100][2];

int64_t fn(const string& s, int pos, int sum = 0, int tight = 1){
    if(pos == -1){
        return sum == 1 and int(s.size() > 1) ? 1 : 0;
    }
    int64_t& res = dp[pos][sum + offset][tight];
    if(res != -1){
        return res;
    }
    res = 0;
    int hi = tight ? s[pos] - '0' : 9;
    for(int i = 0; i <= hi; ++i){
        res += fn(s, pos - 1, (pos + 1) % 2 ? sum - i : sum + i, (tight and (i == hi)));
    }
    return res;
}

int64_t go(string s){
    reverse(s.begin(), s.end());
    return fn(s, int(s.size()) - 1);
}


int it(const string& s){
    int ev = 0, od = 0;
    for(int i = 0; i < int(s.size()); ++i){
        if(i&1) od += s[i] - '0';
        else ev += s[i] - '0';
    }
    return ev - od == 1 and int(s.size()) > 1 ? 1 : 0;
}

void solve(const int& tc){
    string l, r;
    cin >> l >> r;
    
    memset(dp, -1, sizeof(dp));
    auto Lres = go(l);
    
    memset(dp, -1, sizeof(dp));
    auto Rres = go(r);
    
    cout << Rres - Lres + it(l) << '\n';

}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
