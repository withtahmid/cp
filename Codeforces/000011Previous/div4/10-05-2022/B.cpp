#include<bits/stdc++.h>
using namespace std;
#define test_case int t, c = 0; cin>>t; while(t--)
int main()
{
	test_case{
		int n;
		cin>>n;
		vector<int>v(n);
		int mn = 1e8;
		//int mx = 0;
		for (int i = 0; i < n; ++i)
		{
			int temp;
			cin>>temp;
			v[i] = temp;
			mn = min(mn,temp);
			
		}
		int sum = 0;
		//cout<<"Min: "<<mn<<endl;
		for (int i = 0; i < n; ++i)
		{
			sum += abs(v[i] - mn);
		}
		cout<<sum<<endl;
	}
} 