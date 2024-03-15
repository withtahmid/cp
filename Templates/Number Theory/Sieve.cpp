vector<int> isPrime;
void sieve(const int N){
	isPrime.resize(N + 69, true);
	isPrime[1] = false;
	for(int i = 4; i <= N; i += 2){
		isPrime[i] = false;
	}
	for(int i = 3; i * i <= N; i += 2){
		for(int j = i * i; j <= N; j += (i << 1)){
			isPrime[j] = false;
		}
	}
}