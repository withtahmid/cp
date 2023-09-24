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
#define sort(v) sort(v.begin(), v.end())
#define reverse(v) reverse(v.begin(), v.end())
#define ub(v,n) upper_bound(v.begin(), v.end(), n)
#define lb(v,n) lower_bound(v.begin(), v.end(), n)
#define pb push_back
#define test_case int t, c = 0; cin>>t;/*cin.ignore()*/ while(t--)
#define debug cout<<"I am here\n";
template <typename Type> void operator>>(istream& istream, vector<Type>& v){for(auto& i : v) cin>>i; }
template <typename Type> void operator<<(ostream& ostream, vector<Type>& v){for(auto i : v) cout<<i<<" ";}
bool isCapital(char c){
    return 'A' <= c && c <= 'Z';
}
bool isCorrect(string str)
{
    bool yes = false;
    for(int i = 1; i<str.size(); i++)
    {
        if(!isCapital(str[i]))
        {
            yes = true;
            break;
        }
    }
    return yes;
}
string makeCorrect(string str)
{
    for(int i = 0; i < str.size(); i++)
      isCapital(str[i]) ?  str[i] += 32 : str[i] -= 32;
    return str;
}
int main()
{
	boostIO
    string str;
    cin>>str;
    if(str.size() == 1)
          cout << (char) (isCapital(str[0]) ? str[0]+32 : str[0]-32) << endl;
    else if(!isCorrect(str))
        cout << makeCorrect(str) << endl;
    else
        cout << str << endl;
}
