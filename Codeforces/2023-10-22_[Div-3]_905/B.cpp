/**
 *
 * Author: withtahmid
 * Created: 2023-10-22 17:02:32
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
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    map<int, int>mp;
    for(auto c : str){
        ++mp[c - 'a'];
    }
    
    if(k >= n){
        cout << "NO" << endl;
        return;
    }

    int first_balance = 0;
    int single = 0;
    for(auto i : mp){
        if((i.second & 1) and (i.second > 1)){
            ++first_balance;
        }
        if(i.second == 1){
            ++single;
        }
    }
    if(k < (first_balance + single -1)){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}
