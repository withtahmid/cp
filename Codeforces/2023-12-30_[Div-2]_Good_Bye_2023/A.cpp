/**
 *
 * Author: withtahmid
 * Created: 2023-12-30 20:43:15
 *
 **/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...)
#define dbg(...)
#define init(...)
#endif
#define endl '\n'
#define pb push_back
#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define mem(x, y) memset(x, y, sizeof(x))
typedef int_fast64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline constexpr auto _max(const auto f, const auto... r){return max({f, r...});}
inline constexpr auto _min(const auto f, const auto... r){return min({f, r...});}
inline void operator>>(istream& istream, vector<auto>&v){for(auto& i:v){cin>>i;}}
void solve(int);
void precompute();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init();
    precompute();
    bool test_case = true;
    int tc = 1; if(test_case){cin >> tc;}
    for(int i = 1; i <= tc; ++i){
        solve(i);
    }
    dbg(__elapsed__());
}

const int N = 2400 + 5;
bool isPrime[N];
vector<int> primes;
void sieve(){
    for(int i = 1; i <= N; i++){
        isPrime[i] = true;
    }
    isPrime[1] = false;
    for(int i = 4; i <= N; i += 2){
        isPrime[i] = false;
    }
    for(int i = 3; i*i <= N; i+=2){
        if(isPrime[i]){
            for(int j = i*i; j<= N; j+= 2*i){
                isPrime[j] = false;
            }
        }
    }
    for(int i = 1; i < N; ++i){
        if(isPrime[i]){
            primes.pb(i);
        }
    }
}

void precompute(){
    sieve();
}

vector<int> factorize(int n){
    vector<int> result;
    for (int p : primes){
        if (p * p > n) 
            break;
        if (n % p == 0){
            int expo = 0;
            while (n % p == 0){
                ++expo;
                n /= p;
                result.push_back(p);
            }
            
        }
    }
    if (n != 1) {
        result.push_back(n);
    }
    return result;
}

void solve(const int case_no){
    const int x = 2023;
    int n, k;
    cin >> n >> k;
    vector<int>v(n);
    cin >> v;

    ll prod = 1LL;

    for(int i = 0; i < n; ++i){
        prod *= v[i];
        if(x % prod != 0){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    
    auto res = factorize(x / prod);
    if(len(res) < k){
        for(int i = 0; i < k - len(res); ++i){
            cout << "1 ";
        }
    }
    else{
        while(len(res) > k){
            res[0] *= res.back();
            res.pop_back();
        }
    }
   
    
    for(auto i : res){
        cout << i <<" ";
    }
    cout << endl;
    
}
