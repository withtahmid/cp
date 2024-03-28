
vector<bool> isPrime;
vector<int>primes;
void sieve(const int N = 1000000){
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
    for(int i = 2; i <= N; ++i){
        if(isPrime[i]){
            primes.emplace_back(i);
        }
    }
}

vector<int> primeFactors(int n){
    assert(int(primes.size()) > 0);
    vector<int> factors;
    for(const int& p : primes){
        if(p * p > n) break;
        while(n % p == 0) n /= p, factors.emplace_back(p);
    }
    if(n != 1) factors.emplace_back(n);
    return factors;
}