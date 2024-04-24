#include<bits/stdc++.h>
using namespace std;
#include<debug.h>
#define ll long long
#define ull unsigned long long
#define fast_in_out  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ln "\n"
#define sc scanf
#define pr printf

const double EPS = (double) 1e-9;
const double pii = acos(-1);
const int mod = 1000000007;
const int N = (int) 500 + 10;

int weight[N + 1], val[N + 1], dp[550][10005];

int knapsack(int pos, int cap, int n)
{
    if(pos == n)
    {
        return 0;
    }
    if(dp[pos][cap] != -1)
    {
        return dp[pos][cap];
    }
    dbg(dp[pos][cap], pos, cap);

    int res = knapsack(pos + 1, cap, n);

    if(cap >= weight[pos])
    {
        int take = knapsack(pos + 1, cap - weight[pos], n);
        take += val[pos];
        res = max(res, take);
    }
    return dp[pos][cap] = res;
}

int main()
{
    fast_in_out;
    int k, n;
    cin >> k >> n;
    dbg(k, n);
    for(int i = 0; i < n; i++)
    {
        cin >> val[i] >> weight[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << knapsack(0, k, n);
}
