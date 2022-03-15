#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll x = 0, y = 0, left = 0, right, mid = 0;
    cin >> x >> y;
    double z, z2; 
    // cout << x << y;
    z = 100*y/ x;
    if (z >= 99)
    {
        cout << -1;
        return 0;
    }
    right = x;
    while (left<=right)
    {
        mid = (left + right) / 2;
        z2 = (100*(y + mid) / (x + mid));
        if (z2 > z)
        {
            right = mid - 1;
        }
        else //mid일때 찾은거
        {
            left = mid + 1;
        }
    }
    cout << left;
}