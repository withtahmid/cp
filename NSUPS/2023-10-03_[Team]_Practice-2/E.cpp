/**
 *
 * Author: withtahmid
 * Created: 2023-10-03 12:25:52
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
// inline constexpr auto max(const auto f, const auto... r){return max({f, r...});}
// inline constexpr auto min(const auto f, const auto... r){return min({f, r...});}
// inline void operator>>(istream& istream, vector<auto>&v){for(auto& i:v){cin>>i;}}
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
    string str;
    cin >> str;
    const int n = len(str);
    set<int>eye, mouth;
    for(int i = 0; i < n; ++i){
        if(str[i] == '^'){
            eye.insert(i);
        }
        else{
            mouth.insert(i);
        }
    }
    
    int res = 0;

    while(len(eye) >= 2 and len(mouth)){
        int start = *eye.begin();
        set<int>::iterator mid_lb = mouth.lower_bound(start);
    
        if(mid_lb == mouth.end()){
            break;
        }
    
        int end = *eye.rbegin();
        if(end < *mid_lb){
            break;
        }
    
        eye.erase(eye.begin());
        eye.erase(*eye.rbegin());
        mouth.erase(mid_lb);
        ++res;
    }
    cout << "Case " << case_no<<": " << res << endl;
}
