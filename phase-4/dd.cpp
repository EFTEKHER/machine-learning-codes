#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    
    // Prefix sum array
    vector<long long> prefix_sum(n);
    prefix_sum[0] = v[0];
    for (int i = 1; i < n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + v[i];
    }
    
    // Sorting and indexing
    vector<int> sorted_v = v;
    sort(sorted_v.begin(), sorted_v.end());
    vector<int> index_sorted(n);
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(sorted_v.begin(), sorted_v.end(), v[i]);
        index_sorted[i] = it - sorted_v.begin();
    }
    
    int m;
    cin >> m;
    while (m--) {
        int type, l, r;
        cin >> type >> l >> r;
        --l; // Convert to 0-based index
        --r;
        
        if (type == 1) {
            // Sum query
            long long sum = prefix_sum[r] - (l > 0 ? prefix_sum[l - 1] : 0);
            cout << sum << endl;
        } else {
            // i-th smallest query
            int k;
            cin >> k;
            --k; // Convert to 0-based index for k-th smallest
            
            int idx = index_sorted[k];
            if (idx >= l && idx <= r) {
                cout << sorted_v[k] << endl;
            } else {
                cout << "Zan'nenda" << endl;
            }
        }
    }
    
    return 0;
}