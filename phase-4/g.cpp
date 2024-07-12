#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int v, r;
        cin >> v >> r;

        vector<vector<int>> board(v, vector<int>(r));

        for (int i = 0; i < v; ++i)
        {
            for (int j = 0; j < r; ++j)
            {
                cin >> board[i][j];
            }
        }

        vector<long long> mainDiag(v + r - 1, 0), antiDiag(v + r - 1, 0);

        for (int i = 0; i < v; ++i)
        {
            for (int j = 0; j < r; ++j)
            {
                mainDiag[i - j + r - 1] += board[i][j];
                antiDiag[i + j] += board[i][j];
            }
        }

        long long maxSum = 0;

        for (int i = 0; i < v; ++i)
        {
            for (int j = 0; j < r; ++j)
            {
                long long currentSum = mainDiag[i - j + r - 1] + antiDiag[i + j] - board[i][j];
                maxSum = max(maxSum, currentSum);
            }
        }

        cout << maxSum << endl;
    }

    return 0;
}