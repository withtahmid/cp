#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		fflush(stdin);
		unsigned long long c = 0;
		vector<string> v(n);
		for(string& i : v )
			cin>>i;
		for(int i = 0; i<n; i++)
		{
			for(int j = i+1; j<n; j++)
			{
				//if(i<j)
				//{
					if((v[i][0] == v[j][0] && v[i][0]) != v[j][1])
						c++;
					else if((v[i][0] == v[j][1] && v[i][0]) != v[j][0])
						c++;
					else if((v[i][1] == v[j][0] && v[i][1]) != v[j][1])
						c++;
					else if((v[i][1] == v[j][1] && v[i][1]) != v[j][0])
						c++;
				//}
			}
		}
		printf("%d\n",c);

	}
}