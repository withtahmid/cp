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

const int N = 2e5 + 69;

int n, a[N], b[N + 1];

void solve(const int& tc){
    
    cin >> n;
    
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    
    for(int i = 0; i - 1 < n; ++i){
        cin >> b[i];
    }
    
    int cost = INT_MAX;

    int64_t res = 0LL;

    for(int i = 0; i < n; ++i){
        res += abs(a[i] - b[i]);
        cost = min({cost, abs(b[n] - b[i]) + 1, abs(b[n] - a[i]) + 1});
        if((a[i] <= b[n] and b[n] <= b[i]) or (b[i] <= b[n] and  b[n] <= a[i])){
            cost = 1;
        }
    }
    cout << res + cost << '\n';

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
