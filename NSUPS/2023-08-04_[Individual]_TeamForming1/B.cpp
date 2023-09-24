/**
 * 
 * Author: withtahmid
 * Created: 2023-08-04 10:16:35
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
void solve(int case_no){
    int n;
    cin >> n;
    // vector<int>v(n);
    vector<ll>pos, neg;
    bool zero = false;
    for(int i = 0; i < n; ++i){
        ll in;
        cin >> in;
        if(in > 0LL){
            pos.pb(in);
        }
        else if(in < 0LL){
            neg.pb(in);
        }
        else{
            zero = true;
        }
    }
    sort(pos.rbegin(), pos.rend());
    sort(neg.begin(), neg.end());
    dbg(pos);
    dbg(neg);
    ll neg_sum = 0;
    for(int i = 1; i < len(neg); i += 2){
        neg_sum += (neg[i] * neg[i-1]);
    }

    ll pos_sum = 0;
    for(int i = 1; i < len(pos); i += 2){
        pos_sum += (pos[i] * pos[i-1]);
    }

    dbg(pos_sum, neg_sum);


    ll lefts = 0;

    if(len(neg)%2 == 1 and len(pos)%2 == 1 and zero){
        lefts = pos.back();
    }
    else if(len(neg)%2 == 1 and len(pos)%2 == 1 and !zero){
        lefts = max(pos[len(pos)-1] + neg[len(neg)-1] , pos[len(pos)-1] * neg[len(neg)-1]); 
    }
    else if(len(neg)%2 == 0 and len(pos)%2 == 1 and zero){
        lefts = pos.back();
    }
    else if(len(neg)%2 == 0 and len(pos)%2 == 1 and !zero){
        lefts = pos.back();
    }
    else if(len(neg)%2 == 1 and len(pos)%2 == 0 and zero){
        lefts = 0;
    }
    else if(len(neg)%2 == 1 and len(pos)%2 == 0 and !zero){
        lefts = neg.back();
    }

    if( len(pos) > 0 and len(pos) % 2 == 0 and pos[len(pos) -1] == 1 ){
        pos_sum += 1;
    }

    cout << pos_sum + neg_sum + lefts << endl;
}