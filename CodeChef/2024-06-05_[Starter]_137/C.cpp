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

static int n, k, a[N], h[N], pos[N];

void solve(const int& tc){
    cin >> n >> k;
    
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    for(int i = 0; i < n; ++i){
        cin >> h[i];
    }

    pos[0] = 0;
    int time = 0;
    for(int i = 0; i < n; ++i){
        auto net_pos = a[i] - time;
        if(net_pos - h[i] <= pos[i - 1]){
            pos[i] = net_pos - h[i] - 1; 
        }
        time += h[i];
    }

    for(int i = 0; i < n; ++i){
        cerr << pos[i] << ' ';
    }
    cerr << endl;
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
