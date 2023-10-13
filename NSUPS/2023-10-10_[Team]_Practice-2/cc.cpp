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
vector<int> ones(maxn);
ll dp [maxn][maxn];
int n, m;
ll fn (int i, int prev){
    if(i == m){
        return 0;
    }

    if(dp[i][prev] != -1){
        return dp[i][prev];
    }

    ll cost_1, cost_2, cost_3;

    ll result;

    if(prev == 0){
        cost_1 = abs(prev - ones[i]);
        cost_2 = abs((prev + 1) - ones[i]);
        result  = _min(
            fn(i + 1, prev) + cost_1,
            fn(i + 1, prev + 1) + cost_2
            );
    }
    else if(prev + 1 == n){
        cost_1 = abs(prev - ones[i]);
        cost_3 = abs((prev - 1) - ones[i]);
        result  = _min(
            fn(i + 1, prev) + cost_1,
            fn(i + 1, prev - 1) + cost_3
            );
    }
    else{
        cost_1 = abs(prev - ones[i]);
        cost_2 = abs((prev + 1) - ones[i]);
        cost_3 = abs((prev - 1) - ones[i]);

        result  = _min(
            fn(i + 1, prev) + cost_1,
            fn(i + 1, prev + 1) + cost_2,
            fn(i + 1, prev - 1) + cost_3
            );
    }
    return dp[i][prev] =  result;
}

void solve(const int case_no){
    
    
    cin >> n >> m;
    int grid[n][m];
    for(int i = 0 ; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> grid[i][j];
        }

    }

    ones.resize(m);

    for(int i = 0 ; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j] == 1){
                ones[j] = i;
            }
        }
    }

    mem(dp, -1);
    ll res = LLONG_MAX;
    for(int row = 0; row < n; ++ row){
        ll initial = abs(row - ones[row]);
        res = min(
                res,
                fn(1, row)  + initial 
            );
        dbg(row, initial);
    }

    cout << res << endl;
}