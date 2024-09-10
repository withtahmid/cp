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
#define ts to_string
typedef long double ld;
typedef pair<int, int> pii;

const int N = 2e5 + 69;
int a[N], n;

const uint64_t offset = __lg(int(1e6)) + 1; // bitshift

inline uint64_t chash(uint64_t x, uint64_t y){
    return y | (x << offset);
}

inline uint64_t chash(uint64_t x, uint64_t y, uint64_t z){
    return z | (y << offset) | (x << ( 2 * offset));
}

void solve(const int& tc){
    cin >> n;
    
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    
    map<uint64_t, int> xy, yz, xz, xyz;
    
    for(int i = 2; i < n; ++i){
        int x = a[i - 2], y = a[i - 1], z = a[i];
        ++xyz[chash(x, y, z)], ++xy[chash(x, y)], ++yz[chash(y, z)], ++xz[chash(x, z)];
    }
    
    uint64_t res = 0LL;
    
    for(int i = 2; i < n; ++i){
        int x = a[i - 2], y = a[i - 1], z = a[i];
        auto tot = xyz[chash(x, y, z)];
        res += (xy[chash(x, y)] - tot) + (yz[chash(y, z)] - tot) + (xz[chash(x, z)] - tot);
    }

    cout << res / 2 << '\n';
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
