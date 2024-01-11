/**
 *
 * Author: withtahmid
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


const int maxn = 110;
int dp[maxn][4];
int n;
vector<int>v(maxn);
int fn(int i, int prev){
    if(i >= n){
        return 0;
    }
    if(dp[i][prev] != -1){
        return dp[i][prev];
    }
    int res = INT_MAX;
    if(v[i] == 1){
        if(prev != 1){
            res = min(res, fn(i + 1, 1));
        }
    }
    if(v[i] == 2){
        if(prev != 2){
            res = min(res, fn(i + 1, 2));
        }
    }
    if(v[i] == 3){
        if(prev != 1){
            res = min(res, fn(i + 1, 1));
        }
        if(prev != 2){
            res = min(res, fn(i + 1, 2));
        }
    }
    res = min(res, fn(i + 1, 0) + 1);
    return  dp[i][prev] = res;
}
void solve(const int case_no){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    mem(dp, -1);
    cout << fn(0, 3) << endl;
}
