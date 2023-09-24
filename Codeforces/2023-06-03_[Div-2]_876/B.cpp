/**
 * 
 * Author: withtahmid
 * Created: 2023-06-03 20:34:10
 * 
 * */
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
void before_tc(){}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    io();
    #endif
    time_t Time; time(&Time);cerr << ctime(&Time) << endl;
    auto starttime = chrono::steady_clock::now();
    bool multiple_test_case = true;
    before_tc();
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>
    (chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}
class bulb{
public:
    int a, b;
    bulb(){};
};
bool comp(bulb x, bulb y){
    if(x.a == y.a){
        return x.b > y.b;
    }
    return x.a < y.a;
}
void solve(int case_no){
    int n;
    cin >> n;
    vector<bulb>v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i].a >> v[i].b;
    }
    sort(all(v), comp);
    ll on = 0;
    ll res = 0;
    map<ll, ll>count;
    for(auto i : v){
        if(on >= i.a){
            continue;
        }
        
        ll off = count[on];
        count[on] = 0;
        on -= off;
        
        res += i.b;
        ++count[i.a];
        ++on;
        dbg(res, on);
    }
    cout << res << endl;
}