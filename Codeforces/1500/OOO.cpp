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
inline bool read(auto &...a) { return (((cin >> a) ? true : false) && ...);}
inline void read(pair<auto, auto>& p){read(p.first, p.second);}
inline void read(vector<auto>& v) {for(auto& i : v){read(i);}}
inline void read(deque<auto>& v) {for(auto& i : v){read(i);}}
void solve(int);
void precompute();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init();
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
// const int mod = 998244353;
const int oo = INT_MAX;
const ll OO = LLONG_MAX;
void precompute(){}
const int c=100005, mod=998244353;
long long n, t[c], val[c], ans, po[c];
void solve(const int case_no){
    po[0]=1;
    for (int i=1; i<c; i++) {
        po[i]=2*po[i-1]%mod;
    }
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        long long ert=0;
        for (int j=i; j<=n; j+=i) {
            ert=max(ert, t[j]);
        }
        val[i]=ert;
    }
    sort(val+1, val+n+1);
    for (int i=1; i<=n; i++) {
        ans+=po[i-1]*val[i]%mod;
    }
    ans%=mod;
    cout << ans << "\n";
    ans=0;
}
