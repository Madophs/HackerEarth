#include <bits/stdc++.h>
#define LSB(n) (n&(-n))

using namespace std;

inline int64_t sumOddDivisor(const int64_t &n, int64_t &m)
{
    if (n == 0) return 0;
    if (n == 1LL) return 1LL;
    int64_t oddNumbers = (n+1LL) / 2LL;
    int64_t sumNaturalNum = ((oddNumbers%m) * (oddNumbers%m)) % m;
    return (sumNaturalNum + sumOddDivisor(n/2, m)) % m;
}

int main()
{
    int t;
    int64_t n, m;

    cin >> t;
    while(t--) {
        cin >> n >> m;
        cout << sumOddDivisor(n, m) << '\n';
    }
    return 0;
}