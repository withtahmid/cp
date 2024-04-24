class LCALift{
private:
    vector<vector<int>> adj, up;
    vector<int>depth;
    int N, LOG;
public:
    
    LCALift(int sz){
        this -> N = sz, this -> LOG = __lg(N);
        adj = vector<vector<int>>(n);
        up = vector<vector<int>>(n, vector<int>(LOG, -1));
    }
    LCALift(vector<vector<int>>& edges){
        this -> N = edges.size(), this -> LOG = __lg(N);
        adj = edges;
        up = vector<vector<int>>(n, vector<int>(LOG, -1));
    }
}
