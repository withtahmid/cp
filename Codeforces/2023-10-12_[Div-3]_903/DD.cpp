#ifdef LOCAL
#include <debug.h>
#else
#define debug(...)
#endif

#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;

#define endl '\n'
#define all(v) v.begin(), v.end()
#define print(v)          \
    for (auto &i : v)     \
        cout << i << " "; \
    cout << endl;
#define len(v) (int)v.size()

template <typename T>
inline void operator>>(istream &istream, vector<T> &v)
{
    for (T &i : v)
    {
        cin >> i;
    }
}
template <typename T>
inline void operator<<(ostream &ostream, vector<T> &v)
{
    for (T &i : v)
        cout << i << ' ';
    cout << endl;
}

const int MAXN = 1e7 + 5;
int spf[MAXN];

void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;

    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

vector<int> getFactorization(int n)
{
    vector<int> temp;
    while (n != 1)
    {
        temp.emplace_back(spf[n]);
        n = n / spf[n];
    }
    
    return temp;
}

void solve([[maybe_unused]] const int &tc)
{
    int n;
    cin >> n;
    vector<int> v(n);
    cin >> v;
    map <int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        auto temp = getFactorization(v[i]);
        for (auto &j : temp)
        {
            mp[j]++;
        }       
    }
    dbg(mp);
    bool flag = true;
    for (auto &x: mp) {
        flag &= (x.second % n == 0);
        // cout << x.first << " " << x.second << endl;
    }
    cout << (flag ? "YES" : "NO") << endl;

}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    init();
    sieve();
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        debug(tc);
        solve(tc);
    }
    dbg("elap");
    return 0;
}