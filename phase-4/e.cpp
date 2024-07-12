#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n; // Number of frogs
        cin >> n;

        vector<int> hops(n); // Array to store the hop lengths of each frog
        for (int i = 0; i < n; i++) {
            cin >> hops[i];
        }

        // Initialize the maximum number of frogs that can be caught
        int max_catch = 0;

        // Iterate over each frog's hop length
        for (int i = 0; i < n; i++) {
            // Initialize the maximum number of frogs that can be caught for each hop length
            int max_catch_for_hop = 0;

            // Iterate over each hop length
            for (int j = 0; j <= hops[i]; j++) {
                // Check if the current hop length can be caught
                if (j <= n) {
                    // Update the maximum number of frogs that can be caught for this hop length
                    max_catch_for_hop = max(max_catch_for_hop, j);
                }
            }

            // Update the maximum number of frogs that can be caught overall
            max_catch = max(max_catch, max_catch_for_hop);
        }

        cout << max_catch << endl;
    }

    return 0;
}