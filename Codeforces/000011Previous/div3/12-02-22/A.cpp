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
		int array[n];
		int array2[n];
		for(int i=0; i<n; i++){
			cin>>array[i];
			array2[i] = array[i]; 

		}
		sort(array2, array2+n);

		bool flag = false;
		for(int i=0; i<n; i++){
			if(array[i] != array2[i])
			{
				flag = true;
				break;
			}
		}

		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		

	}
}