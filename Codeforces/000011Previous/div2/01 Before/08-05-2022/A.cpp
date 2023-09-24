#include<bits/stdc++.h>
using namespace std;
#define test_case int t, c = 0; cin>>t; while(t--)
int main()
{
	test_case
	{
		int n;
		cin>>n;
		vector<int> v(n);
		for(int& i : v) 
			cin>>i;
		int count = 0, zero = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i+1 ; j < n; ++j)
			{
				if(v[i] == v[j] && i!=j && (v[i] !=0 && v[j] !=0))
				{
					count++;
					v[i] = 0;
				}
			}
			if(v[i] == 0) 
				zero ++;
		}

		if(zero>0)
		{
			for(int i : v) 
				if(i != 0) count++;
			cout<<count<<endl;
		}
		else
		{
			int low, high;
			low = high = v[0];
			for(int i : v) high = max(high,i);
			for(int i : v) low = min(low,i);
			cout<<high+low<<endl;
		}
	}
}