/**
 * 
 * Author: withtahmid
 * Created: 2023-08-19 16:27:46
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
#define sp(n) fixed << setprecision(n)
#define len(v) ((int) v.size())
#define vec vector
#define forn(n) for(int i = 0; i < n; ++i)
typedef int_fast64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline bool in(auto&...args) { return (((cin >> args) ? true : false) && ...);}
inline void in(vector<auto>&v){for(auto&i:v){in(i);}}
inline void print(const auto&...args) {((cout << args), ...);}
inline void println(const auto&...args){ print(args..., '\n');}
template <typename T, typename... Rest>
inline constexpr T maxx(const T f, const Rest... r){return max({f, r...});}
template <typename T, typename... Rest>
inline constexpr T minn(const T f, const Rest... r){return min({f, r...});}
inline void operator>>(istream& istream, vector<auto>& v){for(auto& i:v){cin>>i;}}
void solve(int);
void before_tc(){}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL
    io();
    #endif
    time_t Time; time(&Time);cerr << ctime(&Time) << endl;
    auto starttime = chrono::steady_clock::now();
    bool multiple_test_case = not true;
    before_tc();
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>
    (chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}

const ld EPS = (ld) 1e-9;
bool isEqual(ld a, ld b){
    return abs(a - b) <= EPS;
}

bool isSmaller(ld a, ld b){
    return b - a > EPS;
}

bool isGreater(ld a, ld b){
    return a - b > EPS;
}

void solve(int case_no){
    int r, R, h;
    cin >> r >> R >> h;
    auto fits = [&](ld x){
        ld d = 2.00 * x;
        if(d > h){
            return (ld)-1.00;
        }
        ld reduces = (((ld)(R-r) * x) / (ld)h) * 2.00;
        ld available_gap = ( 2 * R )  - reduces;
        return available_gap;
    };

    ld low = 0.0, high = min(h, R);
    ld res = 0.0;
    for(int it = 0; it < 100; ++it){
        ld mid = (low + high) / 2.0;
        ld available_gap = fits(mid);
        if( available_gap -  (2*mid) >= EPS){
            low = mid + EPS;
            res = mid;
        }
        else{
            high = mid - EPS;
        }

    }
    cout << sp(9) << res << endl;
}