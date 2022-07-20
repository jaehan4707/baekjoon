// 2800 ��ȣ ����
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
string str;
vector<int> symbol;
vector<pair<int, int>> p;
vector<int> visit;
void check(int i, int Count);
map<string, int>m;
int main()
{
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            symbol.push_back(i); //���� ��ȣ�� index�� ����.
        }
        else if (str[i] == ')')
        {
            //���� �ֱٿ� symbol�� �־��� ���� ��ȣ�� index���� ���� ���� ������ ������ ��ȣ�� ���� �����Ǳ� ������ 
            //�׶��� index�� pair�� �־���.
            int num = symbol[symbol.size() - 1];
            symbol.pop_back();
            p.push_back(make_pair(num, i));
        }
    }
    visit.resize(str.length(), 0); //visit�� size�� str�� �����ϰ� �ʱ�ȭ����.
    check(0, 0);
    for (auto iter = m.begin(); iter != m.end(); iter++) //map���� �ڵ����� �������� ���ĵǰ�, first�� ���� �����.
    {
        cout << iter->first << endl;
    }
}
void check(int i, int Count)
{
    if (Count > 0)
    {
        string s = "";
        for (int j = 0; j < visit.size(); j++)
        {
            if (visit[j] == true)
                continue; // true��� ���ڿ��� ����x
            else
            {
                s += str[j]; //���� �����ϰ���� ���� ���ڿ��� ���� �־���.
            }
        }
        m.insert(make_pair(s, 1)); //��ȣ�� �����ϴ��� �ߺ��� ���ڿ��� ������ �����Ƿ�, map�� �����.
    }
    for (int k = i; k < p.size(); k++)
    {
        if (visit[p[k].first] == true && visit[p[k].second] == true) //���� �̹� �ߴ� ����� ����� �Ѿ.
        { //�̹� ����� ��ȣ���
            continue;
        }
        //��ȣ�� �������� ���ϰ� �ʱ�ȭ
        visit[p[k].first] = true;
        visit[p[k].second] = true;
        check(k, Count + 1);
        //��ȣ�� �ٽ� �����ϰ� �ʱ�ȭ
        visit[p[k].first] = false;
        visit[p[k].second] = false;
    }
}