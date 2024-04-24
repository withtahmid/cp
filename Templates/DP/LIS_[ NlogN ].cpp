
const int N = 1e5 + 69;
int fr_dp[N], rv_dp[N];

void lis_table(vector<int>& v){
    
    const int n = int(v.size());
    
    vector<pair<int, int>> a(n), b(n);
    
    for(int i = 0; i < n; ++i){
        a[i].first = v[i], a[i].second = i; 
        b[i].first = v[i], b[i].second = n - i - 1; 
    }

    auto srt = [](vector<pair<int, int>>& v){
        sort(v.begin(), v.end(), [&](pair<int, int> x, pair<int, int> y){
            if(x.first == y.first){
                return x.second > y.second;
            }
            return x.first < y.first;
        });
    };

    srt(a),  srt(b);

    SegmentTree<int, STNode> fr_sgTree(n), rv_sgTree(n);
    
    for(int i = 0; i < n; ++i){
        
        int fr_res = fr_sgTree.query(0, a[i].second).res;
        fr_dp[a[i].second] = fr_res + 1;
        fr_sgTree.update(a[i].second, fr_dp[a[i].second]);

        int rv_res = rv_sgTree.query(0, b[i].second).res;
        rv_dp[n - b[i].second - 1] = rv_res + 1;
        rv_sgTree.update(b[i].second, rv_dp[n - b[i].second - 1]);
    }
}