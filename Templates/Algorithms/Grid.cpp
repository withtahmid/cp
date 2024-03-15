
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
    void dbg(){
        // for(int i = 0; i < this -> H; ++i){
        //     for(int j = 0; j < this -> W; ++j){
        //         cerr << this -> grid[i][j] <<" ";
        //     }cerr << "\n";
        // }
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

