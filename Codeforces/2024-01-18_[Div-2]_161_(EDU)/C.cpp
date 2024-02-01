/**
 *
 * Author: withtahmid
 * Created: 2024-01-18 20:31:47
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
#define len(v) ((int) v.size())
#define has(x, y) (x.find(y) != x.end())
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
inline auto _max(const auto f, const auto... r){return max({f, r...});}
inline auto _min(const auto f, const auto... r){return min({f, r...});}
inline void print(const auto &...a) {((cout << a), ...);}
inline void println(const auto &...a) {print(a..., '\n');}
inline bool read(auto &...a) {return (((cin >> a) ? true : false) && ...);}
inline void read(pair<auto, auto>& p){read(p.first, p.second);}
inline void read(vector<auto>& v) {for(auto& i : v){read(i);}}
void solve(int);
void precompute();
int main(){
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
const int maxn = (1 * 1e5) + 69;
const int mod = (1e9 + 7);
const int oo = INT_MAX;
const ll OO = LLONG_MAX;
void precompute(){}
void solve(const int case_no){
    int n;
    read(n);
    vector<ll>v(n);
    read(v);
    deque<ll>to_right(n), to_left(n),right_cnt(n),left_cnt(n);
    to_right[1] = abs(v[0] - v[1]);
    to_left[n - 2] = abs(v[n - 1] - v[n - 2]);
    right_cnt[0] = 1, left_cnt[n - 1] = 1;
    for(int i = 1; i + 1 < n; ++i){
        if(abs(v[i + 1] - v[i]) < abs(v[i] - v[i - 1])){
            to_right[i + 1] = abs(v[i + 1] - v[i]);
            right_cnt[i] = 1;
        }else{
            to_left[i - 1] = abs(v[i - 1] - v[i]);
            left_cnt[i] = 1;
        }
    }
    for(int i  = 1; i < n; ++i){
        to_right[i] += to_right[i - 1];
        right_cnt[i] += right_cnt[i - 1];
    }
    for(int i = n - 2; i > -1; --i){
        to_left[i] += to_left[i + 1];
        left_cnt[i] += left_cnt[i + 1];
    }
    left_cnt.push_back(0);
    right_cnt.push_front(0);
    int q;
    read(q);
    while(q--){
        int l, r;
        read(l, r);
        if(l < r){
            ll tot = abs(v[r - 1] - v[l - 1]);
            tot -= (to_right[r - 1] - to_right[l - 1]);
            println(tot + (right_cnt[r - 1] - right_cnt[l - 1]));
        }else{
            ll tot = abs(v[r - 1] - v[l - 1]);
            tot -= to_left[r - 1] - to_left[l - 1];
            println(tot + (left_cnt[r] - left_cnt[l]));
        }
    }
}
