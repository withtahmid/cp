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

const int N = 1e5 + 69;
string s;
int n, pf_0[N], pf_1[N];

void solve(const int& tc){
    cin >> n >> s;
    for(int i = 0; i < n; ++i){
        pf_0[i] = s[i] == '0', pf_1[i] = s[i] == '1';
    }
    for(int i = 1; i < n; ++i){
        pf_0[i] += pf_0[i - 1], pf_1[i] += pf_1[i - 1];
    }
    

    map<int, int>gap;
    
    for(int i = 0; i < n; ++i){
        ++gap[pf_0[i] - pf_1[i]];
    }

    map<int, int>used;
    int prev = 0;
    int64_t res = (n * (n + 1 )) / 2;
    for(int i = 0; i < n; ++i){
        res += (gap[prev] - used[prev]), prev = pf_0[i] - pf_1[i], used[prev]++;
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
