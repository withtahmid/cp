/**
 * 
 * Author: withtahmid
 * Created: 01-08-2022
 * 
 * */
#include<bits/stdc++.h>
using namespace std;
#define boostIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
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
    long long n,s;
    cin>>s>>n;
    vector<pair<int,int>>v(n);
    
    for(int i = 0; i<n; i++)
        cin>>v[i].first>>v[i].second;
    sort(v.begin(), v.end(),[&] (pair<int,int>l, pair<int,int>r)
        {
            if(l.first == r.first)
            return l.second > r.second;
        return l.first < r.first;
        }
     );
    bool yes = true;
    for(int i = 0; i < n; i++)
    {
        if(s > v[i].first)
        {
            s += v[i].second;
        }
        else
        {
            yes = false;
            break;
        }
    }
    cout << (yes? "YES\n" : "NO\n") << endl;
}
