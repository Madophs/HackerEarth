#include <bits/stdc++.h>

using namespace std;

int countBits(int n) {
    int count = 0;
    while(n) {
        n = n&(n-1);
        ++count;
    }
    return count;
}

int main()
{
    int t, n;
    cin >> t;
    while (t-- && cin >> n) {
        cout << countBits(n) << '\n';
    }
}