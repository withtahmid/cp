#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL 
#include <debug.h>
#else
#define dbg(...)
#endif

#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define int int64_t
typedef long double ld;
typedef pair<int, int> pii;

void solve(const int& tc){
    int n;
    cin >> n;
    vector<string>v(n);
    for(auto& i : v) cin >> i;
    reverse(all(v));
    for(int i = 0; i < n; ++i){
        string s = v[i];
        for(int j = 0; j < 4; ++j){
            if(s[j] == '#'){
                cout << (j + 1) << ' ';
                break;
            }
        }
    }
    cout << '\n';

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
