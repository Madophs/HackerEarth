#include <bits/stdc++.h>

using namespace std;

int main()
{
    int len, val;
    int minA = numeric_limits<int>::max();

    vector<int> a, b;

    cin >> len;

    for (int i = 0; i++ < len && cin >> val; a.emplace_back(val))
        minA = min(val, minA);

    for (int i = 0; i < len && cin >> val; ++i) {
        b.emplace_back(val);
    }

    int steps = 0;
    bool possible = true;

    for (int tries = 0; tries < 2; ++tries) {
        int newMinA = minA;
        for (int i = 0; i < len; ++i) {

            int diff = a[i] - minA;

            if (!diff) continue;

            int aproxSteps = (int)ceil((double)diff / (double)b[i]);
            a[i] -= (aproxSteps * b[i]);
            steps += aproxSteps;

            if (a[i] != minA) {
                possible = false;
                if (tries != 0)
                     break;
            }
            
            newMinA = min(a[i], newMinA);
        }

        if (!possible && tries == 0) {
            possible = true;
            minA = newMinA;
        }
        else
            break;
    }

    if (possible) {
        cout << steps << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}