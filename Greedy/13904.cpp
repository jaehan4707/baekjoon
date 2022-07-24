//���� ���3 13904 ����
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, day = 1, sum = 0;
vector<int> finish, score;
vector<pair<int, int>> p, np;
vector<int> visit(1001, 0);
bool cmp(pair<int, int>& a, pair<int, int>& b) //pair�� sort�ϱ� ���� �Լ�.
{
    //�켱 �̵��� ū ������� ������ �Ѵ�. ���� �̵��� ���ٸ� ���� �������� ū ������� ����
    if (a.second == b.second)
    {
        return a.first > b.first;
    }
    else
    {
        return a.second > b.second;
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int deadline, profit;
        cin >> deadline >> profit;
        p.push_back(make_pair(deadline, profit));
    }
    sort(p.begin(), p.end(), cmp);
    int end_day = 0;
    for (int i = 0; i < n; i++)
    {
        end_day = p[i].first; //������ �������� end_day�� ���Ѵ�.
        int score = p[i].second; //������ ������ scroe�� ����.
        for (int j = end_day; j >= 1; j--) //�����Ϻ��� �Ϸ羿 ��Ƽ� ������ �ִ´�.
        {
            if (visit[j] == true) //���� j�� day��� �����ϸ� ����. �ش� ���� �̹� ������ �����Ǿ��ٸ� �Ѿ.
            {
                continue;
            }
            else //���� �ش� ���� ������ �������� �ʾҴٸ� 
            {
                sum += score; //������ ������ ���ϰ�
                visit[j] = true; //�ش糯���� Ǯ����� ������ ���õǾ��ٴ°��� �˸���.
                break;
            }
        }
    }
    cout << sum;
}