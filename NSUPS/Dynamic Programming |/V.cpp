#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

int64_t dp[100069];

int64_t fn(vector<int64_t>& v, map<int64_t, int64_t>& cnt, int i = 0){
    if(i >= int(v.size())){
        return 0;
    }
    int64_t& res = dp[i];
    if(res != -1){
        return res;
    }
    res = fn(v, cnt, i + 1);
    if(i + 1 < int(v.size()) and v[i] + 1 == v[i + 1]){
        res = max(res, fn(v, cnt, i + 2) + (cnt[v[i]] * v[i]));
    }else{
        res = max(res, fn(v, cnt, i + 1) + (cnt[v[i]] * v[i]));
    }
    return res;
}

void solve(const int& tc){
    int n;
    cin >> n;
    vector<int64_t>v(n);
    map<int64_t, int64_t>mp;
    for(int i = 0; i < n; ++i){
        cin >> v[i];
        ++mp[v[i]];
    }
    sort(v.begin(), v.end());
    vector<int64_t>un = {v.front()};
    for(int i = 1; i < n; ++i){
        if(v[i] != un.back()){
            un.emplace_back(v[i]);
        }
    }
    memset(dp, -1, sizeof(dp));
    dbg(un);
    cout << fn(un, mp) << '\n';
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
