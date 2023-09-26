/**
 *
 * Author: withtahmid
 * Created: 2023-09-25 20:31:05
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
inline void operator>>(istream& istream, vector<auto>&v){for(auto& i:v){cin>>i;}}
void solve(int);
void before_tc();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init(0);
    bool test_case = true;
    before_tc();
    int tc = 1; if(test_case){cin >> tc;}
    for(int i = 1; i <= tc; ++i){
        solve(i);
    }
    init(1);
}
void before_tc(){}
void solve([[maybe_unused]] const int case_no){
    int n;
    cin >> n;
    vector<set<int>>v(n);
    set<int>univarsal;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        while(x--){
            int in;
            cin >> in;
            v[i].insert(in);
            univarsal.insert(in);
        }
    }
    int res = 0;
    for(auto exclude : univarsal){
        set<int>u;
        for(int i = 0; i < n; ++i){
            if(v[i].contains(exclude)){
                continue;
            }
            for(auto it : v[i]){
                u.insert(it);
            }
        }
        res = max(res, len(u));
    }
    cout << res << endl;
}
