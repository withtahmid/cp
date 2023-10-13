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
void solve(const int case_no){
    int n;
    cin >> n;
    char grid[n][n];
    int  vis[n][n];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            char in;
            cin >> in;
            grid[i][j] = in;
            vis[i][j] = 0;
        }
    }

    ll res = 0;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            
            if(vis[i][j] == 1){
                continue;
            }

            int p = j, q = n - i - 1; 
            int r = n - i - 1, s = n - j - 1;
            int u = n - j - 1, v = i;

            vis[i][j] = vis[p][q] = vis[r][s] = vis[u][v] = 1;

            char m = _max(
                        grid[i][j],
                        grid[p][q],
                        grid[r][s],
                        grid[u][v]
                    );
            
            res +=  abs(grid[i][j] - m) + 
                    abs(grid[p][q] - m) + 
                    abs(grid[r][s] - m) + 
                    abs(grid[u][v] - m);
            
        }
    }
    cout << res << endl;
}
