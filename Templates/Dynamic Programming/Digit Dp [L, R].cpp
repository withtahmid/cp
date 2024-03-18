

const int maxDigit = 22;
int64_t dp[maxDigit][2][2]/**/;

int64_t fn(const string& L, const string& R, int pos, int LT, int RT, /**/){
    if(pos == -1){
        return /**/;
    }
    int64_t& res = dp[pos][LT][RT]/**/;
    if(res != -1 and not LT and not RT){
        return res;
    }
    res = 0;
    int lo = LT ? L[pos] - '0' : 0, hi = RT ? R[pos] - '0' : 9;
    for(int i = lo; i <= hi; ++i){
        res += fn(L, R, pos - 1,  (LT&&(i==lo)),(RT&&(i==hi)), /**/);
    }
    return res;
}

int64_t go(string L, string R){
    reverse(L.begin(), L.end()), reverse(R.begin(), R.end());
    L = L  + string(R.length() - L.length(), '0');
    return fn(L, R, int(R.size()) - 1, 1, 1, /**/);
}
