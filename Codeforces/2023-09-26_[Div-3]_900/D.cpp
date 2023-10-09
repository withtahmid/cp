/**
 *
 * Author: withtahmid
 * Created: 2023-09-26 20:32:59
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
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    vi l(k), r(k);
    cin >> l;
    cin >> r;
    dbg(l, r);
    int q;
    cin >> q;
    
    auto doit = [&](int l, int r){
        for(int i = l, j = r; i <= j; ++i, --j){
            swap(str[i], str[j]);
        }
    };
    set<pii>st;
    while(q--){
        int x;
        cin >> x;
        auto i = lower_bound(all(r), x) - r.begin();
        dbg(case_no, i);
        int a = min(x, l[i] + r[i] - x) - 1;
        int b = max(x, l[i] + r[i] - x) - 1;
        doit(a, b);
        st.insert({min(a. b), max(a. b)});
    }
    for(auto i : st){
        doit(i.first)
    }
    dbg(str);
    cout << str << endl;
}