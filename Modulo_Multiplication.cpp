#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long func(long long a, long long b)
{
    long long res = 0;

    a %= mod;

    while (b)
    {

        if (b & 1)
            res = (res + a) % mod;

        a = (2 * a) % mod;

        b >>= 1;
    }

    return res;
}
int main()
{
    cout << func(1e5, 1e6 + 2) << endl;
    return 0;
}