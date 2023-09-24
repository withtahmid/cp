#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	printf("%.12lf %.12lf\n",(double)a/sqrt((a*a)+(b*b)),(double)b/sqrt((a*a)+(b*b)));
}