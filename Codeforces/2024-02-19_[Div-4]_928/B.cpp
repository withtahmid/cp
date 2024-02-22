/**
 *
 * Author: withtahmid
 * Created: 2024-02-19 20:29:10
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
#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define has(x, y) (x.find(y) != x.end())
#define dec(x) setprecision(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
inline void print(const auto& a){cout<<a;}
inline void print(const vector<auto>& v){for(auto&i:v){print(i);print(" ");}}
inline void print(const auto &...a) {((print(a)), ...);}
inline void println(const auto &...a) {print(a..., '\n');}
inline bool read(auto& x){return(cin >> x) ? true : false;}
inline bool read(pair<auto, auto>& p){ return (read(p.first) and read(p.second));}
inline bool read(vector<auto>& v) {bool x = true; for(auto&i:v){x&=read(i);} return x;}
inline bool read(auto &...a) {return (((read(a))?true:false)&&...);}
inline string kes(int k){return("Case "+to_string(k)+": ");}
template <class T>inline T scan(){T t;read(t);return t;}
template<class T>
using _set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
void solve(const int& case_no);
void precompute();
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dbg(__init__());
    precompute();
    bool test_case = true;
    int tc = 1; if(test_case){read(tc);}
    for(int i = 1; i <= tc; ++i){
        dbg(__case__(i));
        solve(i);
    }
    dbg(__elapsed__());
}
const int maxn5 = (1 * 1e5) + 69;
const int maxn6 = (1 * 1e6) + 69;
const int mod7 = (1e9 + 7);
const int mod9 = 998244353;
const int oo = INT_MAX;
const ll OO = LLONG_MAX;
void precompute(){}
void brutforce(){}

/******************/ 
template<class T>
class Grid{
private:
    map<string, pair<int, int>> direction_words = {
        { "L",   { +0, -1 } },{ "R",   {  0, +1 } }, 
        { "U",   { -1, +0 } },{ "D",   { +1, +0 } },
        { "TL",  { -1, -1 } },{ "TR",  { -1, +1 } }, 
        { "BL",  { +1, -1 } },{ "BR",  { +1, +1 } },

        { "W",   { +0, -1 } },{ "E",   {  0, +1 } },
        { "N",   { -1, +0 } },{ "S",   { +1, +0 } },
        { "NW",  { -1, -1 } },{ "NE",  { -1, +1 } },
        { "SW",  { +1, -1 } },{ "SE",  { +1, +1 } }
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
    // void dbg(){
    //     for(int i = 0; i < this -> H; ++i){
    //         for(int j = 0; j < this -> W; ++j){
    //             cerr << this -> grid[i][j] <<" ";
    //         }cerr << "\n";
    //     }
    // }
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
        return this -> inside(make_pair(i, j));
    }
    void change_dir(vector<int>x, vector<int>y){
        x_dir = x, y_dir = y;
    }
    void change_dir(vector<string>dir){
        x_dir.clear(); y_dir.clear();
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
    pair<int, int> neighbour(const int i, const int j, const int d){
        return this->neighbour(make_pair(i, j), d);
    }
    pair<int, int> neighbour(const pair<int, int> p, string str){
        for(auto& c : str){c = toupper(c);}
        assert(direction_words.find(str) != direction_words.end());
        auto [x, y] = direction_words[str];
        return make_pair(p.first + x, p.second + y);
    }
    pair<int, int> neighbour(const int i, const int j, string str){
        return this -> neighbour(make_pair(i, j), str);
    }
    pair<int, int> toroidal(const pair<int, int> p){
        return make_pair((p.first + this -> H) % this -> H, (p.second + this -> W) % this -> W);
    }
};

/**
 * Grid<char>grid(n)                        n * n
 * Grid<char>grid(n, m)                     n * m
 * Grid<char>grid(n, m, v)                  n * m -> v
 * Grid<char>grid(vector<vector<char>>())   auto
        OR grid.resize() same as constractor
 *
 *  grid[i][j]      -> value& 
 *  grid.at({i, j}) -> value&
 * 
 * grid.change_dir({"L", "R", "U", "D", "TL"});
 * 
 * grid.inside({i, j}) -> bool
 * 
 * grid.index_of(val) -> vector<pair<i, j>>
 * 
 * grid.transpose() -> Grid
 * grid.rotate90()  -> Grid
 * grid.rotate180() -> Grid
 * grid.rotate270() -> Grid
 * grid.flipH()     -> Grid
 * grid.flipV()     -> Grid
 * 
 * grid.neighbour({i, j}, d)    -> pair<x, y>
 * grid.neighbour({i, j}, "U")  -> pair<x, y>
 * grid.torodial({i, j})        -> pair<x, y>
 * 
    "L", "U", "R", "D", "TL", "TR", "BL", "BR",
    "W", "N", "E", "S", "NW", "NE", "SW", "SE"
*/ 

const vector<int> x_dir8 = { -1, -1, -1,  0,  0, +1, +1, +1 };
const vector<int> y_dir8 = { -1,  0, +1, -1, +1, -1,  0, +1 };

const vector<int> x_dir4 = {  0, -1,  0, +1 };
const vector<int> y_dir4 = { -1,  0, +1,  0 };
const vector<string> dir_arr = {"L", "U", "R", "D", /* "TL", "TR", "BL", "BR" */ };

/*********/ 


void solve([[maybe_unused]] const int& case_no){
    int n;
    read(n);
    Grid<char> grid(n);
    for(int i = 0; i < n; ++i){
        read(grid[i]);
    }
    set<int>st;
    for(int i = 0; i < n; ++i){
        int cnt = 0;
        for(int j = 0; j < n; ++j){
            cnt += (grid[i][j] == '1');
        }
        if(cnt != 0){
            st.insert(cnt);
        }
    }
    println(len(st) == 1 ? "SQUARE" :  "TRIANGLE");
}
