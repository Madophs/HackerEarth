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

    int t, n, x;
    int bottles[10002];
    cin >> t;
    while (t--) {
        cin >> n >> x;
        for (int i = 0; i < n; ++i)
            cin >> bottles[i];
        bottles[n] = 0;
        sort(bottles, bottles+n);

        int maxBottles = 0;
        for (int i = 0; i < n && x > 0; ++i) {
            if (bottles[i] > x)
                break;
            x -= bottles[i], ++maxBottles;
        }
        cout << maxBottles << '\n';
    }
    return 0;
}
