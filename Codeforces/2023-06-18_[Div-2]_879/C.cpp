/**
 * 
 * Author: withtahmid
 * Created: 2023-06-18 14:05:01
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
    bool multiple_test_case = true;
    before_tc();
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>
    (chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}
int run(const string a,const  string b, const int n){
    int cnt = 0;
    for(int i = 0, j = n-1; i < (n/2); ++i, --j){
        if(a[i] == a[j] and b[i] == b[j] and a[i] == b[i]){
            ++cnt;
        }
    }
    return cnt;
}
void solve(int case_no){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int no_rvs = 0;
    forn(n){
        no_rvs += (a[i] != b[i]);
    }

    if(no_rvs == 1 || no_rvs == 0){
        cout << no_rvs << endl;
        return;
    }

    int a_rvs = 0;
    string t = a;
    reverse(all(t));
    no_rvs = run(a, b, n);
    a_rvs = run(t, b, n);
    dbg(no_rvs, a_rvs);

    int my_tern = (n - (min(no_rvs, a_rvs) * 2))*2;
    dbg(my_tern);
    if(no_rvs >= a_rvs){
        -- my_tern;
    }
    cout << my_tern << endl;
    


}