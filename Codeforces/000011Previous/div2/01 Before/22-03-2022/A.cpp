#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		if(x==0 && y==0){
			cout<<0<<endl;
			continue;
		}
		if(x==0 || y==0){
			cout<<1<<endl;
			continue;
		}
		int  temp = (x*x) + (y*y);
		int temp2 = sqrt(temp);
		if(temp2*temp2 == temp)
			cout<<1<<endl;
		else
			cout<<2<<endl;
	}
	return 0;
}