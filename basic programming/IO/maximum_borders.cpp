#include <bits/stdc++.h>

using namespace std;

int findMaxBorder(vector<string> &matrix)
{
    int rows = (int)matrix.size();
    int cols = (int)matrix.back().size();

    int maxBorder = 0, maxUpper = 1, maxLower = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols-1; ++j) {
            // Top to bottom
            if (!i && matrix[i][j] == '#' && matrix[i][j+1] == '#')
                ++maxUpper;
            else if (i && matrix[i][j] == '#' && matrix[i][j+1] == '#' && matrix[i-1][j+1] == '.')
                ++maxUpper;
            else
                maxBorder = max(maxBorder, maxUpper), maxUpper = 1;

            // Bottom to top
            int irow = rows - i - 1;
            if (irow == (rows-1) && matrix[irow][j] == '#' && matrix[irow][j+1] == '#')
                ++maxLower;
            else if (irow != (rows-1) && matrix[irow][j] == '#' && matrix[irow][j+1] == '#' && matrix[irow+1][j+1] == '.')
                ++maxLower;
            else
                maxBorder = max(maxBorder, maxLower), maxLower = 1;
        }
    }

    return max(maxBorder, max(maxUpper, maxLower));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int cases, rows, cols;

    cin >> cases;

    while (cases--) {
        cin >> rows >> cols;
        vector<string> matrix(rows);

        for (int i = 0; i < rows; ++i)
            cin >> matrix[i];
        
        cout << findMaxBorder(matrix) << '\n';
    }

    return 0;
}