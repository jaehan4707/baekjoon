#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct company
{
    int day;
    int pay;
};
void stop(vector<company>& c);
int sumpay(vector<company>& c, int DAY);
int cnt = 0;
int dp[15];
int N,n;
int main()
{
    cin >> N;
    int j;
    int Count = 0;
    vector<company>c(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> c[i].day >> c[i].pay;
    }
    for (int i = 1; i <= N; i++)
    {
        for (j = 0; j <i; j++) {
            //i+c[i].day가 j크거나 같아야함. 그리고 c[j].day+j가 N+1보다 작거나 같아야함.
            if (c[j].day + j <= i && c[i].day + i <= N + 1)
            {
                if (dp[i] > dp[j] + c[i].pay)
                    dp[i] = dp[i];
                else
                    dp[i] = dp[j] + c[i].pay;
            }
        }
    }
    int answer = 0;
    for (int i = 1; i <= N; i++) {
        answer = max(answer, dp[i]);
    }
    cout << answer;
}
