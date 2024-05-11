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
    int n;
    cin >> n;
    vector<int>v(n);
    for(int& i : v){
        cin >> i;
    }
    for(int i = 1; i < n; ++i){
        if(v[i] > v[ 0 ]){
            cout << i + 1 << '\n';
            return;
        }
    }
    cout << "-1\n"; 
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
