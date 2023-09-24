/**
 * 
 * withtahmid
 * 
 * */
#include<bits/stdc++.h>
using namespace std;
#define boostIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
#define nl cout<<endl
#define ll  long long
#define nn int n; cin>>n
#define lln long long n; cin >> n
#define vi(n) vector<int>v(n)
#define vl(n) vector<long long>v(n)
#define sort(v) sort(v.begin(), v.end())
#define reverse(v) reverse(v.begin(), v.end())
#define ub(v,n) upper_bound(v.begin(), v.end(), n)
#define lb(v,n) lower_bound(v.begin(), v.end(), n)
#define pb(n) push_back(n)
#define test_case int t, c = 0; cin>>t;/*cin.ignore()*/ while(t--)
#define debug(i) cout<<"I am here: "<<i "\n";
template <typename Type> void print(vector<Type>& v){for(Type& i : v) cout<<i<<" ";cout<<endl;}
template <typename Type> void operator>>(istream& istream, vector<Type>& v){for(auto& i : v) cin>>i; }
template <typename Type> void operator<<(ostream& ostream, vector<Type>& v){for(auto i : v) cout<<i<<" ";cout<<"\n";}
int main()
{
	//boostIO
    test_case{
        nn;
        int arr0[n][n];
        int arr90[n][n];
        int arr180[n][n];
        int arr270[n][n];
        int finalArr[n][n];
        for(int i = 0; i < n; i++)
        {
            string str;
            cin>>str;

            for(int  j = 0; j < n; j++)
            {   
                arr0[i][j] = str[j]-'0';
                arr180[n-i-1][n-j-1] = str[j]-'0';
              
                arr90[j][n-i-1] = str[j]-'0';
                


                arr270[n-j-1][i] = str[j]-'0';
            }
        }
        int result = 0;
        for(int i = 0; i<n; i++)
        {

           
            for(int j = 0; j<n; j++)
            {
                int zero = 0, one = 0;
                arr0[i][j] == 1 ? one++ : zero++;
                arr90[i][j] == 1 ? one++ : zero++;
                arr180[i][j] == 1 ? one++ : zero++;
                arr270[i][j] == 1 ? one++ : zero++;
                int x;
                if(one == 0)
                {
                    finalArr[i][j] = 0;
                    continue;
                }
                if(zero == 0)
                {
                    finalArr[i][j] = 1;
                    continue;
                }
                one > zero ? x = 1 : x = 0;
                finalArr[i][j] = x;
            }
        }
        for(int i = 0; i<n; i++)
        {

            int zero = 0, one = 0;
            for(int j = 0; j<n; j++)
            {
                if(arr0[i][j] != finalArr[i][j])
                    result++;
            }
        }

        cout<< result << endl;
    }
}
