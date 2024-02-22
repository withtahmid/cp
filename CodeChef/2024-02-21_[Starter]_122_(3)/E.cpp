/**
 *
 * Author: withtahmid
 * Created: 2024-02-21 20:24:23
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

const double EPS = (ld)1e-7;
bool isEqual(ld a, ld b) { return abs(a - b) <= EPS; }
bool isSmaller(ld a, ld b) { return b - a > EPS; }
bool isGreater(ld a, ld b) { return a - b > EPS; }
void solve([[maybe_unused]] const int& case_no){
    int n;
    read(n);
    vector<int>xx(n);
    read(xx);
    vector<ld>v(n);
    for(int i = 0; i < n; ++i){
        v[i] = xx[i];
    }
    const auto dist = [](ld x, ld y) -> ld{
        return abs(x - y) / 2.00;
    };

    const auto checkIt = [&](ld x) -> pair<bool, int>{

        int num_of_group = 0;
        int left_bound = v[0];
        int people_in_left = 1;
        for(int i = 1; i < n; ++i){
            if(isGreater(dist(left_bound, v[i]), x)){
                if(people_in_left < 2){
                    return make_pair(false, -1);
                }
                left_bound = v[i];
                num_of_group ++;
                people_in_left = 1;
            }else{
                people_in_left ++;
            }
        }
        return make_pair(people_in_left >= 2, num_of_group);
    };

    const auto checkIt2 = [&](ld x) -> pair<bool, int>{

        int num_of_group = 0;
        int left_bound = v[len(v)-1];
        int people_in_left = 1;
        for(int i = n - 2; i >= 0; --i){
            if(isGreater(dist(left_bound, v[i]), x)){
                if(people_in_left < 2){
                    return make_pair(false, -1);
                }
                left_bound = v[i];
                num_of_group ++;
                people_in_left = 1;
            }else{
                people_in_left ++;
            }
        }
        return make_pair(people_in_left >= 2, num_of_group);
    };


    
    pair<ld, int>res = checkIt(dist(v.back(), v.front()));

    ld l = 0.0, r = 1e8;
    int iter = 800;
    while(not isGreater(l, r)){
        ld mid = (l + r) / 2.00;
        auto[possible1, toy1] = checkIt(mid);
        auto[possible2, toy2] = checkIt2(mid);
        if(not possible1 and not possible2){
            l = mid + EPS;
        }else{
            r = mid - EPS;
            res = make_pair(mid, min(toy1, toy2));
        }
    }

    cout << setprecision(8) << res.first;
    cout << " " << res.second + 1 <<"\n";
}
