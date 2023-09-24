/**
 * 
 * Author: withtahmid
 * Created: 11-02-2023
 * 
 * */
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <debug.h> 
#else
#define debug(...) 
#endif
#define endl '\n'
#define pb push_back
#define all(v) v.begin(),v.end()
#define sp(n) fixed << setprecision(n)
#define sizeof(v) (int) v.size()
typedef int_fast64_t ll;
typedef vector<int_fast32_t> vi;
template <typename Type>
void operator>>(istream& istream, vector<Type>& v){for(auto& i:v){cin>>i;}}
void solve(int);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    io();
    #endif
    time_t Time; time(&Time);cerr << ctime(&Time) << endl;
    auto starttime = chrono::steady_clock::now();
    bool multiple_test_case = true;
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}
int calculate_dif(int n){
    int N = n;
    int mx =INT_MIN, mn = INT_MAX;
    while(n){
        int dig = n%10;
        n /= 10;
        mx = max(mx, dig);
        mn = min(mn, dig);
    }
    return abs(mx-mn);

}
void solve(int case_no){
    int l, r;
    cin >> l >> r;
    int max_dif = -1, res;
    for(int i = l; i <= r; ++i){
        int dif = calculate_dif(i);
        if(max_dif < dif){
            max_dif = dif;
            res = i;
        }
        if(dif == 9){
            break;
        }
    }
    cout << res << endl;
}
