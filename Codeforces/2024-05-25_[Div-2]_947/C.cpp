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
#define int int64_t
typedef long double ld;
typedef pair<int, int> pii;

const int N = 1e5 + 69;

static int n, a[N];


// brutforce part

map<int64_t, int> dp;
vector<int> change(vector<int> v, int l, int r){
    vector<int> x(v.begin() + l, v.begin() + r + 1);
    sort(all(x));
    int mean = x[((len(x) + 1) / 2) - 1];
    for(int i = l; i <= r; ++i){
        v[i] = mean;
    }
    return v;
}

int fn(vector<int> v){
    if(count(all(v), v[0]) == len(v)){
        return v[0];
    }
    int64_t state = 0;
    for(int i = 0; i < len(v); ++i){
        state = (state * 10) + v[i];
    }
    if(dp.count(state)){
        return dp[state];
    }
    int& res = dp[state];
    for(int i = 0; i < len(v); ++i) for(int j = i + 1; j < len(v); ++j){
        res = max(res, fn(change(v, i, j)));
    }
    return res;
}

int brutforce1(){
    ::dp.clear();
    vector<int> v(a, a + n);
    return fn(v); 
}


int brutforce2(){
    vector<int> v(a, a + n);
    
    auto x = v;
    sort(all(x));
    int mean = x[((len(x) + 1) / 2) - 1];
    
    auto get_mean = [&](int ln) -> int{
        assert(ln > 0);
        int ok = INT_MIN;
        for(int i = 0; i + ln - 1 < n; ++i){
            vector<int> vec(a + i, a + i + ln);
            sort(all(vec));
            int m = vec[((len(vec) + 1) / 2) - 1];
            ok = max(ok, m);
        }
        return ok;
    };

    int l = 1, r = n - 1;
    while(r - l > 1){
        int m1 = (l + r) / 2 + 1;
        int m2 = m1 - 1;
        auto f1 = get_mean(m1);
        auto f2 = get_mean(m2);
        mean = max({mean, f1, f2});
        if(f1 > f2){
            l = m1;
        }else{
            r = m2;
        }
    }   
    return mean;
}
// ends brutforce

void brut(){
    vector<int> v = {1, 2, 3, 4, 5, 6};
    sort(all(v));
    n = v.size();
    map<bool, int>ok;
    int cnt_ok = 0, notok = 0;
    do{
        for(int i = 0; i < n; ++ i){
            a[i]  = v[i];
        }
        auto x = brutforce1();
        auto y = brutforce2();
        cnt_ok += (x == y);
        notok += (x != y);

    }while(next_permutation(all(v)));
    
    dbg(cnt_ok, notok);
}


void solve(const int& tc){
    brut();
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    #ifdef LOCAL
    // cout << (brutforce1() ==  brutforce2()) << '\n';
    #endif

}

int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0); 
    dbg(ok());
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        dbg(kes(tc));
        solve(tc);
    }
    dbg(bye());
}
