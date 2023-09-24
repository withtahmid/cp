/**
 * 
 * Author: withtahmid
 * Created: 2023-07-04 15:15:50
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
int tomakepal(const string str){
    int cnt = 0;
    for(int i = 0, j = len(str)-1; i < len(str)/2; ++i, --j){
        cnt += str[i] != str[j];
    }
    return cnt;
}

int ok(const string str, int y){
    // for(int i = 0; i <= y; ++i){
    //     cerr << str[i];
    // }cerr<<endl;
    int cnt = 0;
    for(int i = 0, j = y; i < y/2; ++i, --j){
        cnt += str[i] != str[j];
    }
    return cnt;
}
void solve(int case_no){
    string str;
    cin >> str;
    int to_make_pal = tomakepal(str);
    dbg(to_make_pal);
    reverse(all(str));
    int res = INT_MAX;
    for(int pivot = 0; pivot < len(str)/2; ++pivot){
        int temp = ok(str, pivot*2) + (len(str) - (pivot*2)-1);
        res = min(temp, res);
        // dbg(temp);
    }
    cout << min(res, to_make_pal) << endl;
}