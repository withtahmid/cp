/**
 *
 * Author: withtahmid
 * Created: 2023-10-02 21:59:28
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
inline constexpr auto max(const auto f, const auto... r){return max({f, r...});}
inline constexpr auto min(const auto f, const auto... r){return min({f, r...});}
inline void operator>>(istream& istream, vector<auto>&v){for(auto& i:v){cin>>i;}}
void solve(int);
void precompute();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init();
    precompute();
    bool test_case = true;
    int tc = 1; if(test_case){cin >> tc;}
    for(int i = 1; i <= tc; ++i){
        solve(i);
    }
    dbg(__elapsed__);
}
void precompute(){}

const int maxn = 1e6 + 10;
vector<int> graph[maxn];
vector<bool> visited(maxn);
vector<int> card(maxn);
const ll p = 31;
const ll mod = 9223372036854775807;

pair<ll, ll> fn(pair<ll, ll>&hash, int& ln, int& digit, ll& pow){
    ll fr = (((pow * digit) % mod) + hash.first) % mod;
    ll br = (((hash.second * p) % mod) + digit) % mod;
    return make_pair(fr, br);
}

int dfs(int n, int ln, pair<ll, ll> hash, ll pow){
    visited[n] = true;
    pair<ll, ll> new_hash = fn(hash, ln, card[n], pow);
    int res = (new_hash.first == new_hash.second ? 1 : 0);
    for(auto i : graph[n]){
        if(not visited[i]){
            res += dfs(i, ln + 1, new_hash, (pow * p) % mod);
        }
    }
    return res;
}

void solve(const int case_no){
    int n;
    cin >> n;
    string str;
    cin >> str;
    const auto ctoi = [](const char c){
        return (int) (c - 'A') + 1;
    };
    for(int i = 1; i <= n; ++i){
        card[i] = ctoi(str[i-1]);
        visited[i] = false;
        graph[i].clear();
    }
    for(int i = 1;  i < n; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    int cnt = dfs(1, 0, {0LL, 0LL}, 1);
    int gcd = __gcd(cnt, n);
    cnt /= gcd;
    n /= gcd;
    cout <<"Case "  <<  case_no <<": " << cnt << "/" << n << endl;
}
