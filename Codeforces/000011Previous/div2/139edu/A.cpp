/**
 * 
 * Author: withtahmid
 * Created: 12-12-2022
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
void solve(int case_no){
    int n;
    cin >> n;
    int n_ = n;
    int result = 0;
    int it = 0;
    while(n>0){
        if(n<10){
            result += n%10;
            break;
        }
        result += 10;
        n /= 10;
        --result;
    }
    debug(result);
    cout << result<< endl;
}