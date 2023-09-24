/**
 * 
 * Author: withtahmid
 * Created: 2023-08-25 14:54:19
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
typedef int_fast64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline void print(const auto&...args) {((cout << args), ...);}
inline void println(const auto&...args){ print(args..., '\n');}
template <typename T, typename... Rest>
inline constexpr T _max(const T f, const Rest... r){return max({f, r...});}
template <typename T, typename... Rest>
inline constexpr T _min(const T f, const Rest... r){return min({f, r...});}
inline void operator>>(istream& istream, vector<auto>& v){for(auto& i:v){cin>>i;}}
inline void operator>>(istream& istream, deque <auto>& d){for(auto& i:d){cin>>i;}}
void solve(int);
void before_tc();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL
    io();
    time_t Time; time(&Time);cerr << ctime(&Time) << endl;
    auto starttime = chrono::steady_clock::now();
    #endif
    bool multiple_test_case = not true;
    before_tc();
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    #ifdef LOCAL
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>
    (chrono::steady_clock::now() - starttime).count() << " millisecond\n";
    #endif
    
}
void before_tc(){}
void solve(int case_no){
    int n;
    ll c;
    cin >> n >> c;
    deque<ll>v(n);
    cin >> v;
    v.push_front(0LL);
    for(int i = 2; i <= n; ++i){
        v[i] += v[i-1];
    }

    v.push_back(INT_MAX);

    auto rangeSum = [&](int l, int r){
        if(l > r){
            return (ll) 0;
        }
        return (ll)v[r] - v[l-1];
    };



    vector<ll>result(n+10, 0LL);
    int s = 1, e = 1;
    while(s <= n ){
        dbg("range:",s, e);
        if(s <= e){
            // dbg("\tvalid:", s, e);
            ++result[s];
            --result[e+1];
        }

        ll sum =  rangeSum(s, e + 1);
        dbg("sum:", sum);
        if(e + 1 > n){
            ++s;
        }
        else if( sum > c){
            ++s;
        }
        else{
            ++e;
        }
        dbg('\n');
    }
    for(int i = 1; i <= n; ++i){
        result[i] += result[i-1];
    }
    for(int i = 1; i <= n; ++i){
        cout << result[i] << endl;
    }
}