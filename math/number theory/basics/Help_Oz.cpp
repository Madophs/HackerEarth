#include <bits/stdc++.h>

using namespace std;

vector<int> calcDivisors(int n)
{
    int limit = ceil(sqrt((double)n));
    vector<int> divisors(1, n);
    for (int i = 2; i <= limit; ++i) {
        if (n % i != 0) continue;
        int res = n / i;
        if (res == i)
            divisors.push_back(i);
        if (res > 1 && res != i)
            divisors.push_back(res), divisors.push_back(i);
    }
    return divisors;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> m(n), diff;
    for (int &item : m) cin >> item;
    for (int i = 1; i < m.size(); ++i) {
        diff.push_back(abs(m[i-1]-m[i]));
    }

    int gcdDiff = diff.front();
    for (int i = 1; i < diff.size(); ++i) {
        gcdDiff = gcd(gcdDiff, diff[i]);
    }

    vector<int> divisors = calcDivisors(gcdDiff);
    sort(divisors.begin(), divisors.end());

    for (auto item : divisors)
        cout << item << ' ';
    cout << endl;

    return 0;
}
