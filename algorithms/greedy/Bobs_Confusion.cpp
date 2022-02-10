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

inline int minVal(int matrix[][3], int i, int j, char strategy = 'r')
{
    int l_minVal = numeric_limits<int>::max();
    if (strategy == 'r') {
        for (; j < 3; ++j)
            l_minVal = min(matrix[i][j], l_minVal);
    } else {
        for (; i < 3; ++i)
            l_minVal = min(matrix[i][j], l_minVal);
    }
    return l_minVal;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    int matrix[3][3];
    int a[3], b[3];

    cin >> t;
    while (t--) {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                cin >> matrix[i][j];

        memset(a, 0, sizeof(int) * 3);
        memset(b, 0, sizeof(int) * 3);

        for (int i = 0; i < 3; ++i) {
            a[i] = minVal(matrix, i, 0);
        }

        for (int i = 0; i < 3; ++i) {
            b[i] = abs(a[0]-matrix[0][i]);
        }

        bool correct = true;
        for (int i = 0; i < 3 && correct; ++i) {
            for (int j = 0; j < 3 && correct; ++j) {
                if (matrix[i][j] != (a[i] + b[j]))
                    correct = false;
            }
        }

        cout << (correct ? "YES\n" : "NO\n");
    }

    return 0;
}
