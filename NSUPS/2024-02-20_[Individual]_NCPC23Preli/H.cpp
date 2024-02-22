/**
 *
 * Author: withtahmid
 * Created: 2024-02-20 16:58:09
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
    cin.ignore();
    for(int i = 1; i <= tc; ++i){
        dbg(__case__(i));
        solve(i);
    }
    dbg(__elapsed__());
}
const int maxn5 = (1 * 1e5) + 69;
const int maxn6 = (1 * 1e6) + 69;
const int mod = (1e9 + 7); //998244353
const int oo = ((1ULL << 31) - 1);
const  ll OO = ((1ULL << 63) - 1);
void precompute(){}
void brutforce(){}

void solve([[maybe_unused]] const int& case_no){
    
    string s;
    getline(cin, s);
    dbg(s);

    const map<string, int> dayname = {

        {"Sun", 0}, {"Mon", 1}, {"Tue", 2},
        {"Wed", 3}, {"Thu", 4}, {"Fri", 5},  
        {"Sat", 6}

    };

    const map<int, int> dayCnt = {
        {1, 31},    {2, 28},    {3, 31},    {4, 30},
        {5, 31},    {6, 30},    {7, 31},    {8, 31},
        {9, 30},    {10, 31},   {11, 30},   {12, 31}
    };

    auto leapYear =[](int y) -> bool{
       bool isLeapYear = false;
       if (y % 4 == 0) {
          if (y % 100 == 0) {
             if (y % 400 == 0) {
                isLeapYear = true;
             }
          } 
          else isLeapYear = true;
       }
       return isLeapYear;
    };

    int day = stoi(s.substr(0, 2));
    int month = stoi(s.substr(3, 2));
    int year = stoi(s.substr(6, 4));
    int numOfday = dayCnt[month];
    if(month == 2 and leapYear(year)){
        numOfday ++;
    }

    int tempday = day;
    auto fday = dayname[s.substr(11, 3)];
    while(tempday > 1){
        tempday--;
        fday--;
        fday = (fday + 7) % 7;
    }
    
    vector<vector<int>>grid(5, vector<int>(7, -1));
    dbg(fday, tempday);
    for(int i = 0; i < 5; i++){
        for(int j = fday; j < 7 and tempday <= numOfday; j++){
            grid[i][j] = tempday++;
        }
        fday = 0;
    }

    int ind = 0;
    
    while(tempday <= numOfday){
        grid[0][ ind++ ]= tempday++;
    }

    dbg(grid);
    println("|---------------------------|");
    println("|Sun|Mon|Tue|Wed|Thu|Fri|Sat|");
    println("|---------------------------|");
    for(int i = 0; i < 5; i ++){
        for(int j = 0; j < 7; ++j){
            print("| ");
            if(grid[i][j] == -1){
                print("- ");
                continue;
            }
            if(grid[i][j] < 10){
                print(" ");
            }
            print(grid[i][j]);
        }
        println("|");
        println("|---------------------------|");
    }
    println();
}
