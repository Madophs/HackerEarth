#include <bits/stdc++.h>

template <typename Arg, typename... Args>
void debug(std::ostream& out, Arg&& arg, Args&&... args)
{
    out << std::forward<Arg>(arg);
    using expander = int[];
    (void)expander{0, (void(out << " " << std::forward<Args>(args)), 0)...};
    out << std::endl;
}

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n, card;
    int64_t sum, val;
    vector<int> vec;

    cin >> t;

    while (t-- && cin >> n >> card) {
        sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> val;
            sum += val;
        }

        int ans = 0;
        while (sum != 0LL) {
            while (sum > 0) {
                if (sum >= card) {
                    sum -= card;
                } else {
                    sum = 0;
                }
                ++ans;
            }

            while (sum < 0LL) {
                int64_t diff = abs(sum);
                if (diff >= card) {
                    sum += card;
                } else {
                    sum = 0;
                }
                ++ans;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
