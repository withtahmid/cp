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
void file_io(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
long long bs(long long n, long long k)
{
    long long low = 1, high = 2 * 1e9, mid = 0;
    while(low<high)
    {
        mid = (low+high)/2;
        long long num = mid - (mid/n);
        if(num == k)
        {
            return mid;
        }
        else if(num > k)
        {
            high = mid;
        }
        else
        {
           low = mid;
        }
    }
    return mid;
}
int main()
{
	file_io();
    boostIO
    test_case{
        long long n,k;
        cin>>n>>k;
        if(n==2)
        {
            cout << (k*2)-1<<endl;
            continue;
        }
        cout << bs(n,k) << endl;
    }   
}
