#include <bits/stdc++.h>

using namespace std;

char toggle(char c) {
    if (c >= 'a' && c <= 'z')
        return toupper(c);
    return tolower(c);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string line;
    cin >> line;
    transform(line.begin(), line.end(), line.begin(), toggle);
    cout << line << '\n';
    return 0;
}
