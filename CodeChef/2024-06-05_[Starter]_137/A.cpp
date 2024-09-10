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

const int N = 1000 + 69;

int n, k, a[N];

void solve(const int& tc){
    cin >> n >> k;
    
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    int64_t res = 0LL;

    for(int i = 1; i < n; ++i){
        res += abs(a[i - 1] - a[i]);
    }

    int mx = 0;

    for(int i = 1; i + 1 < n; ++i){
        auto previous = abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1]);
        auto put_one =  abs(a[i - 1] - 1) + abs(1 - a[i + 1]);
        auto put_k = abs(a[i - 1] - k) + abs(k - a[i + 1]);
        auto optimum = max({put_k, put_one, previous});
        mx = max(mx, optimum - previous);
        assert(mx >= 0);

    }
    if(n > 1){
        auto previous = abs(a[1] - a[0]);
        auto put_one =  abs(a[1] - 1);
        auto put_k = abs(a[1] - k);
        auto optimum = max({put_k, put_one, previous});
        mx = max(mx, optimum - previous);
        assert(mx >= 0);

    }
    if(n > 2){
        auto previous = abs(a[n - 2] - a[n - 1]);
        auto put_one =  abs(a[n - 2] - 1);
        auto put_k = abs(a[n - 2] - k);
        auto optimum = max({put_k, put_one, previous});
        mx = max(mx, optimum - previous);
        assert(mx >= 0);
    }
    
    cout << res + mx << '\n';


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
