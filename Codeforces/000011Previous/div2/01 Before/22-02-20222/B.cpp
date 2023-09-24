#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		
		cin>>n;
		//int array[n];
		set<vector<int>>st;
		vector<int>array(n);
		//deque<int>
		int x= 0;
		for(int i=n-1; i>=0; i--)
		{
			array[x++] = i+1;
		}
		for(int i=1; i<=n; i++)
		{	
			for(int p =0; p<n; p++)
				cout<<array[p]<<" ";
			cout<<endl;
				swap(array[i],array[i-1]);
		}
	}
}