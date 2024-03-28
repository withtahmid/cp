
vector<int>spf;
void sieve(const int N = 1000000){
    spf.resize(N + 10);
    for(int i = 2; i <= N; ++i){
        spf[i] = i;
    }
    for(int i = 4; i <= N; i += 2){
        spf[i] = 2;
    }
    for(int i = 3; i * i <= N; ++i){
        if(spf[i] == i){
            for(int j = i * i; j <= N; j += (i << 1)){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}

vector<int> primeFactors(int n){
    vector<int>factors;
    while(n != 1){
        factors.emplace_back(spf[n]);
        n /= spf[n];
    }
    return factors;
}