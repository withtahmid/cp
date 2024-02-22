/**
 *
 * Author: withtahmid
 * Created: 2024-02-20 16:58:09
 *
 **/
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#ifdef LOCAL 
#include <debug.h>
#else
#define local(...) 
#define debug(...)
#define dbg(...)
#endif
#define pb push_back
#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define has(x, y) (x.find(y) != x.end())
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
inline void print(const auto& a){cout<<a;}
inline void print(const vector<auto>& v){for(auto&i:v){print(i);print(" ");}}
inline void print(const auto &...a) {((print(a)), ...);}
inline void println(const auto &...a) {print(a..., '\n');}
inline bool read(auto& x){return(cin >> x) ? true : false;}
inline bool read(pair<auto, auto>& p){ return (read(p.first) and read(p.second));}
inline bool read(vector<auto>& v) {bool x = true; for(auto&i:v){x&=read(i);} return x;}
inline bool read(auto &...a) {return (((read(a))?true:false)&&...);}
inline string kes(int k){return("Case "+to_string(k)+": ");}
template <class T>inline T scan(){T t;read(t);return t;}
template<class T>
using _set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
void solve(const int& case_no);
void precompute();
signed main(){
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
const int maxn5 = (1 * 1e5) + 69;
const int maxn6 = (1 * 1e6) + 69;
const int mod = (1e9 + 7); //998244353
const int oo = ((1ULL << 31) - 1);
const  ll OO = ((1ULL << 63) - 1);
void precompute(){}
void brutforce(){}

const int N = 5e5;

vector<int> adj[N+1];
vector<ll> val(N+1), ans(N+1);
stack<pair<ll, ll>> st;
void dfs(ll v, ll p, ll depth){
auto [x, y] = st.top();
    // if(val[v]>=x){

    // }
    // else{

    // }
    dbg(v, depth,st.top());
    ll cur = val[v];
    if(x>=val[v]){
        ll middle = (depth - y)-1;
        cur+=val[v]*middle;
        cur+=x*y;
    }
    else{
        cur = val[v]*depth;
    }
    ans[v]=cur;
    if(val[v]>=x){
        st.push({val[v], depth});
    }
    else{
        st.push(st.top());
    }
    for(auto c: adj[v]){
        if(c^p){
        dfs(c, v, depth+1);
        }
    }
    st.pop();
}
void solve([[maybe_unused]] const int& case_no){

    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
    cin>>val[i];
    }
    for(int i =1; i<n; i++){
    int x, y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
    }
    st.push({0, 0});
    dfs(1, 0, 1);

    for(int i = 1; i<=n; i++){
    cout << ans[i] << " ";
    adj[i].clear();
    val[i] = ans[i] = 0;
    }
    cout << "\n";
    // st.clear();
}
