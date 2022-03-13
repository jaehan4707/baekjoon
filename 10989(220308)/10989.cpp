#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, n; // N은 수의개수, n은 각 수
    cin >> N;
   
    int S[10001] = { 0 };
    for (int i = 1; i <= N; i++)
    {
        cin >> n;
        S[n]++;
    }
    
    for (int i = 1; i < 10001; i++)
    {
        if (S[i] != 0)
        {
            for (int j = 0; j < S[i]; j++)
            {
                cout << i << "\n";
            }
        }
    }
    return 0;
}