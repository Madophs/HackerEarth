#include <bits/stdc++.h>

using namespace std;

int main()
{
    int size;
    string number;
    cin >> size;

    int odds = 0, evens = 0, half = size / 2;
    for (int i = 0 ; i < size; ++i) {
        cin >> number;
        if (i < half) {
            if (i & 1) odds += number.at(0) - '0';
            else evens += number.at(0) - '0';
        } else {
            if (i & 1) odds += number.back() - '0';
            else evens += number.back() - '0';
        }
    }

    int diff = abs(evens - odds);
    if (diff == 0 || (diff && diff % 11 == 0)) {
        cout << "OUI";
    } else {
        cout << "NON";
    }

    return 0;
}