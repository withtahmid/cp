/**
 * 
 * Author: withtahmid
 * Created: 29-08-2022 15:53:32
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
#define rvs(v) reverse(v.begin(), v.end())
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
    int start = 0;
    for(int i = 1; i < n; i++)
    {
        if(v[i] < v[i-1])
        {
            start = i-1;
            break;
        }
    }
    int end = n;
    for(int i = start+1; i<n; i++)
    {
        if(v[i]>v[i-1])
        {
            end = i;
            break;
        }
    }
    reverse(v.begin()+start, v.begin()+end);  
    bool yes = true;
    for(int i = 1; i<n; i++)
    {
        if(v[i]<v[i-1])
        {
            yes = false;
            break;
        }
    }
    if(yes)
    {
        cout << "yes\n"<<start+1<<" "<<end<<endl;
    }
    else
    {
        cout << "no\n";
    }
    
}
