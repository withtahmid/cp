/**
 * 
 * Author: withtahmid
 * Created: 24-07-2022 20:16:05
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
struct two_frind{
    int unhappiness;
    int friend_one;
    int friend_two;" is divisible by 33\n"
};
#define two_frind struct two_frind
bool doSort(two_frind a, two_frind b)
{
    return a.unhappiness < b.unhappiness;
}

int main()
{
	boostIO
    test_case{
        int n,m;
        cin>>n>>m;
        vector<int>v(n+2);
        for(int i = 0; i < n; i++)
        {
            cin>>v[i+1];
        }

        long long total_unhappiness = accumulate(v.begin(), v.end(),0);

        vector<two_frind>v2(m);

        for(int i = 0; i < m; i++)
        {
            int x,y;
            cin>>x>>y;
            v2[i].unhappiness = v[x]+v[y];
            v2[i].friend_one = x;
            v2[i].friend_two = y;
        }
         if(!m&1)
        {
            cout << 0 << endl;
            continue;
        }
        if(m == 1)
        {
            int a = v[v2[0].friend_one];
            int b = v[v2[0].friend_one];
            cout << min(a,b) << endl;
            continue;
        }


        // cout << endl << endl;

        //   for(two_frind i : v2)
        // {
        //     cout << i.friend_one << "+" << i.friend_two <<" = " << i.unhappiness<<endl;
        // }

        // cout << endl << endl;
      


        sort(v2.begin(), v2.end(), doSort);
        cout <<v2[0].unhappiness << endl;
    }
}
