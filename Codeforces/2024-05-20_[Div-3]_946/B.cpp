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
    string s;
    int n;
    cin >> n >> s;
    set<char>st;
    for(auto c : s){
        st.insert(c);
    }
    vector<char>v(all(st));
    map<char, char> dict;
    for(int i = 0; i < len(v) / 2 + (len(v) & 1); ++i){
        dict[v[i]] = v[len(v) - i - 1];
        dict[v[len(v) - i - 1]] = v[i];
    }
    for(auto c : s){
        cout << dict[c];
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
