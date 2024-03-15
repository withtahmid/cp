#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define dbg(...)
#endif

bool read(auto &...x) {return (((cin >> x) ? 1 : 0) && ...);}
void print(const auto &...x) {((cout << x), ...); }
void println(const auto &...x) { print(x..., '\n');}

const int maxn = 1e7 + 10;
vector<bool>isPrime(maxn);
bool isPrime[maxn];
void sieve(){
	for(int i = 0; i < maxn; ++i){
		isPrime[i] = true;
	}
	isPrime[1] = false;
	for(int i = 2)

}

void solve(const int& tc){
	
}
signed main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	//cin >> t;
	for(int i = 1; i <= t; ++i){
		solve(i);
	}
}