#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif



constexpr uint64_t mod = (1ULL << 61) - 1;
const uint64_t seed = chrono::system_clock::now().time_since_epoch().count();
const uint64_t base = mt19937_64(seed)() % (mod / 3) + (mod / 3);

const int MAXLEN = 1000010;

uint64_t base_pow[MAXLEN];
int64_t modmul(uint64_t a, uint64_t b) {
    uint64_t l1 = (uint32_t) a, h1 = a >> 32, l2 = (uint32_t) b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & mod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & mod) + (ret >> 61);
    ret = (ret & mod) + (ret >> 61);
    return ret - 1;
}
struct PolyHash {
    vector < int64_t > pref, suff;
    PolyHash() {}
    template < typename T >
        PolyHash(const vector < T > & ar) {
            if (!base_pow[0]) {
                base_pow[0] = 1;
                for (int i = 1; i < MAXLEN; i++) {
                    base_pow[i] = modmul(base_pow[i - 1], base);
                }
            }
            int n = ar.size();
            assert(n < MAXLEN);
            pref.resize(n + 3, 0), suff.resize(n + 3, 0);
            for (int i = 1; i <= n; i++) {
                pref[i] = modmul(pref[i - 1], base) + ar[i - 1] + 997;
                if (pref[i] >= mod) pref[i] -= mod;
            }

            for (int i = n; i >= 1; i--) {
                suff[i] = modmul(suff[i + 1], base) + ar[i - 1] + 997;
                if (suff[i] >= mod) suff[i] -= mod;
            }
        }
    PolyHash(const string str): PolyHash(vector < char > (str.begin(), str.end())) {}
    PolyHash(const char * str): PolyHash(vector < char > (str, str + strlen(str))) {}
    uint64_t get_hash(int l, int r) {
        int64_t h = pref[r + 1] - modmul(base_pow[r - l + 1], pref[l]);
        return h < 0 ? h + mod : h;
    }
    uint64_t rev_hash(int l, int r) {
        int64_t h = suff[l + 1] - modmul(base_pow[r - l + 1], suff[r + 2]);
        return h < 0 ? h + mod : h;
    }
};


void solve(const int& tc){
    string s;
    int n;
    
    cin >> n >> s;

    PolyHash H = PolyHash(s);

    auto is_palindrome = [&](int l, int r) -> bool{
        return H.get_hash(l, r) == H.rev_hash(l, r);
    };


    auto is_possible = [&](int ln) -> bool{
        if(ln > int(s.size())){
            return false;
        }
        for(int i = 0; i + ln - 1 < int(s.size()); ++i){
            if(is_palindrome(i, i + ln - 1)){
                return true;
            }
        }
        return false;
    };

    int l = 0, r = int(s.size()) - 1;
    int res_ev = 0;
    while(l <= r ){
        int mid = (l + r) >> 1;
        int ln = (mid << 1) + 2; // length of even palindrome;
        if(is_possible(ln)){
            res_ev = ln;
            l = mid + 1;
        }else{
            r =  mid - 1;
        }
    }

    l = 0, r = int(s.size()) - 1;
    int res_odd = 0;
    while(l <= r ){
        int mid = (l + r) >> 1;
        int ln = (mid << 1) + 1; // length of odd palindrome;
        if(is_possible(ln)){
            res_odd = ln;
            l = mid + 1;
        }else{
            r =  mid - 1;
        }
    }
    cout << max(res_ev, res_odd) << '\n';
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
