#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n), ps(n);
        for(auto& i : v){
            cin >> i;
        }
        for(int i = 1; i < n; ++i){
            ps[i] = (v[i] != v[i - 1] ? 1 : 0);
            ps[i] += ps[i - 1];
        }
        int q;
        cin >> q;
        while(q--){
            int l, r;
            cin >> l >> r;
            int next = (int) (upper_bound(ps.begin(), ps.end() , ps[l - 1]) - ps.begin());
            if(next >= r){
                cout << "-1 -1" << endl;
            }else{
                cout << l << " " << next + 1 << endl;
            }
        }
    }
}