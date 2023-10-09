/**
 *
 * Author: withtahmid
 * Created: 2023-10-09 20:32:55
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

const ld eps = 1e-9;

void solve(const int case_no){
    
    pii o, p, a, b;
    
    o.first = o.second = 0;
    
    cin >> p.first >> p.second;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;

    auto square = [](int x){
        return (int) (x * x);
    };

    auto dist = [square](pii x, pii y){
        ld res = sqrtl(
                square(x.first - y.first) +
                square(x.second - y.second)
            );
        return res;
    };

    pii close_to_s = (dist(o, a) > dist(o, b) ? b : a);

    pii close_to_e = (dist(p, a) > dist(p, b) ? b : a);

    ld res = max(dist(o, close_to_s), dist(p, close_to_e));

    if(close_to_s != close_to_e){
        res = max(res, dist(a, b) / 2.00);
    }

    cout << setprecision(12) << res << endl;

}
