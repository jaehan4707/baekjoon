/* DNA  1969 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, cnt;
vector<string> str;
vector<int>sum(4, 0); // 0 == A , 1 == C, 2==G, 3 ==T
vector<char> DNA;
string answer = "";
int main()
{
    cin >> n >> m;
    DNA.push_back('A'), DNA.push_back('C'), DNA.push_back('G'), DNA.push_back('T');
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        str.push_back(s);
    }
    for (int i = 0; i < m; i++)
    {
        int Max = 0, maxIdx = 0;
        for (int j = 0; j < n; j++) //�� DNA�� �ڸ������� �����ϴ� ���⼭���� �󵵼��� sum���� �������.
        {
            if (str[j][i] == 'A')
            {
                sum[0]++;
            }
            else if (str[j][i] == 'C')
            {
                sum[1]++;
            }
            else if (str[j][i] == 'G')
            {
                sum[2]++;
            }
            else if (str[j][i] == 'T')
            {
                sum[3]++;
            }
        }
        // cout<<endl;
        for (int k = 0; k < 4; k++) //���� ���� ���� ���ڿ��� ������.
        {
            if (Max < sum[k])
            {
                Max = sum[k];
                maxIdx = k;
            }
            else if (Max == sum[k])  //������ ���ڴ� ���������� ���������̴� maxidx�� �ǵ帮�� �ȵ�. �ֳ��ϸ� ���� sum���� ������ �̹� ������������ ����.
            {
                continue;
            }
        }
        answer += DNA[maxIdx]; //���� ���� ���� DNA���⼭���� �־���.
        sum.assign(4, 0); //�󵵼� �ʱ�ȭ
    }
    cout << answer << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (answer[j] != str[i][j]) //���� ã�� ���⼭���� �ٸ� ���⼭���� ���ؼ� �ٸ� ���ڼ��� �ִٸ� ++����.
            {
                cnt++;
            }
        }
    }
    cout << cnt;
}