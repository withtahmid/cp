#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0); 
    int s, t;
    cin >> s >> t;
    int res = 0;
    const int N = 100 + 2;
    for(int a = 0; a < N; ++a) {
        for(int b = 0; b < N; ++b) {
            for(int c = 0; c < N; ++c){
                res += ((a + b + c) <= s and (a * b * c) <= t) ? 1 : 0;
            }   
        }
    }
    cout << res << '\n';
}
