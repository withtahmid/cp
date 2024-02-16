/**
 *
 * Author: withtahmid
 * Created: 2024-02-03 18:01:11
 *
 **/
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#ifdef LOCAL 
#include <debug.h>
#else
#define local(...) 
#define debug(...)
#define dbg(...)
#endif
#define pb push_back
#define pf push_front
#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define has(x, y) (x.find(y) != x.end())
#define FF first
#define SS second 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
inline void print(const auto &...a) {((cout << a), ...);}
inline void println(const auto &...a) {print(a..., '\n');}
inline bool read(auto &...a) {return (((cin >> a) ? true : false) && ...);}
inline void read(pair<auto, auto>& p){read(p.first, p.second);}
inline void read(vector<auto>& v) {for(auto& i : v){read(i);}}
void solve(int);
void precompute();
signed main(){
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
    return 0;
}

const int maxn = 62;
const int mod = (1e9 + 7);
const int oo = INT_MAX;
const ll OO = LLONG_MAX;
void precompute(){}
/*************************************/ 
template<class T>
class Grid{
private:
    map<string, pair<int, int>> direction_words = {
        { "L",   { +0, -1 } },    // Left
        { "R",   {  0, +1 } },   // Right
        { "U",   { -1, +0 } },   // Up
        { "D",   { +1, +0 } },    // Down

        { "TL",  { -1, -1 } },   // Top - Left
        { "TR",  { -1, +1 } },   // Top - Right 
        { "BL",  { +1, -1 } },   // Bottom - Left
        { "BR",  { +1, +1 } },   // Bottom - Right

        { "W",   { +0, -1 } },   // West
        { "E",   {  0, +1 } },   // Easr
        { "N",   { -1, +0 } },   // North
        { "S",   { +1, +0 } },

        { "NW",  { -1, -1 } },   // North - West
        { "NE",  { -1, +1 } },   // North - Ease
        { "SW",  { +1, -1 } },   // South - West
        { "SE",  { +1, +1 } }   // South East
    };

    vector<vector<T>>grid;
    int H = 0, W = 0;
    vector<int> x_dir = {  0, -1,  0, +1 };
    vector<int> y_dir = { -1,  0, +1,  0 };
public:
    Grid(const int n){
        this -> H = n; this -> W = n;
        this -> grid.resize(this -> H , vector<T>(this -> W));
    }
    Grid(const int n, const int m){
        this -> H = n; this -> W = m;
        this -> grid.resize(this -> H , vector<T>(this -> W));
    }
    Grid(const int n, const int m, const T x){
        this -> H = n; this -> W = m;
        this -> grid.resize(this -> H, vector<T>(this -> W, x));
    }
    Grid(const vector<vector<T>>& v){
        assert(v.size() > 0  and v[0].size() > 0); 
        this -> H = v.size(), this -> W = v[0].size();
        this -> grid = v;
    }
    void resize(const int n){
        this -> H = n; this -> W = n;
        this -> grid.resize(this -> H , vector<T>(this -> W));
    }
    void resize(const int n, const int m){
        this -> H = n; this -> W = m;
        this -> grid.resize(this -> H , vector<T>(this -> W));
    }
    void resize(const int n, const int m, const T x){
        this -> H = n; this -> W = m;
        this -> grid.resize(this -> H, vector<T>(this -> W, x));
    }
    void resize(const vector<vector<T>>& v){
        assert(v.size() > 0  and v[0].size() > 0); 
        this -> H = v.size(), this -> W = v[0].size();
        this -> grid = v;
    }
    T& at(const int i, const int j){
        return this -> grid[i][j];
    }
    T& at(const pair<int, int> p){
        return this -> grid[p.first][p.second];
    }
    bool inside(const pair<int, int> p){
        return (0 <= p.first and 0 <= p.second and p.first < this -> H and p.second < this -> W);
    }
    bool inside(const int i, const int j){
        return (0 <= i and 0 <= j and i < this -> H and j < this -> W);
    }
    void change_dir(vector<int>x, vector<int>y){
        x_dir = x, y_dir = y;
    }
    void change_dir(vector<string>dir){
        x_dir.clear(); 
        y_dir.clear();
        for(auto& d : dir){for(auto& c : d){c = toupper(c);}
            assert(direction_words.find(d) != direction_words.end());
            auto [x, y] = direction_words[d];
            x_dir.push_back(x), y_dir.push_back(y);
        }
    }
    vector<T>& operator[](const int& i){
        return this -> grid[i];
    }
    Grid<T> transpose(){
        Grid<T> result(this->W, this->H);
        for(int i = 0; i < this->H; ++i) for(int j = 0; j < this -> W; ++j){
            result[j][i] = grid[i][j];
        }
        return result;
    }
    Grid<T> rotate90(){
        Grid<T> result(this->W, this->H);
        for(int i = 0; i < this->H; ++i) for(int j = 0; j < this -> W; ++j){
            result[j][this->H - 1 - i] = this -> grid[i][j];
        }
        return result;
    }
    Grid<T> rotate180(){
        Grid<T> result(this->H, this->W);
        for(int i = 0; i < this->H; ++i) for(int j = 0; j < this -> W; ++j){
            result[this->H - 1 - i][this->W - 1 - j] = this -> grid[i][j];
        }
        return result;
    }
    Grid<T> rotate270(){
        Grid<T> result(this-> W, this-> W);
        for(int i = 0; i < this->H; ++i) for(int j = 0; j < this -> W; ++j){
            result[this->W - 1 - j][i] = this -> grid[i][j];
        }
        return result;
    }
    Grid<T> flipH(){
        Grid<T> result(this-> H, this-> W);
        for(int i = 0; i < this->H; ++i) for(int j = 0; j < this -> W; ++j){
            result[i][ this -> W - 1 - j] = this -> grid[i][j];
        }
        return result;
    }
    Grid<T> flipV(){
        Grid<T> result(this-> H, this-> W);
        for(int i = 0; i < this->H; ++i) for(int j = 0; j < this -> W; ++j){
            result[this -> H - 1 - i][j] = this -> grid[i][j];
        }
        return result;
    }
    vector<pair<int, int>> index_of(T item){
        vector<pair<int, int>>indx;
        for(int i = 0; i < this -> H; ++i)for(int j = 0; j < this -> W; ++j){
            if(this -> grid[i][j] == item){
                indx.push_back(make_pair(i,j));
            }
        }
        return indx;
    }
    pair<int, int> neighbour(const pair<int, int> p, const int d){
        return make_pair(p.first + x_dir[d], p.second + y_dir[d]);
    }
    pair<int, int> neighbour(const pair<int, int> p, string str){
        for(auto& c : str){c = toupper(c);}
        assert(direction_words.find(str) != direction_words.end());
        auto [x, y] = direction_words[str];
        return make_pair(p.first + x, p.second + y);
    }
    pair<int, int> toroidal(pair<int, int> p){
        return make_pair((p.first + this -> H) % this -> H, (p.second + this -> W) % this -> W);
    }
};

const vector<int> x_dir8 = { -1, -1, -1,  0,  0, +1, +1, +1 };
const vector<int> y_dir8 = { -1,  0, +1, -1, +1, -1,  0, +1 };

// default
const vector<int> x_dir4 = {  0, -1,  0, +1 };
const vector<int> y_dir4 = { -1,  0, +1,  0 };

/*************************************/ 

int dp[maxn][maxn][maxn][maxn];

void solve([[maybe_unused]] const int case_no){
    int n;
    read(n);
    Grid<char>grid(n, n);
    for(int i = 0; i < n; ++i){
        read(grid[i]);
    }
    auto players = grid.index_of('P');
    
    memset(dp, -1, sizeof(dp));
    
    queue<pair<pii, pii>>q;
    q.push({{players[0].FF, players[0].SS}, {players[1].FF, players[1].SS}});
    dp[players[0].FF][players[0].SS][players[1].FF][players[1].SS] = 0;
    
    while(not q.empty()){
        auto[x, y] = q.front();
        q.pop();
        int dist = dp[x.FF][x.SS][y.FF][y.SS];
        for(int i = 0; i < 4; ++i){
            auto p1 = grid.neighbour(x, i);
            auto p2 = grid.neighbour(y, i);
            if(not grid.inside(p1) or grid.at(p1) == '#'){
                p1 = x;
            }
            if(not grid.inside(p2) or grid.at(p2) == '#'){
                p2 = y;
            }
            if(p1 == p2){
                println(dist + 1);
                return;
            }
            if(dp[p1.FF][p1.SS][p2.FF][p2.SS] == -1){
                dp[p1.FF][p1.SS][p2.FF][p2.SS] = dist + 1;
                q.push({p1, p2});
            }
        }
    }
    println(-1);
}