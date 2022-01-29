#include <bits/stdc++.h>

using namespace std;

const int64_t MONK_QUOTIENT = 1000000007;

int64_t modularExponentiation(int64_t a, int64_t n)
{
    if (n == 0)
        return 1;
    int64_t res = 1;
    while (n > 0) {
        if (n & 1)
            res = (res * a) % MONK_QUOTIENT;
        a = (a*a) % MONK_QUOTIENT;
        n /= 2;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int64_t n;
    cin >> n;
    vector<int64_t> vec(n);
    for (int64_t &item : vec)
        cin >> item;

    int64_t x = 1;
    for (int64_t &item : vec)
        x = ((x % MONK_QUOTIENT) * (item % MONK_QUOTIENT)) % MONK_QUOTIENT;

    int64_t divisor = vec.front();
    for (int64_t i = 1; i < vec.size(); ++i) {
        divisor = gcd(divisor, vec[i]);
        if (divisor == 1)
            break;
    }
    cout << modularExponentiation(x, divisor) << '\n';
    return 0;
}
