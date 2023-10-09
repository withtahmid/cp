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
#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
typedef int_fast64_t ll;

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

double get(int a){
    return a * a;
}
const double eps = 1e-9;


vector <vector <int>> v = {
    { 1, 1, 3 },
    { 1, 2, 2 },
    { 2, 4, 4 },
    { 3, 3, 4 },
    { 1, 1, 1, 2 },
    { 1, 3, 3, 3 },
    { 2, 2, 2, 4 },
    { 3, 4, 4, 4 }
}; 
map<int,int> mp;
ll get_val() {

    ll ans = 0;
    int x;

    x = min(mp[1], mp[4]);
    ans += x;
    mp[1] -= x;
    mp[4] -= x;

    x = min(mp[2], mp[3]);
    ans += x;
    mp[2] -= x;
    mp[3] -= x;

    ll res = 0;

    do
    {
        auto newmap = mp;
        ll temp_ans = 0;
        temp_ans += mp[0];

        for (int i = 0; i < v.size(); ++i) {
           map<int,int> cnt;
           for (int j = 0; j < v[i].size(); ++j){
                cnt[v[i][j]]++;
           }
           // dbg(cnt);
           vector <int> vec;
           for (auto &x: cnt) {
              vec.push_back(newmap[x.first]/x.second);
           }
           ll val = (ll) *min_element(all(vec));
           for (auto &x: cnt) {
                newmap[x.first] -= (val * x.second);                
           }
           temp_ans += val;         
        }
        for (int i = 1; i <= 4; ++i) {
            temp_ans += newmap[i] / 5;
        }

        res = max(res, temp_ans + ans);
        break;
    }
    while(next_permutation(all(v)));
    return res;
}


void solve(const int case_no) {    
    sort(all(v));
   // dbg(v);
    int n;
    cin >> n;
    vector <int> v(n);  
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i] %= 5;    
        mp[v[i]]++;    
    }
    dbg(mp);
    cout << get_val() << endl;
}
