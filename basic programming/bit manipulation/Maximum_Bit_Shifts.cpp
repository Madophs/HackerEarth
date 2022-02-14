#include <bits/stdc++.h>
#define ispow2(x) (x && !(x & (x-1LL)))

using namespace std;

inline void swapBits(int64_t &item)
{
    if (ispow2(item))
        return;

    int64_t tmpItem = item, swappedItem;
    int count = 0;
    while (!ispow2(tmpItem)) {
        tmpItem = tmpItem & (tmpItem-1);
        // This is the Most Significant Bit
        ++count;
        if (ispow2(tmpItem))
            swappedItem = tmpItem;
    }

    while (count--) {
        swappedItem |= (swappedItem >> 1LL);
    }

    item = swappedItem;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int64_t> vec(n);
    for (int64_t &item : vec)
        cin >> item;
    
    for (int64_t &item : vec) {
        swapBits(item);
        cout << item <<  " ";
    }
    cout << '\n';
    return 0;
}