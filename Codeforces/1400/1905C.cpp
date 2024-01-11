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
    int n;
    read(n);
    string str;
    read(str);
    vector<int>ls = { (n-1) };
    for(int i = n - 2; i >= 0; --i){
        if(str[i] >= str[ls.back()]){
            ls.pb(i);
        }
    }
    
    int res = 0;
    int m = len(ls) - 1;
    
    sort(all(ls));

    while(res <= m and str[ls[res]] == str[ls[0]]){
        ++res;
    }
    
    res = m - res  + 1;

    for(int i = 0, j = len(ls) - 1; i < len(ls) / 2; ++i, --j){
        swap(str[ls[i]], str[ls[j]]);
    }

    for(int i = 1; i < n; ++i){
        if(str[i] < str[i -1]){
            println(-1);
            return;
        }
    }

    println(res);
}
