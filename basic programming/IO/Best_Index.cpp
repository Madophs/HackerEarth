#include <bits/stdc++.h>

using namespace std;

inline int calcItemRange(int64_t n) {
    int64_t target = n << 1LL;
    int64_t r = (int)sqrtl((long double)target);
    int64_t gauss = r * (r + 1LL);
    if (gauss <= target) {
        int64_t range = (r * (r+1LL)) / 2LL;
        return (int)(range)-1;
    } else {
        --r;
        int64_t range = (r * (r+1LL)) / 2LL;
        return (int)(range)-1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size;
    int64_t val;
    cin >> size;
    vector<int64_t> vec(size+1, 0);
    for (int i = 1; i <= size; ++i) {
        cin >> val;
        vec[i] = val + vec[i-1];
    }
    vec.push_back(vec.back());
    int64_t ans = numeric_limits<int64_t>::min();
    ++size;
    for (int i = 1; i < size; ++i) {
        int range = (size - i);
        int itemsAhead = calcItemRange(range);
        int64_t sum = vec[i+itemsAhead] - vec[i-1];
        ans = max(sum, ans);
    }

    cout << ans << '\n';
    return 0;
}