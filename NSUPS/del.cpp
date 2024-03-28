#include <bits/stdc++.h>
using namespace std;

void solve(const int& tc){
    int n;
    string s;
    
    cin >> n >> s;
    
    vector<int>mp[12];
    
    for(int i = 0; i < n; ++i){
        mp[s[i] - '0'].emplace_back(i);
    }


    auto idx = [&](const int& digit, const int& lim) -> int{
        const auto& m = mp[digit];
        auto ub = upper_bound(m.begin(), m.end(), lim);
        return ub == m.end() ? -1 : *ub;
    };

    int result = 0;

    for(int i = 0;i < 10; ++i) for(int j = 0; j < 10; ++j) for(int k = 0; k < 10; ++k){
        auto x = idx(i, -1), y = idx(j, x), z = idx(k, y);
        if(x != -1 and y != -1 and z != -1){
            ++result;
        }
    }
    
    cout << result << '\n';
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc) {
        solve(tc);
    }
}
