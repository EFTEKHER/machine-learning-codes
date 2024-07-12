#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n), B(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    vector<int> D(n);
    for (int i = 0; i < n; i++) {
        D[i] = A[i] - B[i];
    }

    sort(D.begin(), D.end());

    long long result = 0;
    for (int i = 0; i < n; i++) {
        if (D[i] > 0) {
            result += i;
        } else {
            int pos = lower_bound(D.begin(), D.end(), -D[i] + 1) - D.begin();
            result += pos;
        }
    }

    cout << result << endl;

    return 0;
}
