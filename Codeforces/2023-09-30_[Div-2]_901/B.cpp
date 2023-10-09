/**
 *
 * Author: withtahmid
 * Created: 2023-09-30 20:33:54
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
inline constexpr auto max(const auto f, const auto... r){return max({f, r...});}
inline constexpr auto min(const auto f, const auto... r){return min({f, r...});}
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
    dbg(__elapsed__);
}
void precompute(){}

void solve(const int case_no){
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(m);
    cin >> a;
    cin >> b;
    dbg(a, b);
    int max_a = *max_element(all(a));
    int min_a = *min_element(all(a));

    int max_b = *max_element(all(b));
    int min_b = *min_element(all(b));

    if(max_a <= max_b){
        if(k&1){
            cout << accumulate(all(a), 0LL)  + abs(max_b - min_a) << endl;
        }
        else{
            cout << accumulate(all(a), 0LL) << endl;
        }
        return;
    }
    else if(min_a >= max_b){
        if(~k&1){ 
            cout << accumulate(all(a), 0LL)  - abs(max_b - min_a) << endl;
        }
        else{
            cout << accumulate(all(a), 0LL) << endl;
        }
        return;
    }
    else if(k == 1 ){
        cout << accumulate(all(a), 0LL)  +  (min_a < max_b ? abs(max_b - min_a) : 0) << endl;
        return;
    }
    cout << accumulate(all(a), 0LL) << endl;
}
