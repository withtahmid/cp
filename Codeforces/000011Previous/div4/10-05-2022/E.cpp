#include<bits/stdc++.h>
using namespace std;
#define test_case int t, c = 0; cin>>t; while(t--)
int main()
{
	test_case
	{
		int n,q;
		cin>>n>>q;
		vector<int>v(n);
		vector<int>v_sum(n);
		for(int& i : v) cin>>i;
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		for (int i = 1; i < n; ++i)
		{
			v[i]+=v[i-1];
		}

		for (int i = 0; i < q; ++i)
		{
			int x;
			cin>>x;
			auto ub = lower_bound(v.begin(), v.end(),x);
			if(ub == v.end())
			{
				cout<<-1<<endl;
			}
			else
			{
				cout<< ub - v.begin()+1<<endl;
			}
		}

	}
}