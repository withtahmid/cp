/**
 * 
 * Author: withtahmid
 * Created: 2023-07-05 14:58:39
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
void dbgd(deque<int> v){
    for(auto i : v){
        cerr << i <<" ";
    }cerr<< endl;
}
ll strtoi(const string str){
    if(str == ""){
        return 0LL;
    }
    ll sum = 0;
    for(int i = 0; i < len(str); ++i){
        sum = (sum*10) + (str[i] - '0');
    }
    return sum;
}
ll createPartition(string str, int mask){
    deque<int> v;
    for(int i = 0; i < len(str); ++i){
        if((mask >> i)&1){
            v.pb(i+1);
        }
    }
    sort(all(v));
    vector<string>parts;
    for(int i = 0; i < len(str); ++i){
        // dbgd(v);
        if(len(v) == 0){
            parts.pb(str.substr(i, string::npos));
            break;
        }
        string temp = "";
        while(i < v.front()){
            temp += str[i];
            ++i;
        }
        --i;
        v.pop_front();
        parts.pb(temp);

    }
    // dbg(parts);
    ll res = 0;
    for(auto i : parts){
        res += strtoi(i);
        // dbg(res);
    }

    return res;
}
void solve(int case_no){
    string str;
    cin >> str;
    const int N = 1 << (len(str) -1);
    ll res = 0;
    for(int mask = 0; mask < N; ++mask){
       res += createPartition(str, mask);
       
    }
    cout << res << endl;
}