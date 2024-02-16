
string bin(long long n){
    int bit = 64;string res = string(bit, '0');
    for(int i = 0; i < bit; ++i)res[bit - i - 1] = ((n >> i) & 1) ? '1' : '0';
    return res;
}
string bin(long long n, int pad){
    int bit = 64;string res = string(bit, '0');
    for(int i = 0; i < bit; ++i)res[bit - i - 1] = ((n >> i) & 1) ? '1' : '0';
    return res.substr(bit - pad + 1, string::npos);
}
inline int iThBit(const long long num, int i){return((num>>i)&1);}
inline void set_bit(long long& num, int i){num|=(1ULL<<i);}
inline void unset_bit(long long& num, int i){num&=(~(1ULL<<i));}
inline void toggle_bit(long long& num, int i){num^=(1ULL<<i);}
inline long long setted(long long num, int i){return(num | (1ULL<<i));}
inline long long unsetted(long long num, int i){return(num&(~(1ULL<<i)));}
inline long long togggled(long long num, int i){return(num^(1ULL<<i));}