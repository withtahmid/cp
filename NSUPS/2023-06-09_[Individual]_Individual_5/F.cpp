/**
 * 
 * Author: withtahmid
 * Created: 2023-06-09 10:45:50
 * 
 **/
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <debug.h> 
#else
#define debug(...)
#define dbg(...)
#endif
#define endl '\n'
#define pb push_back
#define all(v) v.begin(),v.end()
#define sp(n) fixed << setprecision(n)
#define len(v) (int) v.size()
typedef int_fast64_t ll;
typedef vector<int_fast32_t> vi;
typedef long double ld;
template<typename... Args>
void print(Args... args){auto rest = [](const auto& arg)
{cout << arg << " "; };(rest(args), ...);cout << endl;}
template <typename Type>
void operator>>(istream& istream, vector<Type>& v){for(auto& i:v){cin>>i;}}
void solve(int);
void before_tc(){};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    io();
    #endif
    time_t Time; time(&Time);cerr << ctime(&Time) << endl;
    auto starttime = chrono::steady_clock::now();
    bool multiple_test_case = not true;
    before_tc();
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>
    (chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}

ll facto(ll n){
    ll res = 1;
    for(ll i = 1; i <= n; ++i){
        res *= i;
    }
    return res;
}
inline ll ncr(ll n, ll r){
    return facto(n) / ((facto(n-r)) * facto(r));
}

void solve(int case_no){
    dbg(ncr(11, 4));
    dbg(ncr(11, 2));
    dbg(ncr(8,4));
    int n;
    cin >> n;
    vi v(n);
    cin >> v;
    bool same = true;
    for(int i = 0; i < n; ++i){
        if(v[0] != v[i]){
            same = false;
            break; 
        }
    }
    if(same){
        cout << 1 << endl;
        return;
    }

    sort(all(v));
    ll mx = v[n-1];

    auto idx = lower_bound(all(v), mx&1 ? (mx-1)/2 : mx/2) - v.begin();
    ll mn = abs(mx - v[idx]);
    ll temp = idx;
    if(idx != 0){
        if(abs(mx - v[idx-1]) < mn){
            mn = v[idx];
        }
    }
    if(idx != n-1){
        if(abs(mx - v[idx-1]) < mn){
            idx--;
            mn = v[idx];
        }
    }
    
}