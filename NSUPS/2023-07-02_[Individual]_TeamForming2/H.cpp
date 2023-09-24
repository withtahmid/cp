/**
 * 
 * Author: withtahmid
 * Created: 2023-07-02 15:02:57
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
#define sp(n) fixed << setprecision(n)
#define len(v) ((int) v.size())
#define vec vector
#define forn(n) for(int i = 0; i < n; ++i)
typedef int_fast64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline bool in(auto&...args) { return (((cin >> args) ? true : false) && ...);}
inline void in(vector<auto>&v){for(auto&i:v){in(i);}}
inline void print(const auto&...args) {((cout << args), ...);}
inline void println(const auto&...args){ print(args..., '\n');}
template <typename T, typename... Rest>
inline constexpr T maxx(const T f, const Rest... r){return max({f, r...});}
template <typename T, typename... Rest>
inline constexpr T minn(const T f, const Rest... r){return min({f, r...});}
inline void operator>>(istream& istream, vector<auto>& v){for(auto& i:v){cin>>i;}}
void solve(int);
void before_tc(){}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL
    io();
    #endif
    time_t Time; time(&Time);cerr << ctime(&Time) << endl;
    auto starttime = chrono::steady_clock::now();
    bool multiple_test_case = not true;
    before_tc();
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>
    (chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}
const int MAXN = 100000 + 10;
vector<int>TREE[MAXN];
vector<int>color(MAXN);
vector<bool>visited(MAXN);
vector<pii>childs(MAXN);
pii dfs(int n){
    visited[n] = true;
    int black = 0;
    int white = 0;
    for(auto i : TREE[n]){
        if(not visited[i]){
            pii res = dfs(i);
            white += res.first;
            black += res.second;
        }
    }
    if(color[n] == 1){
        white += 1;
    }else{
        black += 1;
    }
    childs[n] = {white, black};
    dbg(n, white, black);
    return {white, black};
}

void solve(int case_no){
    int n;
    cin >> n;
    int tolat_white = 0;
    for(int i = 0; i < n; ++i){
        cin >> color[i];
        tolat_white += color[i];
    }
    for(int i = 0; i + 1 < n; ++i){
        int u, v;
        cin >> u >> v;
        TREE[u].pb(v);
        TREE[v].pb(u);
    }
    dfs(0);
    int res = 0;
    pii temp_pair;
    for(int i = 0; i  < n; ++i){
        int temp = childs[i].second - childs[i].first;
        if(temp > res){
            res = temp;
            temp_pair = childs[i];
        }
       
    }
    tolat_white += temp_pair.second;
    tolat_white -= temp_pair.first;
    cout << tolat_white << endl;

}