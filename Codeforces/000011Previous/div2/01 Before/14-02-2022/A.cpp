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
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin>>arr[i];
		}
		sort(arr, arr+n);
		int count =1;
		for(int i=1; i<n; i++)
		{
			if(arr[i] == (arr[i-1]+1))
				count++;
			else
				break;
		}
		cout<<arr[0]<<" ";
		for (int i = 1; i < count; i++)
		{
			cout<<arr[i]<<" ";
		}cout<<endl;

	}
	return 0;
}