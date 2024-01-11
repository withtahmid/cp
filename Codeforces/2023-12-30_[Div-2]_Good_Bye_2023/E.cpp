/**
 *
 * Author: withtahmid
 * Created: 2023-12-30 20:43:15
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
    bool test_case = not true;
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
        vector<int> a(n);
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll sum = a[0];
        ll oddSum = a[0] % 2;
        ll evenSum = !oddSum;
        cout << sum << " ";
        for (ll i = 1; i < n; ++i) {
            sum += a[i];

            if(a[i]%2!=0)
                oddSum += a[i] % 2;
            else
                evenSum+= !(a[i] % 2);

            ll has = oddSum / 3;
            ll left = oddSum - has;
            cout << sum - has - (left % 2) << " ";
        }

        cout << "\n";


}