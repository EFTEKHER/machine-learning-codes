#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> w(n);
        for (int i = 0; i < n; ++i) {
            cin >> w[i];
        }

        int left = 0, right = n - 1;
        long long leftSum = 0, rightSum = 0;
        int maxBlocks = 0;

        while (left <= right) {
            if (leftSum < rightSum) {
                leftSum += w[left++];
            } else if (leftSum > rightSum) {
                rightSum += w[right--];
            } else {
                maxBlocks = max(maxBlocks, left + (n - 1 - right));
                leftSum += w[left++];
                rightSum += w[right--];
            }
        }

        cout << maxBlocks << '\n';
    }

    return 0;
}