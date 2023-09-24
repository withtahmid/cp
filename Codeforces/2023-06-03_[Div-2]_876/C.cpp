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

void solve(int case_no){
    int n;
    cin >> n;
    vi v(n);
    cin >> v;
    if(v[n-1] == 1){
        cout << "NO" << endl;
        return;
    }
    cout <<"YES\n";
    reverse(all(v));
    dbg(v);
    vi str;
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(v[i] == 1){
            ++cnt;
        }
        else{
            str.pb(cnt);
            if(cnt != 0){
                str.pb(0);
            }
            cnt = 0;
        }
    }
    if(cnt != 0){
        str.pb(cnt);
    }
    dbg(str);
    reverse(all(str));
    vi tmp;
    for(int i = 0; i < len(str); ++i){
        if(str[i] != 0){
            tmp.pb(str[i++]);
            continue;
        }
        tmp.pb(str[i]);
    }
    reverse(all(tmp));
    dbg(tmp);
    for(int i = 0; i < len(tmp); ++i){
        if(tmp[i] != 0){
            for(int j = 0; j < tmp[i]; ++j){
                cout <<"0 ";
            }
        }
        cout << tmp[i] <<" ";
    }
    cout << endl;

}