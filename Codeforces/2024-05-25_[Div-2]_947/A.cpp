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

const int N = 58;

int n, a[N];

void solve(const int& tc){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    
    auto ok = [&](int x) -> bool{
        vector<int> v;
        for(int i = x; i < n; ++i){
            v.emplace_back(a[i]);
        }
        for(int i = 0; i < x; ++i){
            v.emplace_back(a[i]);
        }
        for(int i = 1; i < n; ++i){
            if(v[i] < v[i - 1]){
                return false;
            }
        }
        return true;
    };

    for(int i = 1; i < n; ++i){
        if(a[i] < a[i - 1]){
            if(not ok(i)){
                cout << "NO\n";
                return;
            }
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
