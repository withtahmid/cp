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

const int N = 2e5 + 69;
int n, a[N], seq[N]; 

void solve(const int& tc){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i < n; ++i){
        seq[i - 1] = __gcd(a[i - 1], a[i]);
    }

    vector<int>_left(n - 1), _right(n - 1);

    _left.front() = 1;
    for(int i = 1; i < len(_left); ++i){
        _left[i] = (seq[i - 1] <= seq[i]) && _left[i - 1];
    }
    _right.back() = 1;
    for(int i = len(_right) - 2; i >= 0; --i){
        _right[i] = (seq[i + 1] >= seq[i]) && _right[i + 1];
    }

    auto check = [&](int index)-> bool{
        if(index == 0){
            return _right[1];
        }else if(index == n - 1){
            return _left[len(_left) - 2];
        }
        else if(index == n - 2){
            int newGcd = __gcd(a[index + 1], a[index - 1]);
            return (seq[index - 2] <= newGcd) and _left[index - 2];
        }else if(index == 1){
            int newGcd = __gcd(a[index + 1], a[index - 1]);
            return (newGcd <= seq[index + 1]) and _right[index + 1];
        }

        if(!_left[index - 2] or !_right[index + 1]){
            return 0;
        }
        int newGcd = __gcd(a[index + 1], a[index - 1]);
        if(seq[index - 2] <=  newGcd and newGcd <= seq[index + 1]){
            return 1;
        }
        return 0;
    };

    for(int i = 0; i < n; ++i){
        if(check(i)){
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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
