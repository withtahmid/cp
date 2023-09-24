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
    bool multiple_test_case =  true;
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}
void solve(int case_no){
    int n;
    string str1, str2;
    cin >> n >> str1 >> str2;
    vector<bool>row1(n), row2(n);
    fill(all(row1), false);
    fill(all(row2), false);

    if( n > 1 and  str1[0] == 'B' and str1[1] == 'W'){
        if(str2[0] == 'W'){
            cout << "NO" << endl;
            return;
        }
        row1[0] = true;
        row2[0] = true;
    }
    else if( n > 1 and  str2[0] == 'B' and str2[1] == 'W'){
        if(str1[0] == 'W'){
            cout << "NO" << endl;
            return;
        }
        row1[0] = true;
        row2[0] = true;
    }
    if( n > 1 and  str1[n-1] == 'B' and str1[n-2] == 'W'){
        if(str2[n-1] == 'W'){
            cout << "NO" << endl;
            return;
        }
        row1[n-1] = true;
        row2[n-1] = true;
    }
    else if(n > 1 and  str2[n-1] == 'B' and str2[n-2] == 'W'){
        if(str1[n-1] == 'W'){
            cout << "NO" << endl;
            return;
        }
        row1[n-1] = true;
        row2[n-1] = true;
    }
    for(int i = 0; i < n; ++i){
         if(i > 0 and i+1 < n){
            if(str1[i] == 'B' and str1[i-1] == 'W' and str1[i+1] == 'W'){
                if(str2[i] == 'W'){
                    cout << "NO" << endl;
                    return;
                }
                row1[i] = true;
                row2[i] = true;
            }

        }
    }
    debug(row1);
    debug(row2);

    for(int i = 0; i+1 < n; ++i){
        bool flag = true;
        if(str1[i] == 'B' and not row1[i]){
            if(str1[i+1] == 'W' and not row2[i]){
                row1[i] = true;
                row2[i] = true;
            }
            else if(str2[i] == 'W' and not row1[i+1]){
                row1[i] = true;
                row1[i+1] = true;
            }
            else if(str1[i+1] == 'B' and str2[i] == 'B' and not row1[i+1] and not row2[i]){
                row1[i] = true;
                row2[i] = true;
            }
            else{
                flag = false;
            }
        }
        //
        if(str2[i] == 'B' and not row2[i]){
            
           if(str2[i+1] == 'W' and not row1[i]){
                row1[i] = true;
                row2[i] = true;
            }
            else if(str1[i] == 'W' and not row2[i+1]){
                row2[i] = true;
                row2[i+1] = true;
            }
            else if(str2[i+1] == 'B' and str1[i] == 'B' and not row2[i+1] and not row1[i]){
                row1[i] = true;
                row2[i] = true;
            }
            else{
                flag = false;
            }
        }
        
        if(not flag){
            cout << "NO" << endl;
            return;
        }
    }
    debug(row1);
    debug(row2);
    cout << "YES" << endl;
}