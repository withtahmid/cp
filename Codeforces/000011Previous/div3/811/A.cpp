/**
 * 
 * Author: withtahmid
 * Created: 01-08-2022 20:18:01
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
        int n,H,M;
        cin>>n>>H>>M;
        int TIME = (H * 60) + M;
        int result  = 1e8;
        for(int i = 0; i<n; i++)
        {
            int h,m;
            cin>>h>>m;
            int time =  (h*60) + m - TIME;
            if(time<0)
                time += (24*60);
            result = min(time,result);
        }
        cout << result/60 <<" "<<result%60<<endl;
    }   
}
