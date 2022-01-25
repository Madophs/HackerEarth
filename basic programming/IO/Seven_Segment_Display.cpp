#include <bits/stdc++.h>

using namespace std;

int sticksReq[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
vector<pair<int, int>> priority;

void consPrioVec() {
    for (int i = 0; i < 10; ++i) {
        priority.push_back({sticksReq[i], i});
    }

    sort(priority.begin(), priority.end(), [] (auto a, auto b) {
        if (a.first < b.first)
            return true;
        if (a.first == b.first && a.second > b.second)
            return true;
        return false;
    });
}

int getAmountOfSticks(string n) {
    int sticks = 0;
    for (char &c : n) {
       sticks += sticksReq[(int)(c-'0')];
    }
    return sticks;
}

string largestPossible(string n) {
    int sticks = getAmountOfSticks(n);
    string ans;
    for (int i = 0; i < 10 && sticks > 0; ++i) {
        int mntSticksReq = priority[i].first, stickDigit = priority[i].second;
        while (sticks >= mntSticksReq) {
            if (sticks == 3) {
                sticks = 0;
                ans.push_back('7');
                break;
            }
            sticks -= mntSticksReq;
            ans += to_string(stickDigit);
        }
    }
    sort(ans.begin(), ans.end(), std::greater<char>());
    return ans;
}

int main()
{
    consPrioVec();
    int t;
    string n;
    cin >> t;

    while (t--) {
        cin >> n;
        cout << largestPossible(n) << '\n';
    }
    return 0;
}