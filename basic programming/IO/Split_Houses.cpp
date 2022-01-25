#include <bits/stdc++.h>

using namespace std;

unsigned char putFence(char &c) {
    if (c == '.')
        return 'B';
    return c;
}

int main()
{
    int n;
    string line;
    cin >> n >> line;
    
    bool adjacentHouses = false;
    for (unsigned int i = 0; !adjacentHouses && i < line.length()-1; ++i) {
        if (line[i] == 'H' && line[i+1] == 'H') {
            adjacentHouses = true;
        }
    }

    if (!adjacentHouses) {
        transform(line.begin(), line.end(), line.begin(), putFence);
        cout << "YES\n" << line;
    } else {
        cout << "NO";
    }
    return 0;
}