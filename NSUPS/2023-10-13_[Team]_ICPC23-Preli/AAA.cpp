#include <bits/stdc++.h>
#include<debug.h>
using namespace std;
typedef int_fast64_t ll;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define len(v) (int)v.size()

template <typename T>
inline void operator>>(istream &istream, vector<T> &v){for (T &i : v) cin >> i;}

template <typename T>
inline void operator<<(ostream &ostream, vector<T> &v){for (T &i : v) cout << i << ' '; cout << endl;}


const int MAXN = 1e7 + 5;
int spf[MAXN];

void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;

    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

vector<int> factorize(int n)
{
    vector<int> temp;
    int prev = -1;
    while (n != 1)
    {
        if (prev != spf[n]) {
            temp.emplace_back(spf[n]);
            prev = spf[n];
        }
        n = n / spf[n];
    }    
    return temp;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    for (auto &x: v) cin >> x;
    vector <vector<int>> fact(n);
    for (int i = 0; i < n; ++i) {
        vector <int> temp = factorize(v[i]);
    //     cout << v[i] << " - "; 
    //    for (auto &x: temp) {
    //         cout << x << ' ';            
    //     }
    //     cout << endl;
        fact[i] = temp;
    } 
    int res = 0;
    int cnt = 0;
    int prev = 0;
    map<int,int> mp2;


    for (int i = 0; i < n; ++i) {
        if (v[i] == 1) { 
            if (mp2.size() == k) {
                res = max (res , i - prev + 1);
            }
            continue;   
        }
        for (auto &x: fact[i]) {
            mp2[x]++; 
        }             
       
        if (mp2.size() == k){   
            bool flag = false;     
            for (auto &x: mp2) {
                if (x.second  == ( i - prev + 1) ) {
                    flag = true;
                }
                if(flag) break;
            } 
            if (flag ) continue;

            res = max(res, i - prev + 1);
            // cout << i << ' ' << prev << endl;
        } 
        else if (mp2.size() > k) {
       
            while (mp2.size() > k) {
                for (auto &x: fact[prev]) {
                    mp2[x]--;
                    if (mp2[x] == 0) mp2.erase(x);
                }
                prev++;
            }
            if (mp2.size() == k) {
                res = max(res, i - prev + 1);
                // cout << i << ' ' << prev << endl;
            }
        }       
    }
   

    cout << ((res == 1) ? 0 : res )<< endl;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    sieve();
    init();
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cout << "Case " << tc << ": ";
        solve();
    }
    cout << "ok" << endl;
    return 0;
}



/*
Case 1: 3 ok
Case 2: 7 ok
Case 3: 6 ok
Case 4: 7 ok
Case 5: 0 ok
Case 6: 5 ok
Case 7: 4 ok 
Case 8: 0 ok
Case 9: 0 ok
Case 10: 0 ok
Case 11: 4 ok 
Case 12: 0 ok
Case 13: 3 ok
Case 14: 7 ok 
Case 15: 0 ok 
Case 16: 5 ok 
Case 17: 5 ok
Case 18: 4 ok
ok

Case 1: 3
Case 2: 7
Case 3: 6
Case 4: 7
Case 5: 0
Case 6: 5
Case 7: 4
Case 8: 0
Case 9: 0
Case 10: 0
Case 11: 4
Case 12: 0
Case 13: 3
Case 14: 7
Case 15: 0
Case 16: 5
Case 17: 5
Case 18: 4


*/ 