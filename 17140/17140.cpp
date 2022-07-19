/* 17140 ���4 ������ �迭�� ����


A[r][c]�� k�� �Ǳ� ���� �ð� ���
1�ʸ��� R or C ��������.

���� ��� ���͸� ���������. �ù�. ������.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int r, c, k;
vector<vector<int>> a;
map<int, int> m;
void makeary(int row, int col);
bool flag(int a, int b);
vector<int> visit;
int Row = 0, Col = 0, Cnt = 0;
int main()
{
    cin >> r >> c >> k;
    a.resize(101, vector<int>(101, 0));
    makeary(3, 3);
    int row = 3, col = 3;
    visit.resize(101, 0);     // visit�迭 101�� �ʱ�ȭ
    if (a[r - 1][c - 1] == k) //���� �ٷ� ���� ã�� �� �ִٸ� ����� �ʿ䰡 ����.
    {
        cout << 0;
    }
    else
    {
        while (1) // a[r][c]�� k�� �ǰų�? Cnt�� 100�� �ѱ�� �ȵ�.
        {
            int rsize = row; // row�� ���� ����
            int csize = col; // col�� ���� ����
            if (Cnt > 100)   // 100�ʰ� ������ -1�� ����ϰ� �ݺ����� Ż���Ŵ.
            {
                cout << -1;
                break;
            }
            if (flag(csize, rsize)) //���� ���� ����.  //csize�� ���� ����, rsize�� ���� ����
            {
                //���� 1�̸� R����
                for (int i = 0; i < csize; i++)
                {
                    vector<pair<int, int>> p;
                    for (int j = 0; j < rsize; j++)
                    {
                        if (a[i][j] == 0)
                            continue;
                        visit[a[i][j]]++; //

                        m[a[i][j]] = visit[a[i][j]];
                        a[i][j] = 0;
                    }
                    //��,����Ƚ���� ���� ����Ƚ���� �ٸ��� �� ��������, ����Ƚ���� ���ٸ� �� ��������.
                    for (auto iter = m.begin(); iter != m.end(); iter++)
                    {
                        p.push_back(make_pair(iter->second, iter->first)); // pair�� sort�ϸ� first������ ���ĵ�.
                    }
                    for (int i = 0; i < p.size(); i++)
                    {
                        for (int j = i + 1; j < p.size(); j++)
                        {
                            if (p[i].first > p[j].first) //�󵵼��� ���� ������� ����
                            {
                                swap(p[i], p[j]);
                            }
                            else if (p[i].first == p[j].first) //�󵵼��� ���ٸ� ���ڸ� ������������ ����.
                            {
                                if (p[i].second > p[j].second)
                                {
                                    swap(p[i], p[j]);
                                }
                            }
                        }
                    }
                    int idx = 0;
                    if (Row < p.size() * 2) //������ ���ڰ� ���� ũ��� pair�� 2�谡 �����Ѵ�. �ִ밪�� ��� �ٲ���.
                    {
                        Row = p.size() * 2;
                    }
                    // cout << "ROW " << Row << endl;
                    if (Row > 100) //���� ũ�Ⱑ 100�� �ѱ�ٸ� �߶���.
                        Row = 100;
                    row = Row;                         //�Լ��� �� row�� ����
                    for (int k = 0; k < p.size(); k++) //����,�󵵼� ������� �迭�� �־���.
                    {
                        a[i][idx] = p[k].second, idx++;
                        a[i][idx] = p[k].first, idx++; // second�� ����, first�� �󵵼�
                    }
                    m.clear();            // map����.
                    visit.assign(101, 0); // visit�迭 ����.
                }
                Cnt++;                    // 1�� ���
                if (a[r - 1][c - 1] == k) //���� a[r][c]�� ã�Ҵٸ� �׶� �ð��ʸ� ����ϰ� �ݺ��� Ż��
                {
                    cout << Cnt;
                    break;
                }
            }
            else
            {
                for (int x = 0; x < rsize; x++) //���� ����
                {
                    vector<pair<int, int>> P;
                    for (int y = 0; y < csize; y++) //���� ����
                    {
                        if (a[y][x] == 0)
                            continue;
                        visit[a[y][x]]++; //�󵵼� ++�����ֱ�.
                        m[a[y][x]] = visit[a[y][x]];
                        a[y][x] = 0; //���� �ְ� �ǽð����� 0���� �ʱ�ȭ����.
                    }
                    for (auto iter = m.begin(); iter != m.end(); iter++)
                    {
                        P.push_back(make_pair(iter->second, iter->first));
                    }

                    for (int i = 0; i < P.size(); i++)
                    {
                        for (int j = i + 1; j < P.size(); j++)
                        {
                            if (P[i].first > P[j].first) //�󵵼��� ���� ������� ����
                            {
                                swap(P[i], P[j]);
                            }
                            else if (P[i].first == P[j].first) // �󵵼��� ������ ���ڸ� ���ؼ� ������������ ����
                            {
                                if (P[i].second > P[j].second)
                                {
                                    swap(P[i], P[j]);
                                }
                            }
                        }
                    }
                    int idx = 0;
                    if (Col < P.size() * 2) //������ ���� ũ��� pair�� ũ�� * 2��.
                    {
                        Col = P.size() * 2;
                    }
                    if (Col > 100) //���� 100�� �ѱ�ٸ� 100���ķδ� ©����.
                        Col = 100;
                    col = Col;
                    for (int k = 0; k < P.size(); k++) //����,�󵵼� ������� �迭�� �־���.
                    {
                        a[idx][x] = P[k].second;
                        idx++;
                        a[idx][x] = P[k].first;
                        idx++;
                    }
                    m.clear();            // map����.
                    visit.assign(101, 0); // visit�迭 ����.
                }
                Cnt++;
                if (a[r - 1][c - 1] == k) //���� ���� ã�Ҵٸ� �ʸ� ����ϰ� �ݺ��� Ż��
                {
                    cout << Cnt;
                    break;
                }
            }
        }
    }
}
void makeary(int row, int col)
{
    int num;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> num;
            a[i][j] = num;
        }
    }
}
bool flag(int a, int b) // a�� �� , b�� ��
{
    if (a >= b)
        return true;
    else
        return false;
}