#include<bits/stdc++.h>
using namespace std;
#define test_case int t, c = 0; cin>>t; while(t--)
int main()
{
	test_case{
		int n,m;
		cin >> n >> m;
		vector<string>v(n);
		int mn = 1e8;
		for( string& i : v) cin>>i;
		for(int i = 0; i < n-1; i++)
		{
			for(int j = i+1; j<n; j++)
			{
				int difference = 0;
				for(int k = 0; k < m; k++)
				{
					difference += abs(v[i][k] - v[j][k]);
				}
				mn = min(mn,difference);
			}
		}
		cout<<mn<<endl;
	}
} 