/**
 * 
 * Author: withtahmid
 * Created: 23-08-2022 14:21:07
 * 
 * */
#include<bits/stdc++.h>
using namespace std;
#define boostIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n";
#define nl cout<<"\n";
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
#define decimal(n) fixed << setprecision(n)
#define test_case int t, c = 0; cin>>t;/*cin.ignore()*/ while(t--)
#define debug cout<<"I am here\n";
template <typename Type> void operator>>(istream& istream, vector<Type>& v){for(auto& i : v) cin>>i; }
template <typename Type> void operator<<(ostream& ostream, vector<Type>& v){for(auto i : v) cout<<i<<" ";}
void file_io(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
int main()
{
	file_io();
    boostIO
    nn;
    vi(n);
    cin>>v;
    vector<pair<int,int>>pairs;
    if(n==1)
    {
        cout<< !(v[n-1]) << endl;
        return 0;
    }
    int count_start = 0;
    if(v[0]==0)
    {
        for(int i = 0; i < n; i++)
        {
            if(v[i] == 1)
            {
                break;
            }
            count_start++;
        }
        pairs.pb({count_start,0});
    }
    
    int count_end = 0;
     if(v[n-1]==0)
    {
        for(int i = n-1; i>=0; i--)
        {
            if(v[i] == 1)
            {
                break;
            }
            count_end++;
        }
        pairs.pb({count_end,0});
    }

    for(int i = 1; i<n; i++)
    {
        v[i] += v[i-1];
    }

    
    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            pairs.pb({(v[j]-v[i]), ((j-i)-(v[j]-v[i]))});
        }
    }
    
    

    vector<int>results;
    for(auto i : pairs)
    {
        results.pb(i.first-i.second);
    }
    srt(results);
    cout << v[n-1] +  results[results.size()-1]<<endl;

}
