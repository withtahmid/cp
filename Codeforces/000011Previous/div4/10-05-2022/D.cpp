#include<bits/stdc++.h>
using namespace std;
#define test_case int t, c = 0; cin>>t; while(t--)
int main()
{
	test_case
	{
		int n,m;
		cin>>n>>m;
		int arr[n][m];
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin>>arr[i][j];
			}
		}
		int mx = -1;
		for (int i = 0; i < n; ++i)
		{
			
			for (int j = 0; j < m; ++j)
			{
				int sum = 0;
				sum += arr[i][j];
				int axis_i = i-1, axis_j = j-1;
				while(axis_i>=0 && axis_j>=0)
				{
					sum += arr[axis_i][axis_j];
					axis_i--;
					axis_j--;
				}
				axis_i = i+1, axis_j = j+1;
				while(axis_i<n && axis_j<m)
				{
					sum += arr[axis_i][axis_j];
					axis_i++;
					axis_j++;	
				}
				axis_i = i-1, axis_j = j+1;
				while(axis_i>=0 && axis_j<m)
				{
					sum += arr[axis_i][axis_j];
					axis_i--;
					axis_j++;
				}
				axis_i = i+1, axis_j = j-1;
				while(axis_i<n && axis_j>=0)
				{
					sum += arr[axis_i][axis_j];
					axis_i++;
					axis_j--;
				}
				mx = max(mx,sum);
			}
			
		}
		cout<<mx<<endl;
	}
}