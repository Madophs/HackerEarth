#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

long long lcm(long long a, long long b)
{
    return a * (b / (gcd(a, b)));
}

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        long long k, ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> k;
            if (i) {
                ans = lcm(ans, k);
            } else {
                ans = k;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}