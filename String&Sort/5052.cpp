/*
백준 골드4 전화번호 목록
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int t, n;
bool comp(vector<string> a, vector<string> b)
{
    return a.size() > b.size();
}
vector<string> phone;
vector<string> ans;
int main()
{
    cin >> t;
    for (int x = 0; x < t; x++)
    {
        cin >> n;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            phone.push_back(str);
        }
        sort(phone.begin(), phone.end()); //번호의 길이를 기준으로 오름차순으로 번호를 정렬한다.
        int p = 0;
        for (int k = 0; k < phone.size() - 1; k++)
        {
            int count = 0;
            for (int j = 0; j < phone[k].size(); j++)
            {
                if (phone[k][j] == phone[k + 1][j])
                {
                    count++;
                }
            }
            if (count == phone[k].size()) //접두어의 길이와 count가 값다면 그 번호는 일관성이 없다.
            {
                cout << "NO" << endl;
                break;
            }
            p++; //일관성이 없는 번호라면 하나씩 더해준다.
        }
        if (p == phone.size() - 1) // p의 값과 비교횟수와 같다면 그건 일관성 있는 번호들만 있기에 yes를 출력
        {
            cout << "YES" << endl;
        }
        phone.clear();
    }
}