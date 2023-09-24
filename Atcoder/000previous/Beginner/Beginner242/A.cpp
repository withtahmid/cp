#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,x;
	cin>>a>>b>>c>>x;
	
	if(x>b)
	{
		cout<<"0.000000000000"<<endl;
	}
	else if(x<=a){
		cout<<"1.000000000000"<<endl;
	}
	else
	{
		double temp = b-a;
		cout<<setprecision(11)<< (double)c/temp<<endl;

	}	
}