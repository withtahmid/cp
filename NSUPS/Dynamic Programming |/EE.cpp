#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fast_in_out  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ln "\n"
#define sc scanf
#define pr printf

const double EPS = (double) 1e-9;
const double pii = acos(-1);
const int mod = 1000000007;
const int N = (int) 2e3;
int dp[N + 10][N + 10];
string s1, s2;
int n1, n2;

int LCS(int p1, int p2)
{
    if(p1 == 0)
    {
        return p2;
    }
    if(p2 == 0)
    {
        return p1;
    }
    if(dp[p1][p2] != -1)
    {
        return dp[p1][p2];
    }
    int res = LCS(p1 - 1, p2 - 1);
    if(s1[p1 - 1] == s2[p2 - 1])
    {
        return dp[p1][p2] = res;
    }
    res = min(res, LCS(p1 - 1, p2));
    res = min(res, LCS(p1, p2 - 1));
    return dp[p1][p2] = res + 1;
}

int main()
{
    fast_in_out;
    int test;
    cin >> test;
    for(int t = 1; t <= test; t++)
    {
        memset(dp, -1, sizeof(dp));
        cin >> s1 >> s2;
        n1 = s1.size();
        n2 = s2.size();
        int op = LCS(n1, n2);
        cout << op << ln;
    }
}
