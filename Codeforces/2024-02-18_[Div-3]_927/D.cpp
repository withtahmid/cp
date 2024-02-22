/**
 *
 * Author: withtahmid
 * Created: 2024-02-18 18:02:51
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
void solve([[maybe_unused]] const int& case_no){
    int n = scan<int>();
    char trump = scan<char>();
    map<char, vector<int>>mp;
    for(int i = 0; i < 2 * n; ++i){
        string card = scan<string>();
        mp[card[1]].push_back(card[0] - '0');
    }
    for(auto& [c, v] : mp){
        sort(all(v), greater<int>());
    }
    vector<string> res;
    int odd = 0;
    vector<string>lefts;
    dbg(mp);
    for(auto& [c, v] : mp){
        if(c == trump){
            continue;
        }
        for(int i = len(v) - 1; i > 0; i -= 2){
            res.push_back(string(1, char (v[i] + '0')) + string(1, c) + " " + string(1, char (v[i - 1] + '0')) + string(1, c));
            v.pop_back();
            v.pop_back();
        }
        if(len(v) & 1){
            lefts.push_back(string(1, char(v.front() + '0')) + string(1, (char) c));
        }
        
    }
    dbg(res, lefts, mp[trump]);
    auto& v = mp[trump];
    while(len(v) and len(lefts)){
        res.push_back(lefts.back() + " " + string(1, char (v.back() + '0')) + string(1, trump));
        lefts.pop_back();
        v.pop_back();    
    }
    dbg(res, lefts, mp[trump]);
    if((len(v) & 1 ) or len(lefts)){
        return println("IMPOSSIBLE");
    }

    for(int i = 0; i < len(v); i += 2){
        res.push_back(string(1, char (v[i + 1] + '0')) + string(1, trump) + " " + string(1, char (v[i] + '0')) + string(1, trump));
    }

    for(auto& i : res){
        println(i);
    }
}
