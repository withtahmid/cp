#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

const int N = (1 << 10) + 10;

int64_t dp[21][2][2][N][N];

int64_t fn(string& s, int pos, int tight = 1, int zero = 1, int used = 0 , int state = 0){
    if(pos == -1){
        for(int i = 0; i <= 9; ++i){
            if(((used >> i) & 1) and ((i & 1) == ((state >> i) & 1))){
                return 0;
            }
        }
        return 1;
    }
    int64_t& res = dp[pos][tight][zero][used][state];
    
    if(res != -1 and not tight){
        return res;
    }

    res = 0;

    const int lim  = tight ? s[pos] - '0' : 9;

    for(int i = 0; i <= lim; ++i){
        res += fn(s, pos - 1, tight and (i == lim), zero and (i == 0), zero and (i == 0) ? used : used | (1 << i), zero and (i == 0) ? state : state ^ (1 << i));
    }
    return res;
}

void solve(const int& tc){
    
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end()), reverse(b.begin(), b.end());

    const auto cnt = [](const string& num) -> int{
        map<int, int>mp;
        for(int i = 0; i < num.size(); ++i){
            ++mp[num[i] - '0'];
        }
        for(auto[k, v] : mp){
            if((k & 1) == (v & 1)){
                return 0;
            }
        }
        return 1;
    };

    cout << fn(b, b.size() - 1) - fn(a, a.size() - 1) + cnt(a)<< '\n';

}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    memset(dp, -1, sizeof(dp));
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
