/**
 * 
 * Author: withtahmid
 * Created: 2023-09-07 20:32:41
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
#define sp(n) setprecision(n)
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
void before_tc(auto);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL
    io();
    time_t Time; time(&Time);cerr << ctime(&Time) << endl;
    auto starttime = chrono::steady_clock::now();
    #endif
    bool multiple_test_case = not true;
    before_tc(1);
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    #ifdef LOCAL
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>
    (chrono::steady_clock::now() - starttime).count() << " millisecond\n";
    #endif
    
}
void before_tc(auto looad){}


class item{
public:
    ll hash_val;
    ll len;
    item(){}
    item(ll x, ll z){
        hash_val = x;
        len = z;
    }
};

const ll MAXN = 1e5 + 10;
const ll p = 7, mod = LONG_MAX;
vector<item>TREE(MAXN * 4);
vector<ll> a,b;

item relation(item a, item b){
    if(a.len != 0LL and b.len != 0LL){
        ll a_hash = a.hash_val;

        ll b_hash =(power(p, a.len) * b.hash_val) % mod;
        ll hash = (a_hash + b_hash) % mod;
        return item(hash, a.len + b.len);
    }
    if(a.len == 0){
        return b;
    }
    return a;  
}
void build(ll indx, ll l, ll r){
    if(l == r){
        TREE[indx] = item(a[l], 1);
        return;
    }
    ll mid = (l + r)/2;
    ll left = indx * 2;
    ll right = indx * 2 + 1;
    build(left, l, mid);
    build(right, mid+1, r);
    TREE[indx] = relation(TREE[left], TREE[right]);
}
item query(ll indx, ll l, ll r, ll range_l, ll range_r){
    if(range_l > range_r){
        return item(0LL,0LL);
    }
    if(l == range_l and r == range_r){
        return TREE[indx];
    }
    ll mid = (l + r) / 2;
    ll left = indx * 2;
    ll right = indx * 2 + 1;
    return relation(
        query(left,l, mid, range_l, min(mid, range_r)),
        query(right, mid + 1, r, max(mid+1, range_l), range_r)
    );
}
void update(ll indx, ll l, ll r, ll pos, ll val){
    if(l == r){
         TREE[indx] = item(val, 1);
        return;
    }
    ll mid = (l + r ) / 2;
    ll left = indx * 2;
    ll right = indx * 2 + 1;
    if(pos <= mid){
        update(left, l, mid, pos, val);
    }
    else{
        update(right, mid+1, r, pos, val);
    }
    TREE[indx] = relation(TREE[left], TREE[right]);

}

void solve(int case_no){
    dbg(-5&1);
}