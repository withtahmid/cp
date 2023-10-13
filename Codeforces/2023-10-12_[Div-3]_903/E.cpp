/**
 *
 * Author: withtahmid
 * Created: 2023-10-12 20:31:49
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
    bool test_case = true;
    int tc = 1; if(test_case){cin >> tc;}
    for(int i = 1; i <= tc; ++i){
        solve(i);
    }
    dbg(__elapsed__());
}
void precompute(){}

const int maxn = 2e5;
int dp[maxn];
int n;
vi v;
int fn(int i){
    if(i == n){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    int res = fn(i + 1) + 1;
    if(i + v[i]  + 1 <= n){
        int res_2 = fn(i + v[i] + 1);
        res = min(res, res_2);
    }
    return dp[i] = res;
}

void solve(const int case_no){
    cin >> n;
    v.resize(n);
    cin >> v;
    mem(dp, -1);
    cout << fn(0) << endl;
}
