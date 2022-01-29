#include <bits/stdc++.h>

using namespace std;

long long modularExponentiation(long long a, long long n, const long long mod)
{
    if (n == 0)
        return 1LL;

    long long res = 1;
    while (n > 0) {
        if (n & 1LL)
            res = (res * a) % mod;
        a = (a * a) % mod;
        n /= 2;
    }

    return res;
}

long long extendedEuclid(long long a, long long b, long long &x, long long &y)
{
    if (b == 0) {
        x = 1, y = 0;
        return a;
    } else {
        long long x1, y1;
        long long d = extendedEuclid(b, a%b, x1, y1);
        x = y1;
        y = (x1 - ((a / b) * y1));
        return d;
    }
}

long long modInverse(long long a, long long m) {
    long long x, y;
    extendedEuclid(a, m, x, y);
    return (x%m+m)%m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long a, b, c, m;
    cin >> a >> b >> c >> m;

    long long ab = modularExponentiation(a, b, m);
    long long inverseOfC = modInverse(c, m);
    long long ans = (ab * inverseOfC) % m;
    cout << ans << '\n';
    return 0;
}
