#include<bits/stdc++.h>
using namespace std;
#define test_case int t, c = 0; cin>>t; while(t--)

int first_R(vector<string>& v, int n, int m)
{
	pair<int, int> indx;
	
	for(int i=0; i<n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(v[i][j] == 'R')
			{
				return j;
			}
		}
	}
	return -1;
}

bool has_before(vector<string>& v, int indx, int n, int m)
{
	for (int j = 0; j < m; ++j)
	{
		for(int i = 0; i<n; i++)
		{
			if(v[i][j] == 'R' && j<indx)
			{
				return false;
			}
		}
	}	
	return true;
}

int main()
{
	test_case{
		int n,m;
		cin>>n>>m;
		cin.ignore();
		vector<string>v(n);
		for(string& i : v) cin>>i;
		int indx = first_R(v,n,m);
		if(has_before(v,indx,n,m) && indx>=0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}

	


}