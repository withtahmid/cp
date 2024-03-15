// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("O3, unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int change(int ball, int run){
    if(ball % 6 == 1){
        if(run & 1){
            return 0;
        }
        else{
            return 1;
        }
    }
    return run & 1;
}

int dp[110][210][210][3];

int fn(int ball, int to_win, int to_cen, int strike){
    if(to_win <= 0){
        // cout << ball << " " << to_cen << " " << "\n";
        if(to_cen <= 0){
            return 3;
        }else{
            return 2;
        }
    }
    assert(ball >= 0);
    if(ball == 0){
        if(to_win <= 0 and to_cen <= 0){
            return 3;
        }else if(to_win <= 0){
            return 2;
        }else{
            return 1;
        }
    }

    int& res = dp[ball][to_win][to_cen][strike];
    // cout << "ball: "  <<  ball << " " << to_win << " " << to_cen << endl;
    if(res != -1){
        return res;
    }
    res = 1;
    if(not strike){
        res = max(res, fn(ball - 1, to_win, to_cen, strike ^ change(ball, 0)));
    }else{
        for(int i = 0; i <= 6; ++i){
            if(i != 5){
                res = max(res, fn(ball - 1, to_win - i, to_cen - i, strike ^ change(ball, i)));
            }
        }
    }
    return res;
}

void run_case(int tc) {
    int x, y, z;
    cin >> x >> y >> z;
    int res = fn(x, y, z, 1);
    if(res == 3){
        cout << "Like a Boss!\n";
    }
    else if(res == 2){
        cout << "Bravo Captain!\n";
    }
    else{
        cout << "Love You Captain!\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));
    
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ": ";
        run_case(tc);
    }


  return 0;
}