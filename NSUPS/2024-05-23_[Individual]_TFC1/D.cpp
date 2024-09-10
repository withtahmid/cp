#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL 
#include <debug.h>
#else
#define dbg(...)
#endif

#define all(v) v.begin(),v.end()
#define len(v) ((int) v.size())
#define has(v, x) ((v.find(x) != v.end()))
// #define int int64_t
typedef long double ld;
typedef pair<int, int> pii;



const int maxDigit = 15;
int64_t dp[maxDigit][2][2][2][2][2][2][2][2][2][2][2][2][2];
int64_t fn(const string& L, const string& R, int pos, int LT = 1, int RT = 1, int isZero = 1, 
            int zero = 0, int one  = 0, int two = 0, int three = 0, int four = 0, int five = 0,
            int six = 0, int seven = 0, int eight = 0, int nine = 0, int digit = 0){
    if(pos == -1){
       return 0;
    }
    int64_t& res = dp[pos][LT][RT][isZero][zero][one][two][three][four][five][six][seven][eight][nine];
    if(res != -1 and not LT and not RT){
        return res;
    }
    res = 0;
    const vector<int> v = {zero, one, two, three, four, five, six, seven, eight, nine};
    // dbg(v);
    int lo = LT ? L[pos] - '0' : 0, hi = RT ? R[pos] - '0' : 9;
    for(int i = lo; i <= hi; ++i){
        int take = 0;
        for(int d = 0; d < i; ++d){
            take += (v[d] != 0);
        }
        if(take != 0){
            dbg(digit, i, take);
        }
        res += take + fn(L, R, pos - 1,  (LT&&(i==lo)),(RT&&(i==hi)), isZero&&(i==0), zero||((!isZero)&&i==0) , one||(i==1), (two||(i==2)), three||(i==3), four||(i==4), five||(i==5), six||(i==6), seven||(i==7), eight||(i==8), nine||(i==9), (digit * 10)  + i);
    }
    return res;
}

int64_t go(string L, string R){
    reverse(L.begin(), L.end()), reverse(R.begin(), R.end());
    L = L  + string(R.length() - L.length(), '0');
    dbg(L, R);
    return fn(L, R, int(R.size()) - 1);
}


void brutforcer(){
    int cnt = 0;
    for(int dig = 1; dig <= 100; ++dig){
        string s = to_string(dig);
        for(int i = 0; i < len(s); ++i)for(int j = 0; j < len(s); ++j){
            if(s[i] < s[j] and i < j){
                ++cnt;
                dbg(s[i], s[j]);
            }
        }
    }
    dbg(cnt);
}

void solve(const int& tc){
    memset(dp,-1, sizeof(dp));
    string a, b;
    cin >> a >> b;
    // brutforcer();
    cout << "Case " << tc << ": " << go(a, b) << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0); 
    dbg(ok());
    int t = 1;
    cin >> t;
    memset(dp,-1, sizeof(dp));
    for(int tc = 1; tc <= t; ++tc){
        dbg(kes(tc));
        solve(tc);
    }
    dbg(bye());
    dbg((1 << 13) * 14);
}

