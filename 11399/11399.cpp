#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, sum = 0, time = 0;
    cin >> n;
    vector<int> P(n);
    vector<int> S(n);
    for (int i = 0; i < n; i++)
    {
        cin >> P[i];
    }
    sort(P.begin(), P.end());
    for (int i = 0; i < n; i++)
    {
        sum = sum + P[i];
        S[i] = sum;
        time = time + S[i];
    }
    cout << time;
}