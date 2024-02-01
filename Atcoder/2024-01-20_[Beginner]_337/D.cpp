/**
 *
 * Author: withtahmid
 * Created: 2024-01-20 18:01:22
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
#define len(v) ((int) v.size())
#define has(x, y) (x.find(y) != x.end())
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
inline auto _max(const auto f, const auto... r){return max({f, r...});}
inline auto _min(const auto f, const auto... r){return min({f, r...});}
inline void print(const auto &...a) {((cout << a), ...);}
inline void println(const auto &...a) {print(a..., '\n');}
inline bool read(auto &...a) {return (((cin >> a) ? true : false) && ...);}
inline void read(pair<auto, auto>& p){read(p.first, p.second);}
inline void read(vector<auto>& v) {for(auto& i : v){read(i);}}
void solve(int);
void precompute();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dbg(__init__());
    precompute();
    bool test_case = not true;
    int tc = 1; if(test_case){read(tc);}
    for(int i = 1; i <= tc; ++i){
        dbg(__case__(i));
        solve(i);
    }
    dbg(__elapsed__());
}
const int maxn = (1 * 1e5) + 69;
const int mod = (1e9 + 7);
const int oo = INT_MAX;
const ll OO = LLONG_MAX;
void precompute(){}
void solve(const int case_no){
    int h, w, k;
    read(h, w, k);
    vector<string> grid(h);
    read(grid);
    dbg(grid);
    
    vector<vector<ll>>pf_x_h(h, vector<ll>(w));
    vector<vector<ll>>pf_o_h(h, vector<ll>(w));
    
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            if(grid[i][j] == 'x'){
                pf_x_h[i][j] = 1;
            }else if(grid[i][j] == 'o'){
                pf_o_h[i][j] = 1;
            }
        }
    }
    
    auto pf_x_v = pf_x_h, pf_o_v = pf_o_h;
    
    // row
    for(int row = 0; row < h; ++row){
        for(int i = 1; i < w; ++i){
            pf_o_h[row][i] += pf_o_h[row][i - 1];
            pf_x_h[row][i] += pf_x_h[row][i - 1];
        }
    }

    // column
    for(int col = 0; col < w; ++col){
        for(int i = 1; i < h; ++i){
            pf_x_v[i][col] += pf_x_v[i - 1][col];
            pf_o_v[i][col] += pf_o_v[i - 1][col];
        }
    }

    auto hor = [&](int l, int r, int row, const auto& pf) -> ll{
        if(l == 0){
            return pf[row][r];
        }
        return pf[row][r] - pf[row][l - 1];
    };

    auto ver = [&](int l, int r, int col, const auto& pf) -> ll{
        if(l == 0){
            return pf[r][col];
        }
        return pf[r][col] - pf[l - 1][col];
    };

    auto diff = [](int l, int r) -> ll{
        return r - l + 1;
    };

    ll  res = OO;

     // calculate for row
    for(int row = 0; row < h; ++row){
        for(int i = 0; i + k - 1 < w; ++i){
            auto x = hor(i, i + k - 1, row, pf_x_h);
            auto o = hor(i, i + k - 1, row, pf_o_h);
            auto d = diff(i, i + k - 1);
            if(x > 0){
                continue;
            }
            res = min(res, d - o);        }
    }
    dbg(res);

    // calculate for column
    for(int col = 0; col < w; ++col){
        for(int i = 0; i + k - 1 < h; ++i){
            auto x = ver(i, i + k - 1, col, pf_x_v);
            auto o = ver(i, i + k - 1,  col, pf_o_v);
            auto d = diff(i, i + k - 1);
            if(x > 0){
                continue;
            }
            res = min(res, d - o);
        }
    }

    println(res == OO ? -1 : res);
}
