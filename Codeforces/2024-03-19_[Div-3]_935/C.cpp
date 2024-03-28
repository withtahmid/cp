#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

#define int int64_t

void solve(const int& tc){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int>one(n), zero(n);
    for(int i = 0; i < n ; ++i){
        one[i] = s[i] == '1';
        zero[i] = s[i] == '0';
    }

    partial_sum(one.begin(), one.end(), one.begin());
    partial_sum(zero.begin(), zero.end(), zero.begin());
    
    auto half = [](int total, int agree){
        return total <= (agree * 2);
    };

    auto leftok = [&](int i){
        if(i == 0) return true;
        int z = zero[i];
        // dbg(z);
        return half(i + 1, z);
    };

    auto righttok = [&](int i){
        if(i == n - 1) return true;
        int o = one.back() -  (i > 0 ? one[i - 1] : 0);
        return half(n - i + 1, o);
    };

    auto ok = [&](int i){
        return leftok(i) and righttok(i);
    };

    dbg(ok(0));

    vector<int>res(n);
    for(int i = 0; i < n; ++i){
        res[i] = ok(i);
    }

    dbg(res);

    int mid = ((n - 1) / 2);
    int ans = 0, dis = mid;

    for(int i = n - 1; i >= 0; --i){
        if(not res[i]) continue;
        if(abs(mid - i) <= dis){
            dis = abs(mid - i), ans = i + 1;
        }
        // dbg(ans, dis);
    }

    cout << dis << " " << ans << '\n';
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    dbg(__init__());
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        dbg("\nTC ", tc, "\n");
        solve(tc);
    }
    dbg(__elapsed__());
}
