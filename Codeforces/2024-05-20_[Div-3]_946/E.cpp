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

string s, res;

int n, dp[N];

map<char, pii> dir = {

    { 'W',   { -1, 0 } },{ 'E',   {  +1, 0 } },
    { 'N',   { 0, +1 } },{ 'S',   { 0, -1 } },
};

pii addpii(pii a, pii b){
    return make_pair(a.first + b.first, a.second + b.second);
}

void fn(int i, pii p1, pii p2, string d){
    if(i == n){
        dbg(d);
        if(p1 == p2 and count(all(s), 'R') != 0 and count(all(s), 'H') != 0){
            ::res = d;
        }
        return;
    }

    fn(i + 1, addpii(p1, dir[s[i]]), p2, d + 'H');
    fn(i + 1, p1, addpii(p2, dir[s[i]]), d + 'R');
}

void solve(const int& tc){
    cin >> n >> s;
    dbg(n, s);
    
    ::res = "NO";
    
    fn(0, {0, 0}, {0, 0}, "");

    cout << ::res << '\n';

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
