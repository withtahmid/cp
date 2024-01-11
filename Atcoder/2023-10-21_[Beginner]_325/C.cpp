/**
 *
 * Author: withtahmid
 * Created: 2023-10-21 17:58:41
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
int n, m;
const int maxn = 1010;
char grid[maxn][maxn];
int idir[] = {-1, -1, -1,  0,  0, +1, +1, +1};
int jdir[] = {-1,  0, +1, -1, +1, -1,  0, +1};
bool valid(int x, int y){
        return (bool)(x >= 0 and x < n  and y >= 0 and y < m);
}

void fn(int i, int j){
    grid[i][j] = '.';
    for(int p = 0; p < 8; ++p){
        int _i = i + idir[p];
        int _j = j + jdir[p];
        if(valid(_i, _j) and grid[_i][_j] == '#'){
            fn(_i, _j);
        }

    }
}

void solve(const int case_no){
    
    cin >> n >> m;
    
    for(int i = 0; i < n ; ++i){
        for(int j = 0; j < m; ++j){
            cin >> grid[i][j];
        }
    }

    int res = 0;
    for(int i = 0; i < n ; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j] == '#'){
                fn(i, j);
                ++ res;
            }
        }
    }
    cout << res << endl;

}
