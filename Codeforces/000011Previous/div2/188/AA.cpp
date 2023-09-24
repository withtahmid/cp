#include<bits/stdc++.h>
using namespace std;
int main()
{

    long long int n, k;

    cin >> n >> k;
    long long int odd = (n / 2) + (n % 2);
    long long int even = (n / 2);
   // int a[odd + 1], b[even + 1];

    if (odd >= k)
    {
        cout << 2 * k - 1;
    }
    else if (odd < k)
    {
        long long int j = 1;
        for (long long int i = odd + 1; i <= k; i++)
        {
            if (i == k)
            {
                cout << 2 * j;
                break;
            }

            else
            {
                j++;
            }
        }
    }
}