

const int maxDigit = 22;
int64_t dp[maxDigit][2]/**/;

int64_t fn(const string& s, int pos, int tight /**/){
    if(pos == -1){
        return /**/;
    }
    int64_t& res = dp[pos][tight]/**/;
    if(res != -1 and not tight){
        return res;
    }
    res = 0;
    int hi = tight ? s[pos] - '0' : 9;
    for(int i = 0; i <= hi; ++i){
        res += fn(s, pos - 1,, (tight&&(i==hi)), /**/);
    }
    return res;
}

int64_t go(string s){
    reverse(s.begin(), s.end());
    return fn(s, int(s.size()) - 1, 1, /**/);
}
