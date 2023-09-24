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
        int max_x = -110;
        int min_x = 110;
        int max_y = -110;
        int min_y = 110;
        for(int i = 0; i < n; i++)
        {
            int x,y;
            cin>>x>>y;
            max_x = max(max_x,x);
            min_x = min(min_x,x);
            max_y = max(max_y,y);
            min_y = min(min_y,y);
        }
        cout << (max_x > 0 ? max_x*2 : 0) + (max_y > 0 ? max_y*2 : 0) + (min_x < 0 ? abs(min_x)*2 : 0) + (min_y < 0 ? abs(min_y)*2 : 0) << endl;
    }   
}
