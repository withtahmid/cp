/**
 *
 * Author: withtahmid
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
    bool test_case = not true;
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
int n, k;
int fn(const string& str){
    
}
void solve(const int case_no){
    read(n, k);
    string str;
    read(str);
    vector<int>a(n), b(n);
    for(int i = 0; i < n; ++i){
        if(str[i] == 'a'){
            a[i] = 1, b[i] = 0;
        }else{
            a[i] = 0, b[i] = 1;
        }
    }
    for(int i = 1; i < n; ++i){
        a[i] += a[i - 1], b[i] += b[i - 1];
    }
    int res = 1;
    for(int i = 0; i < n; ++i){
        const auto& pf = str[i] == 'a' ? b : a;
        int l = i, r = n - 1;
        int idx_r  = l;
        while(l <= r){
            int mid = (l + r) / 2;
            if(pf[mid] <= (pf[i] + k)){
                l = mid + 1;
                idx_r = mid;
            }else{
                r = mid - 1; 
            }
        }
        int baki = (pf[i] + k) - pf[idx_r];
        if(baki > 0){
            l = 0, r = i;
            int idx_l = i;
            while(l <= r){
                int mid = (l + r) / 2;
                if(pf[i] - pf[mid] < baki){
                    r = mid - 1;
                    idx_l = mid;
                }else{
                    l = mid + 1;
                }
            }
            res = max(res, idx_r - idx_l + 1);
        }else{
            res = max(res, idx_r - i + 1);
        }
    }
    println(res);
}
