#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0); 
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        deque<int>d;
        for(int i = 1; i <= m; ++i) d.push_back(i);
        for(int i = d.back() + 1; i <= n; ++i) d.push_front(i);
        for(auto& i : d) cout << i << ' ';
        cout << '\n';
    }
}
