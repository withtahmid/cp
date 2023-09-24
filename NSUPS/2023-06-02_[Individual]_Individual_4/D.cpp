/**
 * 
 * Author: withtahmid
 * Created: 2023-06-02 10:14:41
 * 
 * */
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include <debug.h> 
#else
#define debug(...)
#define dbg(...)
#endif
#define endl '\n'
#define pb push_back
#define all(v) v.begin(),v.end()
#define sp(n) fixed << setprecision(n)
#define len(v) (int) v.size()
typedef int_fast64_t ll;
typedef vector<int_fast32_t> vi;
typedef long double ld;
template<typename... Args>
void print(Args... args){auto rest = [](const auto& arg)
{cout << arg << " "; };(rest(args), ...);cout << endl;}
template <typename Type>
void operator>>(istream& istream, vector<Type>& v){for(auto& i:v){cin>>i;}}
void solve(int);
void before_tc(){}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    io();
    #endif
    time_t Time; time(&Time);cerr << ctime(&Time) << endl;
    auto starttime = chrono::steady_clock::now();
    bool multiple_test_case = not true;
    before_tc();
    int testcase = 1; if(multiple_test_case){cin >> testcase;}
    for(int tc = 1; tc <= testcase; ++tc){
        solve(tc);
    }
    cerr << "\n\nElapsed time: " << chrono::duration_cast<chrono::milliseconds>
    (chrono::steady_clock::now() - starttime).count() << " millisecond\n";
}
const int base = 1000000000;
const int base_digits = 9;

class cpp_int {
#pragma GCC diagnostic ignored "-Wdeprecated-copy"
public:
    vector<int> a;
    int sign;
 
    cpp_int() :
        sign(1) {
    }
 
    cpp_int(long long bigint) {
        *this = bigint;
    }
 
    cpp_int(const string &s) {
        read(s);
    }
 
    void operator=(const cpp_int &bigint) {
        sign = bigint.sign;
        a = bigint.a;
    }
 
    void operator=(long long bigint) {
        sign = 1;
        if (bigint < 0)
            sign = -1, bigint = -bigint;
        for (; bigint > 0; bigint = bigint / base)
            a.push_back(bigint % base);
    }
 
    cpp_int operator+(const cpp_int &bigint) const {
        if (sign == bigint.sign) {
            
            cpp_int res = bigint;
 
            for (int i = 0, carry = 0; i < (int) max(a.size(), bigint.a.size()) || carry; ++i) {
                if (i == (int) res.a.size())
                    res.a.push_back(0);
                res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry)
                    res.a[i] -= base;
            }
            return res;
        }
        return *this - (-bigint);
    }
 
    cpp_int operator-(const cpp_int &bigint) const {
        if (sign == bigint.sign) {
            if (abs() >= bigint.abs()) {
                cpp_int res = *this;
                for (int i = 0, carry = 0; i < (int) bigint.a.size() || carry; ++i) {
                    res.a[i] -= carry + (i < (int) bigint.a.size() ? bigint.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry)
                        res.a[i] += base;
                }
                res.trim();
                return res;
            }
            return -(bigint - *this);
        }
        return *this + (-bigint);
    }
 
    void operator*=(int bigint) {
        if (bigint < 0)
            sign = -sign, bigint = -bigint;
        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
            if (i == (int) a.size())
                a.push_back(0);
            long long cur = a[i] * (long long) bigint + carry;
            carry = (int) (cur / base);
            a[i] = (int) (cur % base);
            
        }
        trim();
    }
 
    cpp_int operator*(int bigint) const {
        cpp_int res = *this;
        res *= bigint;
        return res;
    }
 
    friend pair<cpp_int, cpp_int> divmod(const cpp_int &a1, const cpp_int &b1) {
        int norm = base / (b1.a.back() + 1);
        cpp_int a = a1.abs() * norm;
        cpp_int b = b1.abs() * norm;
        cpp_int q, r;
        q.a.resize(a.a.size());
 
        for (int i = a.a.size() - 1; i >= 0; i--) {
            r *= base;
            r += a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((long long) base * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.a[i] = d;
        }
 
        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }
 
    cpp_int operator/(const cpp_int &bigint) const {
        return divmod(*this, bigint).first;
    }
 
    cpp_int operator%(const cpp_int &bigint) const {
        return divmod(*this, bigint).second;
    }
 
    void operator/=(int bigint) {
        if (bigint < 0)
            sign = -sign, bigint = -bigint;
        for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
            long long cur = a[i] + rem * (long long) base;
            a[i] = (int) (cur / bigint);
            rem = (int) (cur % bigint);
        }
        trim();
    }
 
    cpp_int operator/(int bigint) const {
        cpp_int res = *this;
        res /= bigint;
        return res;
    }
 
    int operator%(int bigint) const {
        if (bigint < 0)
            bigint = -bigint;
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i)
            m = (a[i] + m * (long long) base) % bigint;
        return m * sign;
    }
 
    void operator+=(const cpp_int &bigint) {
        *this = *this + bigint;
    }
    void operator-=(const cpp_int &bigint) {
        *this = *this - bigint;
    }
    void operator*=(const cpp_int &bigint) {
        *this = *this * bigint;
    }
    void operator/=(const cpp_int &bigint) {
        *this = *this / bigint;
    }
 
    bool operator<(const cpp_int &bigint) const {
        if (sign != bigint.sign)
            return sign < bigint.sign;
        if (a.size() != bigint.a.size())
            return a.size() * sign < bigint.a.size() * bigint.sign;
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != bigint.a[i])
                return a[i] * sign < bigint.a[i] * sign;
        return false;
    }
 
    bool operator>(const cpp_int &bigint) const {
        return bigint < *this;
    }
    bool operator<=(const cpp_int &bigint) const {
        return !(bigint < *this);
    }
    bool operator>=(const cpp_int &bigint) const {
        return !(*this < bigint);
    }
    bool operator==(const cpp_int &bigint) const {
        return !(*this < bigint) && !(bigint < *this);
    }
    bool operator!=(const cpp_int &bigint) const {
        return *this < bigint || bigint < *this;
    }
 
    void trim() {
        while (!a.empty() && !a.back())
            a.pop_back();
        if (a.empty())
            sign = 1;
    }
 
    bool isZero() const {
        return a.empty() || (a.size() == 1 && !a[0]);
    }
 
    cpp_int operator-() const {
        cpp_int res = *this;
        res.sign = -sign;
        return res;
    }
 
    cpp_int abs() const {
        cpp_int res = *this;
        res.sign *= res.sign;
        return res;
    }
 
    long long longValue() const {
        long long res = 0;
        for (int i = a.size() - 1; i >= 0; i--)
            res = res * base + a[i];
        return res * sign;
    }
 
    friend cpp_int gcd(const cpp_int &a, const cpp_int &b) {
        return b.isZero() ? a : gcd(b, a % b);
    }
    friend cpp_int lcm(const cpp_int &a, const cpp_int &b) {
        return a / gcd(a, b) * b;
    }
 
    void read(const string &s) {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }
 
    friend istream& operator>>(istream &stream, cpp_int &bigint) {
        string s;
        stream >> s;
        bigint.read(s);
        return stream;
    }
 
    friend ostream& operator<<(ostream &stream, const cpp_int &bigint) {
        if (bigint.sign == -1)
            stream << '-';
        stream << (bigint.a.empty() ? 0 : bigint.a.back());
        for (int i = (int) bigint.a.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << bigint.a[i];
        return stream;
    }
    
    friend string tostring(const cpp_int &bigint) {
        std::ostringstream stream;
        if (bigint.sign == -1)
            stream << '-';
        stream << (bigint.a.empty() ? 0 : bigint.a.back());
        for (int i = (int) bigint.a.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << bigint.a[i];
        return stream.str();
    }

    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int) p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int) a.size(); i++) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int) cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }
 
    typedef vector<long long> vll;
 
    static vll karatsubaMultiply(const vll &a, const vll &b) {
        int n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }
 
        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());
 
        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);
 
        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];
 
        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int) a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            r[i] -= a2b2[i];
 
        for (int i = 0; i < (int) r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < (int) a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }
 
    cpp_int operator*(const cpp_int &v) const {
        vector<int> a6 = convert_base(this->a, base_digits, 6);
        vector<int> b6 = convert_base(v.a, base_digits, 6);
        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());
        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        cpp_int res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < (int) c.size(); i++) {
            long long cur = c[i] + carry;
            res.a.push_back((int) (cur % 1000000));
            carry = (int) (cur / 1000000);
        }
        res.a = convert_base(res.a, 6, base_digits);
        res.trim();
        return res;
    }
};

void solve(int case_no){
    int n, x;
    cin >> n;
    cpp_int a = 1;
    for(int i = 0; i < n; ++i){
        cin >> x;
        a *= x;
    }
    int m;
    cin >> m;
    cpp_int b = 1;
    for(int i = 0; i < m; ++i){
        cin >> x;
        b *= x;
    }
    string  res = tostring(gcd(a, b));
    debug(res);
    cout << (len(res) > 9 ? res.substr(len(res)-9, string::npos) : res) << endl;
}