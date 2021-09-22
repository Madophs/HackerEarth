#include <bits/stdc++.h>

using namespace std;

int main()
{
    string zooword;
    cin >> zooword;

    int x = 0, y = 0;
    for (char &val : zooword)
    {
        if (val == 'z') ++x;
        else ++y;
    }

    if (y == (x << 1)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}