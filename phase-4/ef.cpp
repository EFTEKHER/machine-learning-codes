#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> hops(n);
        for (int i = 0; i < n; i++)
        {
            cin >> hops[i];
        }

        vector<int> count(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            int step = hops[i];
            if (step <= n)
            {
                for (int j = step; j <= n; j += step)
                {
                    count[j]++;
                }
            }
        }

        int max_frogs = 0;
        for (int i = 1; i <= n; i++)
        {
            max_frogs = max(max_frogs, count[i]);
        }

        cout << max_frogs << endl;
    }

    return 0;
}