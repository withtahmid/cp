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

void solve(const int& tc){
    int n, m;
    string s;
    
    cin >> n >> m >> s;
 
    map<char, int> cnt;
    for(auto& c : s){
        ++ cnt[c];
    }
    
    int res = 0;
    
    for(char i = 'A'; i <= 'G'; ++i){
        if(cnt[i] < m){
            res += m - cnt[i];
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
