#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	stack<pair<int, int>> stk;
	cin>>n;
	while(n--)
	{
		int a;
		cin>>a;
		if(stk.empty() || stk.top().first != a){
			stk.push({a,1});
		}
		else
		{
			stk.push({a,stk.top().second+1});
			if(stk.top().second == a)
			{
				while(!stk.empty() && stk.top().first == a)
				{
					stk.pop();
				}
			}
		}
		cout<<stk.size()<<endl;
	}
}