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
typedef long double ld;
typedef pair<int, int> pii;

void solve(const int& case_no){
    int n, k;
    cin >> n >> k;
    vector<int>v(n);
    for(int& i : v){
        cin >> i;
    }
    int em = k, res = 0;
    for(int i = 0; i < n; ++i){
        while(i < n and em >= v[i]){
            em -= v[i], ++i;
        }
        --i, em = k, ++res;
    }
    cout << res << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0); 
    dbg(ok());
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        dbg(kes(tc));
        solve(tc);
    }
    dbg(bye());
}
