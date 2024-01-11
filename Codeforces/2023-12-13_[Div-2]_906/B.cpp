/**
 *
 * Author: withtahmid
 * Created: 2023-12-13 20:10:36
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
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    bool can_use_t = true;
    for(int i = 1; i < m; ++i){
        if(t[i] == t[i-1]){
            can_use_t = false;
            break;
        }
    }

    if(t.front() != t.back()){
        can_use_t = false;
    }

    char c = t[0];
    set<char>st;
    for(int i = 1; i < n; ++i){
        if(s[i] == s[i-1]){
            st.insert(s[i]);
            if(len(st) > 1){
                cout << "NO" << endl;
                return;
            }
        }
    }

    if(len(st) == 0){
        cout << "YES" << endl;
        return;
    }

    if(not can_use_t){
        cout << "NO" << endl;
    }
    else{
        cout << (t[0] != *st.begin() ? "YES" : "NO") << endl;
    }
}
