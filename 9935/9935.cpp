/* 9935 ���4 ���ڿ� ����
���� ó���� �ϴ� ����� ���ڿ� ó�� ���� �������� ���ؼ� �ϴ°� --> �ð��ʰ��� ��.
�� �ð��ʰ��� ����? O(n[���ڿ�����]) *O(��ź����) ��?
��� �ؾ��ұ�?
---���߸� ..,
���� �� ���߹��ڿ��� ���ԵǾ��ִ� ���ڿ��� ������ ������ߵȴٰ� ���������� �� ���߹��ڿ� ��ü�� ����°��̾���.
�׷��� Ʋ�ȴ�.. �ϳ��ϳ� ���ؼ� ���m���ϱ� Ʋ����,.,
���� ��� c4�� �ִٸ� ca4�� ������ �̰� ������� �ǵ� �� �ڵ�δ� ������̴�. �׷��� Ʋ�����̾��� ���� �ǵ��� ���ٴ�� �ϴ� �翬�� �ð��ʰ��� ���°��̰�,,
������ ������.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;
string str, bomb;
vector<char> s;
string answer;
int idx = 0;
int main()
{
    cin >> str >> bomb;
    for (int i = 0; i < str.length(); i++)
    { //���ڿ��� ���ϴٰ� ��ź ������ ��Ʈ����.
        s.push_back(str[i]);
        //�� �Է¹��� ���ڿ��� ũ�Ⱑ ��ź�� ���̺��� �۴ٸ�? ���߽�ų �ʿ䰡 ����.
        if (s.size() >= bomb.size())
        {
            bool flag = true;
            if (s[s.size() - 1] == bomb[bomb.size() - 1])
            { //���� ��ź�� �ɷǴٸ� �� ���� ��ź�� ���� ���� ���ڿ��� �˻�����.
                for (int j = 0; j < bomb.size(); j++)
                {
                    if (s[s.size() - bomb.size() + j] != bomb[j])
                    {                 //���ڿ��� ������ ��ź�� ���̸�ŭ ���ص� �������� ���ؼ� ��ź�� �ִ��� ������ üũ��.
                        flag = false; //���߸��Ұ�� false �����Ұ�� true
                        break;
                    }
                }
                if (flag == true)
                { //��ź�� �������� �ش��ϴ� �ε������� ���ش�.
                    for (int k = 0; k < bomb.size(); k++)
                    {
                        s.pop_back();
                    }
                }
            }
        }
    }
    if (s.size() == 0)
    { //���� size�� 0�̶�� ��� ���ڿ��� ���ߵȰ�.
        cout << "FRULA";
    }
    else
    {
        for (auto v : s)
        {
            cout << v;
        }
    }
}