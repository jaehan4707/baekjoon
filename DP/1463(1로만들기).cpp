#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        if (i < 4)
            a[i] = 1;
        else
        {
            if (i % 2 == 0 && i % 3 != 0)
            {
                a[i] = min(a[i - 1] + 1, a[i / 2] + 1);
            }
            else if (i % 3 == 0 && i % 2 != 0)
            {
                a[i] = min(a[i - 1] + 1, a[i / 3] + 1);
            }
            else if (i % 3 == 0 && i % 2 == 0)
            {
                a[i] = min(a[i / 2] + 1, a[i / 3] + 1);
                a[i] = min(a[i], a[i - 1] + 1);
            }
            else
                a[i] = a[i - 1] + 1;
        }
    }
    cout << a[n];
}