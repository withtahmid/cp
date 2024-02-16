ll power(ll base, ll exponent, ll mod){
    ll res = 1LL;
    base = base % mod;
    if (base == 0LL){
        return 0LL;
    }
    while (exponent > 0LL){
        if (exponent & 1LL){
            res = (res * base) % mod;
        }
        exponent >>=  1LL;
        base = (base * base) % mod;
    }
    return res;
}