#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    int64_t n;

    cin >> t;

    while (t-- && cin >> n) {
        if (n == 1)
            cout << 1 << '\n';
        else {
            int64_t ans = (n * (n-1LL)) / 2;
            if (n & 1)
                 ans += (n-3)/2;
            else
                ans += (n-2)/2;
            cout << ans << '\n';
        }
    }
    return 0;
}