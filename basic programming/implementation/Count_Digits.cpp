#include <bits/stdc++.h>

using namespace std;

int main()
{
    string number;
    int count[10];
    memset(count, 0, sizeof(int)*10);
    cin >> number;
    for (char &c : number)
        ++count[c-'0'];
    for (int i = 0; i < 10; ++i) {
        cout << i << " " << count[i] << '\n';
    }
    return 0;
}