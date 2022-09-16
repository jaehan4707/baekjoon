/* 2800 ��ȣ ����
��ȣ�� �����ؼ� �����  �ִ� ������ ��� �����
stack�� �ֱ�
����� �ִ�  ����� ���� 2^(��ȣ�Ǽ�)-1�̴�.
���ʿ��� ���� �ڿ� �ִ� ��ȣ�� �����ʿ��� �տ� �ִ� ��ȣ�� �����ش�.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;
stack<char> S;
vector<int> l, r;
vector<char> c;
vector<int> temp;
bool big(int a, int b);
string str;
vector<int> symbol;
vector<pair<int, int>> p;
vector<int> visit;
void check(int i, int Count);
vector<string> answer;
map<string, int> m;
int main()
{
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            symbol.push_back(i);
        }
        else if (str[i] == ')')
        {
            int num = symbol[symbol.size() - 1]; //���� �ֱٿ�  ����� ���ʰ�ȣ�� ó�������� ������ ��ȣ�� ������.
            symbol.pop_back();                   //���ְ�.
            p.push_back(make_pair(num, i));      //�ֱ� ������ġ�� ������ ��ġ�� pair�� �־���
        }
    }
    visit.resize(str.length(), 0);
    check(0, 0);
    for (auto iter = m.begin(); iter != m.end(); iter++)
    {
        cout << iter->first << endl;
    }
    //��ȣ �����Ǵ� ��ġ �־��ֱ� ����. ���� ����� ���� ����ؼ� �����ϸ��.
}
void check(int i, int Count)
{ //
    // cout<<3<<endl;
    if (Count > 0)
    {
        //�ϴ� �־��
        // cout<<3<<endl;
        string s = "";
        for (int j = 0; j < visit.size(); j++)
        {
            if (visit[j] == true)
                continue; // true�� �׶��� ��ȣ ��ġ�� �������� ����.
            else
            {
                s += str[j]; //
            }
        }
        //���⼭ �ߺ��� ���ڿ��� ������ҰŰ��v��.
        m.insert(make_pair(s, 1));
    }
    // cout<<4<<endl;
    for (int k = i; k < p.size(); k++)
    {
        if (visit[p[k].first] == true && visit[p[k].second] == true)
        { //�̹� ����� ��ȣ���
            continue;
        }
        visit[p[k].first] = true;
        visit[p[k].second] = true;
        check(k, Count + 1);
        visit[p[k].first] = false;
        visit[p[k].second] = false;
    }
}