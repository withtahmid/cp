#include<bits/stdc++.h>
using namespace std;
int main()

{
	int t; cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int array[n];
		for(int i=0; i<n; i++)
		{
			cin>>array[i];
		}
		int answer = 0;
		for(int i=1; i<n-1; i++)
		{
			if(array[i] > array[i+1] && array[i] > array[i-1])
			{
				answer ++;
				if(i+2<n)
				{
					array[i+1] = max(array[i],array[i+2]);
				}
				else 
				{
					array[i+1] = array[i];
				}
			}
		}
		cout<<answer<<endl;
		for(int i=0; i<n; i++)
		{
			cout<<array[i]<<" ";
		}
		cout<<endl;
	}

}