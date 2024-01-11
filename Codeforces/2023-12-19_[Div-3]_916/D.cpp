/**
 *
 * Author: withtahmid
 * Created: 2023-12-19 20:32:24
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
#define mem(x, y) memset(x, y, sizeof(x))
typedef int_fast64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline constexpr auto _max(const auto f, const auto... r){return max({f, r...});}
inline constexpr auto _min(const auto f, const auto... r){return min({f, r...});}
inline void operator>>(istream& istream, vector<auto>&v){for(auto& i:v){cin>>i;}}
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
void precompute(){}
void solve(const int case_no){
    ll n;
    cin >> n;

    vector<ll> a(n), b(n), c(n);
    
    cin >> a;
    cin >> b;
    cin >> c;

    ll idx_1 = 0;
    ll val_1 = 0;
    ll type_1 = 0;

    for(int i = 0; i < n; ++i){
        if(a[i] > val_1){
            val_1 = a[i];
            idx_1 = i;
            type_1 = 0;
        }
        if(b[i] > val_1){
            val_1 = b[i];
            idx_1 = i;
            type_1 = 1;
        }
        if(c[i] > val_1){
            val_1 = c[i];
            idx_1 = i;
            type_1 = 2;
        }
    }
    
    ll idx_2 = 0;
    ll val_2 = 0;
    ll type_2 = 0;
    
    for(int i = 0; i < n; ++i){
        if(i == idx_1) continue;
        if(a[i] > val_2 and (type_1 != 0)){
            val_2 = a[i];
            idx_2 = i;
            type_2 = 0;
        }
        if(b[i] > val_2 and (type_1 != 1)){
            val_2 = b[i];
            idx_2 = i;
            type_2 = 1;
        }
        if(c[i] > val_2 and (type_1 != 2)){
            val_2 = c[i];
            idx_2 = i;
            type_2 = 2;
        }
    }

    ll idx_3 = 0;
    ll val_3 = 0;
    ll type_3 = 0;
    
    for(int i = 0; i < n; ++i){
        if(i == idx_1 || i == idx_2) continue;

        if(a[i] > val_3 and (type_1 != 0) and (type_2 != 0)){
            val_3 = a[i];
            idx_3 = i;
            type_3 = 0;
        }
        if(b[i] > val_3 and (type_1 != 1) and (type_2 != 1)){
            val_3 = b[i];
            idx_3 = i;
            type_3 = 1;
        }
        if(c[i] > val_3 and (type_1 != 2) and (type_2 != 2)){
            val_3 = c[i];
            idx_3 = i;
            type_3 = 2;
        }
    }
    assert(type_1 != type_2 and type_2 != type_3);
    cout << val_1 + val_2 + val_3 << endl;
}
