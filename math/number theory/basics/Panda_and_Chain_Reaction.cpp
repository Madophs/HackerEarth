#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1000003LL;

vector<int64_t> fac(MOD+2);

void calcFact()
{
    fac[0] = 1;
    fac[1] = 1;
    for (int64_t i = 2LL; i <= MOD; ++i) {
        fac[i] = (fac[i-1LL] * i) % MOD;
    }
}

int64_t factMod(int64_t n)
{
    if (n >= MOD)
        return 0;
    int64_t res = 1LL;
    while (n > 1LL) {
        if ((n / MOD) & 1LL)
            res = MOD-res;
        res = ((res % MOD) * (fac[n % MOD] % MOD)) % MOD;
        n /= MOD;
    }
    return res;
}

int factmod(int n, int p) {
    vector<int> f(p);
    f[0] = 1;
    for (int i = 1; i < p; i++)
        f[i] = f[i-1] * i % p;

    int res = 1;
    while (n > 1) {
        if ((n/p) % 2)
            res = p - res;
        res = res * f[n%p] % p;
        n /= p;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    calcFact();

    int t;
    int64_t n, x;
    cin >> t;
    while (t-- && cin >> n >> x) {
        int64_t ans = factMod(n);
        ans = (ans * (x % MOD)) % MOD;
        cout << ans << '\n';
    }
    return 0;
}