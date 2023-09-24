/**
 * 
 * Author: withtahmid
 * Created: 2023-08-26 16:28:19
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
typedef int_fast64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline void print(const auto&...args) {((cout << args), ...);}
inline void println(const auto&...args){ print(args..., '\n');}
template <typename T, typename... Rest>
inline constexpr T _max(const T f, const Rest... r){return max({f, r...});}
template <typename T, typename... Rest>
inline constexpr T _min(const T f, const Rest... r){return min({f, r...});}
inline void operator>>(istream& istream, vector<auto>& v){for(auto& i:v){cin>>i;}}
inline void operator>>(istream& istream, deque <auto>& d){for(auto& i:d){cin>>i;}}
void solve(int);
void before_tc();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL
    io();
    time_t Time; time(&Time);cerr << ctime(&Time) << endl;
    auto starttime = chrono::steady_clock::now();
    #endif
    bool multiple_test_case = not true;
    before_tc();
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    #ifdef LOCAL
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>
    (chrono::steady_clock::now() - starttime).count() << " millisecond\n";
    #endif
    
}
void before_tc(){}


const int maxn = (2 * 1e5) + 100;
vector<int> graph[maxn];
vector<bool>visited(maxn, false);
vector<int>color(maxn);

int dfs(map<int,int>&mp, int n){
    visited[n] = true;
    mp[color[n]]++;
    int size = 1;
    for(auto i : graph[n]){
        if(not visited[i]){
            size += dfs(mp, i);
        }
    }
    return size;
}

void solve(int case_no){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i){
        cin >> color[i];
    }
    set<pii>st;
    for(int i = 0; i < m; ++i){
        int l, r;
        cin >> l >> r;
        if( r < l){
            swap(l,r);
        }
        if(st.contains(make_pair(l, r))){
            continue;
        }
        st.insert(make_pair(l,r));
        graph[l].pb(r);
        graph[r].pb(l);
    }
    map<int, int>mp;
    int res = 0;
    for(int i = 1; i <= n; ++i){
        if(not visited[i]){
            int size = dfs(mp, i);
            dbg(i, size, mp);
            int mx = 0;
            for(auto it : mp){
                mx = max(it.second, mx);
            }
            res += size - mx;
            mp.clear();    
        }
    }
    cout << res << endl;

}