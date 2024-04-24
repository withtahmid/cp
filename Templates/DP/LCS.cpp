
const int N = 110;
int dp[N][N];

int lcs_table(string& a, string& b){
    int n = int(a.size()), m = int(b.size());
    for(int i = 0; i <= n; ++i)for(int j = 0; j <= m; ++j){
        if(i == 0 or j == 0){
            dp[i][j] = 0;
        }
        else if(a[i - 1] == b[j - 1]){
            dp[i][j] = dp[i - 1][j - 1] + 1;
        }else{
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

string lcs_str(string& a, string& b){
    lcs_table(a, b);
    int i = int(a.size()), j = int(b.size());
    string lcs = "";
    while( i > 0 and j > 0){
        if(a[i - 1] == b[j - 1]){
            lcs += a[i - 1], --i, --j;
        }else if(dp[i - 1][j] > dp[i][j - 1]){
            lcs += a[i - 1], --i;
        }else{
            lcs += b[j - 1], --j;
        }
    }
    
    /**/
    /**/
    
    reverse(lcs.begin(), lcs.end());
    return lcs;
}