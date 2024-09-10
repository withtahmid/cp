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
typedef long double ld;
typedef pair<int, int> pii;

string s;
const int N = 1e5 + 69;
int dp[N][4], n;

int wins(char c, int t){
    return ((c == 'R'  and t == 1) or (c == 'P' and t == 2) or (c == 'S' and t == 0)) ? 1 : 0;
}

int fn(int i = 0, int prev = 3){
    if(i == int(s.size())){
        return 0;
    }
    int& res = dp[i][prev];
    if(res != -1){
        return res;
    }
    res = 0;
    for(int rpc = 0; rpc <= 2; ++rpc){
        if(rpc != prev){
            res = max(res, fn(i + 1, rpc) + wins(s[i], rpc));
        }
    }
    return res;
}


void solve(const int& case_no){

    cin >> n >> s;
    
    for(int i = 0; i < n; ++i) for(int j = 0; j < 4; ++j){
        dp[i][j] = -1;
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
