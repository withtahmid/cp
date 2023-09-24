/**
 * 
 * Author: withtahmid
 * Created: 16-10-2022 16:24:58
 * 
 * */
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"    
#endif
using namespace std;
#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
#define nl cout<<"\n";
#define ll  long long
#define nn int n; cin>>n
#define lln long long n; cin >> n
#define vi(n) vector<int>v(n)
#define vl(n) vector<long long>v(n)
#define srt(v) sort(v.begin(), v.end())
#define rvs(v) reverse(v.begin(), v.end())
#define ub(v,n) upper_bound(v.begin(), v.end(), n)
#define lb(v,n) lower_bound(v.begin(), v.end(), n)
#define fil(v,n) fill(v.begin(), v.end(),n)
#define acu(v) accumulate(v.begin(), v.end(),0LL)
#define pb push_back
#define sp(n) fixed << setprecision(n)
#define loop(n)  for(int i = 0; i<n; i++)
#define rloop(n) for(int i = n; i>=0; i--)
#define test_case int t, c = 0; cin>>t;/*cin.ignore()*/ while(t--)
template <typename Type> void operator>>(istream& istream, vector<Type>& v){for(auto& i : v) cin>>i; }
template <typename Type> void operator<<(ostream& ostream, vector<Type>& v){for(auto i : v) cout<<i<<" ";}
void file_io()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int main()
{
    fast_io;
    file_io();
    test_case{
        ll n,q;
        cin>>n>>q;
        vector<ll>v(n);
        vector<ll>vmod(n);
        
        vector<ll>v2(q);
        cin >> v;
        cin >> v2;

        vmod[0] = v[0];
        for(ll i = 1; i<n; i++)
        {
            if(v[i]<vmod[i-1]){
                vmod[i] = vmod[i-1];
            }
            else{
                vmod[i] = v[i];
            }
        }
        // cout << vmod;
        // nl;
        for(ll i = 1; i<n; i++)
        {
            v[i] += v[i-1];
        }
        for(ll i = 0; i<q; i++)
        {
            if(v2[i] < vmod[0])
            {
                cout << 0 << " ";
                continue;
            }
            else if(v2[i]>=vmod[vmod.size()-1])
            {
                cout << v[v.size()-1] <<" ";
                continue;
            }
            auto it = ub(vmod, v2[i]);
            if(it == vmod.begin())
            {
                cout <<0;
            }
            else
            {
                cout <<  v[ it - vmod.begin()-1];
            }
             cout << " ";
        }
        nl;

    }
}
