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

static int n, a[N];

void solve(const int& tc){
    
    cin >> n;
    
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    
    sort(a, a + n);
    
    int ai = a[0], aj = 1e9 + 7;

    for(int i = 1; i < n; ++i){
        if(a[i] % ai != 0){
            aj = a[i];
            break;
        }
    }

    for(int i = 0; i < n; ++i){
        if((a[i] % ai != 0) and (a[i] % aj != 0)){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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
