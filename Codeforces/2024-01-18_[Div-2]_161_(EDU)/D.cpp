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
struct PrefixSum{
    vector<long long>fr;
    vector<long long>rv;
    int size;
    PrefixSum(const vector<auto>& v){
        this -> size = v.size();
        const int n = this -> size;
        assert(0 <= n);
        fr.resize(n);
        rv.resize(n);
        this -> fr[0] = v[0], this -> rv[n - 1] = v [n - 1]; 
        for(int i = 1, j = n - 2; i < n; ++i, --j){
            fr[i] = (fr[i - 1] + v[i]);
            rv[j] = (rv[j + 1] +  v[j]);
        }
    }
    long long get_fr(int l, int r){
        assert(l >= 0 and r < this -> size and l <= r);
        if(l == 0){
            return fr[r];
        }
        return fr[r] - fr[l - 1];
    }
    long long get_rv(int l, int r){
        assert(l >= 0 and r < this -> size and l <= r);
        if(r == (this -> size - 1)){
            return rv[l];
        }
        return rv[l] - rv[r + 1];
    }
};

void solve(const int case_no){
    int n;
    read(n);
    vector<int>v(n);
    read(v);
    dbg(v);
    PrefixSum ps(v);
    dbg(ps.get_fr(0, 0), ps.get_rv(0, 0));
}
