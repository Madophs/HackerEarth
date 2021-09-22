#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cases = 0, green, purple, participants;
    cin >> cases;

    while (cases--) {
        cin >> green >> purple;
        cin >> participants;

        pair<int, int> solved = make_pair(0,0);
        int first, second;
        while (participants--) {
            cin >> first >> second;
            solved.first += first;
            solved.second += second; 
        }

        int minimum = min(solved.first * green + solved.second * purple, solved.first * purple + solved.second * green);
        cout << minimum << '\n';
    }

    return 0;
}