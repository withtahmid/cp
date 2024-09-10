#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL 
#include <debug.h>
#else
#define dbg(...)
#endif

#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define has(v, x) ((v.find(x) != v.end()))
#define int int64_t
typedef long double ld;
typedef pair<int, int> pii;


const int N = 210;

string s;

map<int64_t, int64_t>dp[N];
const int64_t MX = (1ULL << 31) - 1;
int64_t fn(int i = 0, int64_t dig = 0){
    if(i == int(s.length())){
        return dig;
    }
    if(dp[i].count(dig)){
        return dp[i][dig];
    }
    int64_t& res = dp[i][dig];

    if(((dig * 10) + (s[i] - '0')) >= MX){
        return res = fn(i + 1, s[i] - '0') + dig;
    }
    res = fn(i + 1, s[i] - '0') + dig;
    res = max(res, fn(i + 1, ((dig * 10) + (s[i] - '0'))));
    return res;
}

void solve(const int& tc){
    
    cin >> s;
    
    for(int i = 0; i < len(s); ++i) {
        dp[i].clear();
    }
    
    cout << fn() << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0); 
    dbg(ok());
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        dbg(kes(tc));
        solve(tc);
    }
    dbg(bye());
}
