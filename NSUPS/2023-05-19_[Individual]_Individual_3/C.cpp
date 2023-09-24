/**
 * 
 * Author: withtahmid
 * Created: 2023-05-19 10:26:15
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
#define len(v) (int) v.size()
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
void solve(int case_no){
    int x, y;
    cin >> x >> y;
    int a = 1, b = 1;
    while(__gcd(x,y) > 1){
        bool flag = true;
        if(a>b){
            ++b;
            if(y % b == 0){
                y /= b;
                flag = false;
            }else{
                --b;
            }
        }
        else{
            ++a;
            if(x % a == 0){
                x /= a;
                flag = false;
            }else{
                --a;
            }
        }

        if(flag){
            ++a, ++b;
        }
    }
    debug(a);
    debug(b);
    cout << a*b << endl;
}