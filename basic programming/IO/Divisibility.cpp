#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, val, last2Digits = 0;
    cin >> n;
    while (n > 0 && cin >> val) {
        if (n <= 2) {
            last2Digits *= 10;
            last2Digits += val % 10;
        }
        --n;
    }

    if (last2Digits % 10 == 0) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}