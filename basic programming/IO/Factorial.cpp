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

int64_t factorial(int n)
{
    int64_t fac = 1;
    for (int i = 2; i <= n; ++i) {
        fac *= (int64_t)i;
    }
    return fac;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    cout << factorial(n) << '\n';
    return 0;
}
