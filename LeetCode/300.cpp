

#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL  
#include <debug.h>
#else
#define dbg(...)
#endif

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = int(nums.size());
        vector<int>dp(n);
        for(int i = 0; i < n; ++i){
            dp[i] = 1;
            for(int j = 0; j <= i; ++j){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            } 
        }
        return *max_element(dp.begin(), dp.end());
    }
};

void solve(const int& tc){
    Solution s;
    vector<int>v = {10,9,2,5,3,7,101,18};
    dbg(s.lengthOfLIS(v));    
}


int32_t main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int tc = 1; tc <= t; ++tc){
        solve(tc);
    }
}
