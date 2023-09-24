        vector<int> prime_factorize2(int n) 
        {
                vector<int> result;
                for (int p : primes) 
                {
                        if (p * p > n) 
                                break;
                        while (n % p == 0) 
                        {
                                n /= p;result.push_back(p);
                        }
                }       
                if (n != 1) 
                {
                        result.push_back(n);
                }
                return result;
        }