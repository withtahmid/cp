/**
 * 
 * Author: withtahmid
 * Created: 07-08-2022 21:44:46
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
        vi(n);
        cin>>v;
        if(n<3)
        {
            cout << "YES\n";
            continue;
        }
        bool yes = true;
        for(int  i = 1; i+1 < n; i++)
        {
            if( v[i] < v[i-1] && v[i] < v[i+1] )
            {
                yes = false;
                break;
            }
        }
        
        if(yes)
            cout << "YES\n";
        else
            cout << "NO\n";
        
    }
}
