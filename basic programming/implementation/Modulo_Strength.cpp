#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, v;
    cin >> n >> k;
    vector<int> vec(k+1, 0);
    for (int i = 0; i < n && cin >> v; ++i)
        ++vec[v%k];
    int64_t ans = 0;
    for (int &i : vec)
        if (i > 1)
            ans += (int64_t)i * (i-1LL);
    cout << ans << '\n';
    return 0;
}