/**
 * 
 * Author: withtahmid
 * Created: 22-08-2022 16:41:10
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
struct touple
{
    long long first;
    long long second;
    long long third;
};
#define touple struct touple 
void file_io(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
void solve()
{
    test_case
    {
        long long n,k;
        cin>>n>>k;
        vector<touple>v;
        touple temp;
        temp.first = k;
        temp.second = k/n;
        temp.third = k/n;
        v.pb(temp);
        while(v[v.size()-1].third > 0)
        {
            temp.first = v[v.size()-1].first + v[v.size()-1].third;
            temp.second = temp.first/n;
            temp.third = temp.second - v[v.size()-1].second;
            v.pb(temp);
        }
        long long result = k;
        for(long long i = 0; i < v.size(); i++)
        {
            result += v[i].third;
        }
        cout << result << endl;
    }
}
int main()
{
	file_io();
    solve();
}
