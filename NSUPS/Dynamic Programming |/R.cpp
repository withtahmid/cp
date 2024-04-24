#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

const int N = 5000 + 69;

string s;

int64_t dp[N]; 
int n;

int64_t fn(int i = 0){
    if(i == n){
        return 1;
    }
    int64_t& res = dp[i];
    if(res != -1){
        return res;
    }
    int dig = s[i] - '0';
    if(dig == 0){
        return 0;
    }
    if(i + 1 < n){
        dig = (dig * 10) + (s[i + 1] - '0');
    }
    if(dig == 10 or dig == 20){
        res = fn(i + 2);
    }else if(i + 1 < n and dig <= 26){
        res = fn(i + 1) + fn(i + 2);
    }else{
        res = fn(i + 1);
    }
    return res;
}

void solve(const int& tc){
    while(cin >> s and s != "0"){
        ::n = int(s.size());
        memset(dp, -1, sizeof(dp));
        cout << fn() << '\n'; 
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
