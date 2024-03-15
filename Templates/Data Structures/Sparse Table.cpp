

template<class T>
class SparseTable{
private:
    vector<vector<T>>sparse_table;
    function<T(T, T)> func;
    int n, lgn;
public:
    SparseTable(const vector<T>& v, const function<T(T, T)>& _func){
        this -> func = _func;
        this -> n = v.size();
        assert(n != 0);
        this -> lgn = __lg(v.size()) + 1;
        this -> sparse_table.resize(n, vector<T>(lgn));
        for(int i = 0; i < this -> n; ++i){
            this->sparse_table[i][0] = v[i];
        }
        for(int j = 1; j < lgn; ++j){
            for(int i = 0; i + (1 << j) - 1 < this->n; ++i){
                this->sparse_table[i][j] = this->func(this->sparse_table[i][j - 1], this->sparse_table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    T query(int l, int r){
        assert(0 <= l and r < this->n and l <= r);
        int lgr = __lg((r - l + 1));
        return (this->func(this->sparse_table[l][lgr], this->sparse_table[r - (1 << lgr) + 1][lgr]));
    }
};

/**
 * 
 * @SparseTable<int> sparse_table(v, [&](int a, int b){return min(a, b);});
 * @sparse_table.query(l, r) // 0 based
 * 
 * */ 