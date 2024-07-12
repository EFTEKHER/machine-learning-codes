#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int B;
        cin >> B;
        if (B < 2)
        {
            cout << 0 << endl;
        }
        else
        {
            B = B / 2 - 1;
            cout << (B * (B + 1)) / 2 << endl;
        }
    }
    return 0;
}