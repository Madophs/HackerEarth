#include <bits/stdc++.h>

using namespace std;

bool isvowel(char c)
{
    switch (c) {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'Y':
        return true;
    }
    return false;
}
int main()
{
    string tag;
    cin >> tag;
    bool valid = true;
    for (int i = 0; i < tag.length()-1; ++i) {
        if (isdigit(tag[i]) && isdigit(tag[i+1])) {
            int sum = (int)tag[i] + (int)tag[i+1];
            if (sum & 1)
                valid = false;
        } else if (isalpha(tag[i]) || isalpha(tag[i+1])) {
            if (isalpha(tag[i]) && isvowel(tag[i]))
                valid = false;
            if (isalpha(tag[i+1]) && isvowel(tag[i+1]))
                valid = false;
        }
    }
    cout << (valid ? "valid\n" : "invalid\n");
}