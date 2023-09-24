#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{		
		int m,n;
		scanf("%d %d",&n,&m);

		long int** bads = (long int**)malloc(m * sizeof(long int));
		for(int i=0; i<m; i++) {
			bads[i] = (long int*)malloc(2 * sizeof(long int));
		} 
		long int* array = (long int*)malloc(n * sizeof(long int));
		int cnt[10] = {0};
		
		int max = 0;

		for(int i = 0; i<n; i++)
		{
			scanf("%d",&array[i]);
			cnt[array[i]]++;
		}

		for(int i=0; i<m; i++)
		{
			//cin>>bads[i][0]>>bads[i][1];
			scanf("%d %d", &bads[i][0], &bads[i][1]);
		}

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
			
				if(array[i] != array[j] && i!=j)
				{
					int notBad = 1;
					for(int p = 0; p < m; p++)
					{
						if(((array[i]==bads[p][0] && array[j] == bads[p][1]) || (array[i]==bads[p][1] && array[j] == bads[p][0])))
						{
							notBad = 0; break;
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
		printf("%d\n",max);
	}	
	return 0;
}