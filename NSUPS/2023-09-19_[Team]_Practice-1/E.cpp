/**
 *
 * Author: withtahmid
 * Created: 2023-09-19 12:53:36
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
#define rall(v) v.rend(), v.rbegin()
#define sp(n) setprecision(n)
#define len(v) ((int) v.size())
#define mem(x, y) memset(x, y, sizeof(x))
typedef int_fast64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T, typename... Rest>
inline constexpr T _max(const T f, const Rest... r){return max({f, r...});}
template <typename T, typename... Rest>
inline constexpr T _min(const T f, const Rest... r){return min({f, r...});}
inline void operator>>(istream& istream, vector<auto>& v){for(auto& i:v){cin>>i;}}
inline void operator>>(istream& istream, deque <auto>& d){for(auto& i:d){cin>>i;}}
inline void print(const auto&...args) {((cout << args), ...);}
inline void println(const auto&...args){print(args..., '\n');}
inline void print(vector<auto>& v){for(auto& i:v){cout << i << ' ';}cout << endl;}
inline void print(vector<auto>& v, char sep){for(auto& i:v){cout << i << sep;}cout << endl;}
void solve(int);
void before_testcase();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL
    io();
    time_t Time; time(&Time);cerr << ctime(&Time) << endl;
    auto starttime = chrono::steady_clock::now();
    #endif
    bool multiple_test_case = true;
    before_testcase();
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    #ifdef LOCAL
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>
    (chrono::steady_clock::now() - starttime).count() << " millisecond\n";
    #endif

}
void before_testcase(){}
class item{
public:
    ll sum;
    ll min;
    item(){}
    item(ll x, ll z){
        sum = x;
        min = z;
    }
};
const ll MAXN = 200000 + 10;
vector<item>TREE(MAXN * 4);
vector<ll> v;
item merge_tree(item a, item b){
    return item(
        a.sum + b.sum,
        min(a.min, b.min)
        );
}
void build(ll indx, ll l, ll r){
    if(l == r){
        TREE[indx] = item(v[l], v[l]);
        return;
    }
    ll mid = (l + r)/2;
    ll left = indx * 2;
    ll right = indx * 2 + 1;
    build(left, l, mid);
    build(right, mid+1, r);
    TREE[indx] = merge_tree(TREE[left], TREE[right]);
}
item query(ll indx, ll l, ll r, ll range_l, ll range_r){
    if(range_l > range_r){
        return item(0, LLONG_MAX);
    }
    if(l == range_l and r == range_r){
        return TREE[indx];
    }
    ll mid = (l + r) / 2;
    ll left = indx * 2;
    ll right = indx * 2 + 1;
    return merge_tree(
        query(left,l, mid, range_l, min(mid, range_r)),
        query(right, mid + 1, r, max(mid+1, range_l), range_r)
    );
}
void update(ll indx, ll l, ll r, ll pos, ll val){
    if(l == r){
         TREE[indx] = item(val, val);
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
    TREE[indx] = merge_tree(TREE[left], TREE[right]);

}

void solve(int case_no){
    ll n, q;
    cin >> n >> q;
    v.resize(n);
    cin >> v;
    build(1, 0, n-1);
    while(q--){
        int x, l, r;
        cin >> x >> l >> r;
        if(x != 1){
            item res = query(1, 0, n-1, l-1, r-1);
            cout << res.sum - res.min << endl;
        }
        else{
            update(1, 0, n-1, l-1, r);
        }
    }
}