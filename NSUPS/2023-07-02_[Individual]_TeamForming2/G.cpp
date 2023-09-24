/**
 * 
 * Author: withtahmid
 * Created: 2023-07-02 15:02:57
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
#define vec vector
#define forn(n) for(int i = 0; i < n; ++i)
typedef int_fast64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline bool in(auto&...args) { return (((cin >> args) ? true : false) && ...);}
inline void in(vector<auto>&v){for(auto&i:v){in(i);}}
inline void print(const auto&...args) {((cout << args), ...);}
inline void println(const auto&...args){ print(args..., '\n');}
template <typename T, typename... Rest>
inline constexpr T maxx(const T f, const Rest... r){return max({f, r...});}
template <typename T, typename... Rest>
inline constexpr T minn(const T f, const Rest... r){return min({f, r...});}
inline void operator>>(istream& istream, vector<auto>& v){for(auto& i:v){cin>>i;}}
void solve(int);
void before_tc(){}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL
    io();
    #endif
    time_t Time; time(&Time);cerr << ctime(&Time) << endl;
    auto starttime = chrono::steady_clock::now();
    bool multiple_test_case = true;
    before_tc();
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>
    (chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}

class item{
public:
    int max_num;
    int occurance;
    item(){}
    item(int x, int y){
        max_num = x;
        occurance = y;
    }
};
const ll MAXN = 1e5 +10;
const ll p = 7, mod = LONG_MAX;
vector<item>TREE(MAXN * 4);
vector<int> ar;
item relation_tree(item a, item b){
    if(a.max_num == b.max_num){
        return item(a.max_num, a.occurance + b.occurance);
    }
    if(a.max_num > b.max_num){
        return a;
    }
    return b;
   
}
void build(int indx, int l, int r){
    if(l == r){
        TREE[indx] = item(ar[l], 1);
        return;
    }
    int mid = (l + r)/2;
    int left = indx * 2;
    int right = indx * 2 + 1;
    build(left, l, mid);
    build(right, mid+1, r);
    TREE[indx] = relation_tree(TREE[left], TREE[right]);
}
item query(int indx, int l, int r, int range_l, int range_r){
    if(range_l > range_r){
        return item(-1e6, 0);
    }
    if(l == range_l and r == range_r){
        return TREE[indx];
    }
    int mid = (l + r) / 2;
    int left = indx * 2;
    int right = indx * 2 + 1;
    return relation_tree(
        query(left,l, mid, range_l, min(mid, range_r)),
        query(right, mid + 1, r, max(mid+1, range_l), range_r)
    );
}
void update(int indx, int l, int r, int pos, int val){
    if(l == r){
         TREE[indx] = item(val, 1);
        return;
    }
    int mid = (l + r ) / 2;
    int left = indx * 2;
    int right = indx * 2 + 1;
    if(pos <= mid){
        update(left, l, mid, pos, val);
    }
    else{
        update(right, mid+1, r, pos, val);
    }
    TREE[indx] = relation_tree(TREE[left], TREE[right]);

}
void solve(int case_no){
    int n, q;
    cin >> n >> q;
    ar.clear();
    for(int i = 0; i < n; ++i){
        int in;
        cin >> in;
        ar.pb(in);
    }
    cout << "Case " << case_no <<":\n"; 
    build(1, 0, n-1);
    while(q--){
        int l ,r;
        cin >> l >> r;
        item res = query(1, 0, n-1, l, r);
        cout << res.occurance << endl;
    }
}