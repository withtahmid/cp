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

map<char, pii> dir = {

    { 'W',   { +0, -1 } },{ 'E',   {  0, +1 } },
    { 'N',   { -1, +0 } },{ 'S',   { +1, +0 } },
};

string res = "NULL";
string direct = "NULL";

pii addpii(pii a, pii b){
    return make_pair(a.first + b.first, a.second + b.second);
}

void fn(map<char, int> mp, pii p1, pii p2, string s, string d){
    if(len(mp) == 0){
        if(p1 == p2 and count(all(s), 'R') != 0 and count(all(s), 'H') != 0){
            res = s;
            direct = d;
        }
        return;
    }
    for(auto [c, cnt]: mp){
        auto t = mp;
        t[c] -= 1;
        if(t[c] == 0) {
            t.erase(c);
        }
        fn(t, addpii(p1, dir[c]), p2, s + "R", d + c);
        fn(t, p1, addpii(p2, dir[c]), s + "H", d + c);
    }
}

void solve(const int& tc){
    int n;
    string s;
    cin >> n >> s;
    map<char, int> mp;
    map<char, vector<int>> idx;
    for(int i = 0; i < n; ++i){
        ++mp[s[i]];
        idx[s[i]].emplace_back(i);
    }
    dbg(mp);
    auto mp2 = mp;
    // for(auto& [k, v] : mp){
    //     v %= 4;
    // }
    res = "NULL";
    direct = "NULL";

    fn(mp, {0, 0}, {0, 0}, "", "");
    dbg(res);
    dbg(direct);
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
