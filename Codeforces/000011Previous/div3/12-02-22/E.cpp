#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{		
		int m,n;
		cin>>n>>m;

		long bads[m+5][5];
		long array[n];
		int cnt[10] = {0};
		int max = 0;

		for(int i = 0; i<n; i++)
		{
			cin>>array[i];
			cnt[array[i]]++;
		}

		for(int i=0; i<m; i++)
		{
			cin>>bads[i][0]>>bads[i][1];
		}

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
			
				if(array[i] != array[j] && i!=j)
				{
					bool notBad = true;
					for(int p = 0; p < m; p++)
					{
						if(((array[i]==bads[p][0] && array[j] == bads[p][1]) || (array[i]==bads[p][1] && array[j] == bads[p][0])))
						{
							notBad = false; break;
						}
					}

					if(notBad)
					{
						int temp = (cnt[array[i]]+cnt[array[j]]) * (array[i]+array[j]);
						if(temp > max)
						{
							max = temp;
						}

					}
				}
			}
		}
		cout<<max<<endl;
	}	
	return 0;
}