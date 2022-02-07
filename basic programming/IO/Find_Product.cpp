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

    int n;
    int64_t val, ans = 1LL, MOD = 1000000007LL;

    cin >> n;
    while (n-- && cin >> val)
        ans *= val, ans %= MOD;
    cout << ans << '\n';
    return 0;
}
