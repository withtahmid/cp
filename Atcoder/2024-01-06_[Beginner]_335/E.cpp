/**
 *
 * Author: withtahmid
 * Created: 2024-01-06 17:58:21
 *
 **/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...)
#define dbg(...)
#define init(...)
#endif
#define endl '\n'
#define pb push_back
#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define has(x, y) (x.find(y) != x.end())
typedef int_fast64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
inline constexpr auto _max(const auto f, const auto... r){return max({f, r...});}
inline constexpr auto _min(const auto f, const auto... r){return min({f, r...});}
inline void operator>>(istream& istream, vector<auto>&v){for(auto& i:v){cin>>i;}}
void solve(int);
void precompute();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init();
    precompute();
    bool test_case = not true;
    int tc = 1; if(test_case){cin >> tc;}
    for(int i = 1; i <= tc; ++i){
        solve(i);
    }
    dbg(__elapsed__());
}
const int maxn = (2 * 1e5) + 69;
const int oo = INT_MAX;
void precompute(){}
vector<int>graph[maxn];
vector<int>score(maxn);
vector<bool>vis(maxn);
int n, m;
// ll fn(int n, int prev){
//     if(score[n] < score[prev]){
//         vis[n] = true;
//         return;
//     }
    

// }
void solve(const int case_no){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int v, u;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    queue<int>q;
    q.push(n);
    while(not q.empty()){
        int x = q.front();
        q.pop();
        for(auto i : graph[x]){
            if()
        }
    }
}
