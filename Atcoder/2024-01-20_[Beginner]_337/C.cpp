/**
 *
 * Author: withtahmid
 * Created: 2024-01-20 18:01:22
 *
 **/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...)
#define dbg(...)
#endif
#define endl '\n'
#define pb push_back
#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define has(x, y) (x.find(y) != x.end())
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
inline auto _max(const auto f, const auto... r){return max({f, r...});}
inline auto _min(const auto f, const auto... r){return min({f, r...});}
inline void print(const auto &...a) {((cout << a), ...);}
inline void println(const auto &...a) {print(a..., '\n');}
inline bool read(auto &...a) {return (((cin >> a) ? true : false) && ...);}
inline void read(pair<auto, auto>& p){read(p.first, p.second);}
inline void read(vector<auto>& v) {for(auto& i : v){read(i);}}
void solve(int);
void precompute();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dbg(__init__());
    precompute();
    bool test_case = not true;
    int tc = 1; if(test_case){read(tc);}
    for(int i = 1; i <= tc; ++i){
        dbg(__case__(i));
        solve(i);
    }
    dbg(__elapsed__());
}
const int maxn = (3 * 1e5) + 69;
const int mod = (1e9 + 7);
const int oo = INT_MAX;
const ll OO = LLONG_MAX;
void precompute(){}
vector<int>graph[maxn];
vector<bool>vis(maxn);
vector<int>res;
void dfs(int n){
    vis[n] = true;
    for(auto i : graph[n]){
        if(not vis[i]){
            dfs(i);
        }
    }
    res.pb(n);
}
void solve(const int case_no){
    int n;
    read(n);
    vector<int>v(n);
    fill(all(vis), false);
    read(v);
    dbg(v);
    int s ;
    for(int i = 0; i < n; ++i){
        if(v[i] == -1){
            s = i + 1;
        }
        else{
            graph[v[i]].pb(i + 1);
        }
    }
    dfs(s);
    reverse(all(res));
    for(auto& i : res){
        print(i, " ");
    }
    println();
}
