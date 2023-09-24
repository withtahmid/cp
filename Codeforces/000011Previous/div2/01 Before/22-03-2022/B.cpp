#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,b,x,y;
		cin>>n>>b>>x>>y;
		long long result = 0;
		long long sum = 0;
		for(int i=0; i<n; i++)
		{
			if(result+x<=b)
				result+=x;
			else
				result-=y;
			sum+=result;
		}
		cout<<sum<<endl;
	}

}