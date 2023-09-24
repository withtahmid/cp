#include<bits/stdc++.h>
using namespace std;

const  long long N =  1e8;
bool isPrime[N+5];
vector< long long>primes(N);
void sieve()
{
	fill(isPrime,isPrime+N+5,true);
	//isPrime[1] = false;

	for( long long i=4; i<=N; i+=2)
		isPrime[i] = false;

	for( long long i=3; i*i <= N; i+=2)
	{
		if(isPrime[i])
		{
			for( long long j = i*i; j<=N; j+= 2*i)
				isPrime[j] = false;
		}
	}
	for( long long i=2; i<=N; i++)
	{
		if(isPrime[i])
		{
			primes.push_back(i);
		}
	}
}

int main()
{
	sieve();
	 long long l,r;
	cin>>l>>r;
	if(l==1 || r==1){
		cout<<max(l,r)-1<<endl;
		return 0;
	}
	 long long x,y;
	if(isPrime[l]) {
		x=l;
	}
	else
	{
		x = *(upper_bound( primes.begin(), primes.end(), l));
	}

	if(isPrime[r]){
		y=r;
	} 
	else
	{
		auto temp = (upper_bound(primes.begin(), primes.end(),r));
		auto another  =  --temp;
		y = *another;  
	}
	cout<<y-x<<endl;

	

}