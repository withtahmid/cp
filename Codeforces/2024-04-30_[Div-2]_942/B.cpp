/**
 *
 * Author: withtahmid
 * Created: 2024-04-30 20:34:29
 *
 **/
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

int n;
string s;


void solve(const int& case_no){
    cin >> n >> s;
    // cout << (fn() ? "YES" : "NO") << '\n'; 
    cout << (count(all(s), 'U') & 1 ? "YES" : "NO") << '\n';
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
