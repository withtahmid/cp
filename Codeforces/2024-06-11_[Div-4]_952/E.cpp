#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL 
#include <debug.h>
#else
#define dbg(...)
#endif

const int64_t N = 2e5 + 69;

static int h, n, a[N], c[N]; 

void solve(const int& tc){
    cin >> h >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> c[i];
    }

    int64_t l = 1, r = N * N,  res = N * N;

    auto can_defeat_with_this_time = [&](int64_t time) -> bool{
        int64_t total_damage = 0LL;
        for(int i = 0; i < n; ++i){
            int64_t use = (time / c[i]) + (time % c[i] != 0);
            total_damage += use * a[i]; 
        }
        return total_damage >= h ? true : false;
    };

    while(l <= r){
        int64_t mid = (l + r) >> 1;
        if(can_defeat_with_this_time(mid)){
            r = mid - 1, res = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << res << '\n';
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
