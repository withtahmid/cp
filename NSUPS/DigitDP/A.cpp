#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

int dp[55][20][20][20][2];

const int mod = 1000000007;

int fn(string& s, int pos = 0, int three = 0, int six = 0, int nine = 0, int tight = 0){
    const int n = s.size();
    if(pos == int(s.size())){
        return (three == six and six == nine and three > 0) ? 1 : 0;
    }
    if(three > 16 or six > 16 or nine > 16){
        return 0;
    }
    int& res = dp[pos][three][six][nine][tight];
    if(res != -1 and not tight){
        return res;
    }
    res = 0;
    if(tight){
        for(int i = 0; i < (s[pos] - '0'); ++i){
            res += fn(s, pos + 1, three + (i == 3), six + (i == 6), nine + (i == 9), 0);
            res %=  mod;           
        }
        int dig = (s[pos] - '0');
        res += fn(s, pos + 1, three + (dig == 3), six + (dig == 6), nine + (dig == 9), 1);
        res %=  mod;
    }else{
        for(int i = 0; i <= 9; ++i){
            res += fn(s, pos + 1, three + (i == 3), six + (i == 6), nine + (i == 9), 0);
            res %=  mod;           
        }
    }
    return res;
}

void solve(const int& tc){
    string a, b;
    cin >> a >> b;
    auto addPadding = [](string& s) -> void{
        reverse(s.begin(), s.end());
        while(int(s.size()) < 51) {
            s.push_back('0');
        }
        reverse(s.begin(), s.end());
    };

    addPadding(a), addPadding(b);

    auto cnt = [](string s) -> int{
        int a = 0, b = 0, c = 0;
        for(auto& x : s){
            a += x == '3', b += x == '6', c += x == '9';
        }
        return a == b and b == c and c > 0 ?  1 : 0; 
    };
    
    cout << (fn(b) - fn(a) + mod + (cnt(a))) % mod << '\n';
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp, -1, sizeof(dp));
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
