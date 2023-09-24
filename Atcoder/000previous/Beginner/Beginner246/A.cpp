#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x1, y1, x2, y2, x3, y3;
	cin>>x1>>y1;
	cin>>x2>>y2;
	cin>>x3>>y3;

	int x;
	if(x1 == x2)
		x = x3;
	else if(x1 == x3)
		x = x2;
	else if(x2==x3)
		x = x1; 

	int y;
	if(y1 == y2)
		y = y3;
	else if(y1 == y3)
		y = y2;
	else if(y2==y3)
		y = y1; 


	cout<<x<<" "<<y<<endl;


	return 0;
}