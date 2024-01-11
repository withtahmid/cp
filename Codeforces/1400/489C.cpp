/**
 *
 * Author: withtahmid
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
    int m, s;
    cin >> m >> s;
    if( ((9 * m) < s) or (s == 0 and m > 1)){
        cout << "-1 -1" << endl;
        return;
    }

    auto print = [](vector<int>x){
        for(auto i : x) cout << i;
    };

    if(s == 1){
        vector<int>res(m);
        res[0] = 1;
        print(res);
        cout << " ";
        print(res);
        return;
    }
    
    
    vector<int>big(m, 0);

    int left = s;
    int i = 0;
    while(left >= 0){
        if(left <= 9){
            big[i] = left;
            break;
        }
        left -= 9;
        big[i] = 9;
        ++i;
    }

    auto small = big;
    reverse(all(small));
    for(int i = 0; i < len(small); ++i){
        if(small[i] > 0){
            small[i] -= 1;
            small[0] += 1;
            break;
        }
    }
    print(small);
    cout << " ";
    print(big);
}   
