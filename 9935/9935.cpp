/* 9935 ���4 ���ڿ� ����
���� ó���� �ϴ� ����� ���ڿ� ó�� ���� �������� ���ؼ� �ϴ°� --> �ð��ʰ��� ��.
�� �ð��ʰ��� ����? O(n[���ڿ�����]) *O(��ź����) ��?
��� �ؾ��ұ�?

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
    // cout<<str.size()<<endl<<bomb.size();

    for (int i = 0; i < str.length(); i++) //���ڿ��� ���ϴٰ� ��ź ������ ��Ʈ����.
    {

        s.push_back(str[i]);
        //�� �Է¹��� ���ڿ��� ũ�Ⱑ ��ź�� ���̺��� �۾ƾ��ϴ°�? �׷���
        if (s.size() >= bomb.size()) //�۴ٸ� ���߽�ų ������ �ճ�? ����.
        {
            bool flag = true;
            /*
            if(s[s.size()-1]==bomb[bomb.size()-1]) //���� ��ź�� �ɷǴٸ� ��ź�� ���̸�ŭ ���ش�.
            {
                //cout<<s[s.size()-1]<<endl;
                for(int j=0; j<bomb.size();j++)
                {
                    if(s[s.size()-bomb.size()+j]==bomb[j]) //���ڿ��� ������ ��ź�� ���̸�ŭ ���ص� �������� ���ؼ� ��ź�� �ִ��� ������ üũ��.
                    {
                        cout<<"����ã������� "<<s[s.size()-bomb.size()+j];
                        flag=false;
                        break;
                    }
                    /*ó�� § �ڵ�
                    {
                        if(s[s.size()-1-bomb.size()+j]==bomb[j])  //�̷����ϸ� 4�� �ƴ� c�� �˻��ϰԵ�.
                        {
                            flag=false;
                            break;
                        }
                    }
                }
            }
            */
            for (int j = 0; j < bomb.size(); j++)
            {
                if (s[s.size() - bomb.size() + j] != bomb[j])
                {
                    flag = false;
                    break;
                }
            }
            // flag��  true�� ���� �Ǹ��������ڰ� ��ź�� �������� �������� �˻��ؼ� ��ź�� �����⿡ ��Ʈ��������.
            if (flag == true)
            { //��ź�� �������� �ش��ϴ� �ε������� ���ش�.
                for (int k = 0; k < bomb.size(); k++)
                {
                    // cout << "���� ���� ���°� " << s[s.size() - 1];
                    s.pop_back();
                }
                // cout << endl;
            }
        }
    }
    if (s.size() == 0)
    {
        cout << "FRULA";
    }
    else
    { //��� ���� ����ϱ�
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i];
        }
    }
}
