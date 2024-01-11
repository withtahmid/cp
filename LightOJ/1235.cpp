/**
 *
 * Author: withtahmid
 *
 **/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...)
#define dbg(...)
#define init(...)
#endif
#define endl '\n'
#define pb push_back
#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define has(x, y) (x.find(y) != x.end())
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
inline auto _max(const auto f, const auto... r){return max({f, r...});}
inline auto _min(const auto f, const auto... r){return min({f, r...});}
inline void print(const auto &...a) { ((cout << a), ...); }
inline void println(const auto &...a) { print(a..., '\n'); }
inline void read(vector<auto>& v) {for(auto& i : v){ cin >> i;}}
inline void read(deque<auto>& v) {for(auto& i : v){ cin >> i;}}
inline bool read(auto &...a) { return (((cin >> a) ? true : false) && ...);}
void solve(int);
void precompute();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init();
    precompute();
    bool test_case = true;
    int tc = 1; if(test_case){cin >> tc;}
    for(int i = 1; i <= tc; ++i){
        solve(i);
    }
    dbg(__elapsed__());
}
const int maxn = (2 * 1e5) + 69;
const int oo = INT_MAX;
void precompute(){}
void solve(const int case_no){
    ll n, k;
    read(n, k);
    vector<ll>v(n);
    read(v);
    int N = 1 << n;
    set<ll>st;
    for(int mask = 0; mask <= N; ++mask){
        ll sum = 0;
        for(int i = 0; i < 20; ++i){
            if((mask >> i) & 1){
                sum += v[i];
            }
        }
        st.insert(sum);
    }
    print("Case ", case_no, ": ");
    for(int mask = 0; mask <= N; ++mask){
        ll sum = 0;
        for(int i = 0; i < 20; ++i){
            if((mask >> i) & 1){
                sum += v[i];
            }
        }
        if(has(st, abs(k - sum))){
            println("Yes");
            return;
        }
    }
    println("No");
}
