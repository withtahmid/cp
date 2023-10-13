/**
 *
 * Author: withtahmid
 * Created: 2023-10-10 19:12:49
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
#define mem(x, y) memset(x, y, sizeof(x))
typedef int_fast64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
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
void precompute(){}

const int maxn = 1010;

struct edge{
    int v, w;
    bool f = true;
};

vector<edge>graph[maxn];
int n, m, k, s;

vector<bool>visited(maxn);

const ll inf = 1e13;

vector<ll>dist_arr(maxn, inf);

ll dp[maxn][maxn];

int fn(int i, int left, ll cost){
    
    visited[i] = true;
    dist_arr[i] = min(dist_arr[i], cost);
    for(auto x : graph[i]){
        if(not visited[x.v]){
            if(x.f){
                fn(x.v, left, cost + x.w);
            }
            else if(left > 0){
                fn(x.v, left - 1, cost + x.w);
            }
        }
    }
    visited[i] = false;
    return 1;
}

void solve(const int case_no){
    
    cin >> n >> m >> k >> s;

    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].pb({v, w, true});
        graph[v].pb({u, w * 2, false});
    }

    fn(s, k, 0LL);

    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        cout << (dist_arr[x] >= inf ? -1 : dist_arr[x]) << endl;
    }

}
