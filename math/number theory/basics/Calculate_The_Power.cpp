#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1000000007LL;

int64_t powMod(int64_t &a, int64_t &b)
{
    if (b == 0)
        return 1;

    int64_t res = 1, power = a;
    while (b > 0) {
        if (b & 1LL)
            res = (power * res) % MOD;
        power = (power * power) % MOD;
        b >>= 1;
    }
    return res;
}
int main()
{
    int64_t a, b;
    cin >> a >> b;
    cout << powMod(a, b) << '\n';
    return 0;
}