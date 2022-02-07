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

int fac[11];
inline void precalcFactorial()
{
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= 10; ++i)
        fac[i] = fac[i-1] * i;;
}

pair<int, int> possibleDigits(int &numDigits)
{
    int least = 1, largest = 1;
    for (int i = 2; i <= numDigits; ++i) {
        least = (least << 3) + (least << 1) + i;
        largest += i * pow(10, i-1);
    }
    return make_pair(least, largest);
}

int countAlmighty(int &l, int &r)
{
    int ld = log10(l) + 1, rd = log10(r) + 1;
    pair<int, int> lower = possibleDigits(ld);
    pair<int, int> upper = possibleDigits(rd);
    if (ld == rd) {
        if (lower.first >= l && upper.second <= r) {
            return fac[ld];
        } else {
            string strnum = to_string(lower.first);
            int cont = 0, num;
            do {
                num = atoi(strnum.c_str());
                if (num >= l && num <= r)
                    ++cont;
            } while (num <= r && next_permutation(strnum.begin(), strnum.end()));

            return cont;
        }
    } else {
        // Left first
        string strnum = to_string(lower.first);
        int cont = 0, num = 0;
        do {
            num = atoi(strnum.c_str());
            if (num >= l)
                ++cont;
        } while (next_permutation(strnum.begin(), strnum.end()));

        strnum = to_string(upper.first);
        num = 0;
        do {
            num = atoi(strnum.c_str());
            if (num <= r)
                ++cont;
        } while (num <= r && next_permutation(strnum.begin(), strnum.end()));

        int digits = ld + 1;
        while (digits < rd) {
            cont += fac[digits++];
        }
        return cont;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    precalcFactorial();

    int q, l, r;

    cin >> q;

    while (q-- && cin >> l >> r) {
        int ans = countAlmighty(l, r);
        cout << ans << '\n';
    }

    return 0;
}
