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

const vector<int> x_dir8 = { -1, -1, -1,  0,  0, +1, +1, +1 };
const vector<int> y_dir8 = { -1,  0, +1, -1, +1, -1,  0, +1 };
const vector<int> x_dir4 = {  0, -1,  0, +1 };
const vector<int> y_dir4 = { -1,  0, +1,  0 };
template<class T>
class Grid{
    int n, m;
    vector<vector<T>>grid;
public:
    Grid(int a, int b){
        this -> n = a;
        this -> m = b;
        grid.assign(a, vector<T>(b));
    }
    void input(){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin >> grid[i][j];
            }
        }
    }
    Grid<T> copy(){
        return this;
    }
    Grid<T> rotate(const int d){
        assert(d == 90 or d == 180 or d == 270);
        int x, y;
        if(d == 90){
            Grid<T>tmp(m, n);
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < m; ++j){
                    int x = j, y = n - i - 1;
                    tmp[x][y] = grid[i][j];
                }
            }
            return tmp;
        }
        if(d == 180){
            Grid<T>tmp(n, m);
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < m; ++j){
                    int x = n - i - 1, y = m - j -1;
                    tmp[x][y] = grid[i][j];
                }
            }
            return tmp;
        }
       if(d == 270){
            Grid<T>tmp(m, n);
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < m; ++j){
                    int x = m-j-1, y = i;
                    tmp[x][y] = grid[i][j];
                }
            }
            return tmp;
        }
        assert(true);
        return Grid<T>(1, 1);
    }

    vector<T>& operator[](const int i) {
        assert(0 <= i and i < this -> n);
        return grid[i];
    }

    void dbg(){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cerr << grid[i][j];
            }
            cerr << '\n';
        }
    }
};

void solve(const int case_no){
    int n, m;
    cin >> n >> m;
    Grid<char>grid(n, m);
    grid.input();
    auto x = grid[0][0];
    grid.dbg();
    dbg();
    auto ok = grid.rotate(90);
    ok.dbg();
    dbg();
    ok = grid.rotate(180);
    dbg();
    ok.dbg();
    ok = grid.rotate(270);
    dbg();
    ok.dbg();
}
