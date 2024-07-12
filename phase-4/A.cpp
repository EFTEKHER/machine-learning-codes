/*
code written by Eftekher Ali Efte from Bangladesh
 email:eftekherali2000@gmail.com
pursuing computer science and engingeering in Ruet
*/
#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <stdlib.h>
#define ull unsigned long long int
#include <ctype.h>
#include <iostream>
#include <vector>
#include <set>

#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> A(n), B(n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    vector<int> diff(n);
    for (int i = 0; i < n; i++)
    {
        diff[i] = A[i] - B[i];
    }

    sort(diff.begin(), diff.end());

    long long result = 0;
    for (int i = 0; i < n; i++)
    {
        if (diff[i] > 0)
        {
            result += i;
        }
        else
        {
            result += lower_bound(diff.begin(), diff.begin() + i, 1 - diff[i]) - diff.begin();
        }
    }

    cout << result << endl;

    return 0;
}
