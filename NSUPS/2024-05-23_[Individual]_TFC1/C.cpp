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

const int N = 1e3 + 69;
int n, a[N];
int64_t dp[N][2][2];

int64_t fn(int i = 0, int prev = 0, int taken_first = 0){
    int64_t& res = dp[i][prev][taken_first];
    if(res != -1){
        return res;
    }
    if(i == 0){
        res = max(fn(i + 1, 0, 0), fn(i + 1, 1, 1) + a[i]);
        
        return res;
    }
    else if(i == (n - 1)){
        if(not prev and not taken_first){
            res = a[i];
        }else{
            res = 0;
        }
        return res;
    }
    res = fn(i + 1, 0, taken_first);;
    if(prev != 1){
        res = max(res, fn(i + 1, 1, taken_first) + a[i]);
    }
    return res;
}

void solve(const int& tc){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << "Case " << tc <<": " << fn() << '\n';
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
