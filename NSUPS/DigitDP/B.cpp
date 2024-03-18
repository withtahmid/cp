#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif


inline bool ev(const int& x){
    return (x == 0) or (x == 1);
}

inline bool od(const int& x){
    return (x == 0) or (x == 2);
}

inline int f(int digit, int cnt , int i){
    if(i != digit){
        return cnt;
    }
    return (cnt + 1) & 1 ? 1 : 2;
}

int64_t dp[22][2][2][3][3][3][3][3][3][3][3][3][3];

int64_t fn(string& s, int pos = 0, int tight = 1, int nlz = 0, 
    int zero = 0, int one = 0, int two = 0, int three = 0, int four = 0, 
    int five = 0, int six = 0, int seven = 0, int eight = 0, int nine = 0){
    if(pos == int(s.size())){
        bool even = ev(zero) and ev(two) and ev(four) and ev(six) and ev(eight);
        bool odd  = od(one) and od(three) and od(five) and od(seven) and od(nine);
        return even and odd and nlz ? 1 : 0;
    }
    
    int64_t& res = dp[pos][tight][nlz][zero][one][two][three][four][five][six][seven][eight][nine];
    
    if(res != -1){
        return res;
    }
    
    res = 0;
    
    dbg(pos, tight);

    const int limit = (tight ? int(s[pos] - '0') : 9);
    for(int i = 0; i <= limit; ++i){
        res += fn(s, pos + 1, (tight and (i == limit)), nlz or (i > 0), 
            f(0, zero, i), f(1, one, i), f(2, two, i), f(3, three, i), f(4, four, i), 
            f(5, five, i), f(6, six, i), f(7, seven, i), f(8, eight, i), f(9, nine, i));
    }
    return res;
}

int brut(int l, int r){
    int cnt = 0;
    for(int num = l; num <= r; ++num){
        map<int, int>mp;
        bool flag = true;
        auto X = num;
        while(num > 0){
            ++mp[num % 10], num /= 10;
        }
        for(auto[k, v] : mp){
            if((k & 1) == (v & 1)){
                flag = false;
                break;
            }
        }
        num = X;
        if(flag){
            ++cnt;
        }
    }
    return cnt;
}
void solve(int a, int b){
    // unsigned long long a, b;
    // cin >> a >> b;
    // brut(a, b);
    auto pad = [](unsigned long long x) -> string{
        string s = to_string(x);
        return s;
        // reverse(s.begin(), s.end());
        // while(int(s.size()) < 20) {
        //     s.push_back('0');
        // }
        // reverse(s.begin(), s.end());
        // return s;
    };

    auto x  = pad(a - 1), y = pad(b);
    memset(dp, -1, sizeof(dp));
    // auto l  = fn(x);
    auto l = 0;
    memset(dp, -1, sizeof(dp));
    auto r = fn(y);
    // dbg(x, y);
    // dbg(l, r);
    
    auto br = brut(a, b);        

    auto ok = r  - l;

    cout << (br == ok ? 1 : 0)  << " " << br <<" : "; 
    cout << r - l << "\n";
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    dbg(__init__());
    // memset(dp, -1, sizeof(dp));
        solve(1, 100);
    // for(int i = 1; i < 201; ++i){
    // } 
    // int t = 1;
    // cin >> t;
    // for(int tc = 1; tc <= t; ++tc){
    //     solve(tc);
    // }
    dbg(__elapsed__());
}
