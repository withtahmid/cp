/**
 * 
 * Author: withtahmid
 * Created: 03-08-2022
 * 
 * */
#include<bits/stdc++.h>
using namespace std;
#define boostIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n";
#define nl cout<<"\n"
#define ll  long long
#define nn int n; cin>>n
#define lln long long n; cin >> n
#define vi(n) vector<int>v(n)
#define vl(n) vector<long long>v(n)
#define srt(v) sort(v.begin(), v.end())
#define reverse(v) reverse(v.begin(), v.end())
#define ub(v,n) upper_bound(v.begin(), v.end(), n)
#define lb(v,n) lower_bound(v.begin(), v.end(), n)
#define pb push_back
#define test_case int t, c = 0; cin>>t;/*cin.ignore()*/ while(t--)
#define debug cout<<"I am here\n";
template <typename Type> void operator>>(istream& istream, vector<Type>& v){for(auto& i : v) cin>>i; }
template <typename Type> void operator<<(ostream& ostream, vector<Type>& v){for(auto i : v) cout<<i<<" ";}
int main()
{
    boostIO
    test_case{
       nn;
       vl(n);
       cin>>v;
       bool yes = true;
       long long previous = v[0];
       v[0] = 0;
       for(int i = 1; i < n; i++)
       {
            if( v[i]+previous > v[i-1])
            {
                long long current = v[i] + previous;
                v[i] = v[i-1] + 1;
                current -= v[i];
                previous = current;
            }
            else
            {
                yes = false;
                break;
            }
       }
       cout << ( yes ? "YES\n" : "NO\n");
    }
}