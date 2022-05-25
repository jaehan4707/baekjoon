#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
vector<int> solution(vector<vector<string>>places);
int main()
{
    vector<vector<string>>ary;
    vector<int>a;
    ary= { {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},{"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};
    a=solution(ary);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    
}
vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;
    bool flag;
    vector<string> str;
    vector<pair<int, int>> p;
    pair<int, int> Y;
    map<pair<int, int>, int> X;
    for (int i = 0; i < places.size(); i++)
    {
        flag = true;
        for (int j = 0; j < places.size(); j++) //���پ� ����
        {
            str.push_back(places[i][j]);
            // PoooP �̰� �״����� �̰�
        }

        /*
        for(int k=0; k<str.size();k++)
        {
            cout<<str[k]<<endl;
        }
        */
        // cout<<str.size()<<endl; str.size=5
        //ù �� �� ����. ���⼭ �Ѳ����� �ذ�����.
        for (int x = 0; x < str.size(); x++) //5*5 ���ǽ��� �ְ�
        {
            for (int y = 0; y < str.size(); y++)
            {
                if (str[x][y] == 'P')
                {
                    p.push_back(make_pair(x, y));
                }
                else if (str[x][y] == 'X')
                {
                    X.insert(make_pair(make_pair(x, y), 0));
                }
            }
        }
        /*
        if(i==4) //p �ߵ�.
        {
            for(int k=0; k<p.size();k++)
            {
                cout<<p[k].first<<" "<<p[k].second<<endl;
            }
        }

        if(i==4) //X �ߵ�.
        {
            for(auto iter=X.begin(); iter!=X.end();iter++)
            {
                cout<<iter->first.first<<" "<<iter->first.second<<endl;
            }
        }
        */
        if (p.size() == 0) //����� ���� ��
        {
            flag = true;
            answer.push_back(1);
            X.clear();
            p.resize(0);
            str.resize(0);
            continue;
        }
        for (int a = 0; a < p.size(); a++)
        {
            for (int b = a + 1; b < p.size(); b++)
            {
                if (abs(p[a].first - p[b].first) + abs(p[a].second - p[b].second) > 2) //2�� ������ ���� �ʿ䰡 ����.
                {
                    continue;
                }
                else if (abs(p[a].first - p[b].first) + abs(p[a].second - p[b].second) == 1) //1�̸� ��Ƽ���� ������������.
                {
                    flag = false; //�Ÿ� �α⸦ ��Ű�� ����.
                }
                else if (abs(p[a].first - p[b].first) + abs(p[a].second - p[b].second) == 2) //2�� ���̿� ��Ƽ���� �־����.
                {
                    if (p[a].first == p[b].first) //���� ���϶��� �� ���̿� �־����.
                    {
                        int idx = (p[a].second + p[b].second) / 2;
                        //p[a].second = idx;
                        Y = make_pair(p[a].first, idx);
                        // map���� ��Ƽ���� �� ��ǥ�� size������.
                        if (X.find(Y) == X.end()) //��Ƽ���� ��ġ�� p[a].first�� idx�� �Ǿ���. ã�����Ѱ��  X.end()�� ��ȯ
                        {
                            flag = false; //��Ƽ���� ���ٸ� false��ȯ
                            break;
                        }
                    }
                    else if (p[a].second == p[b].second) //���� ���϶��� �� ���̿� �־����.
                    {
                        int idx = (p[a].first + p[b].first) / 2;
                        //p[a].first = idx;
                        Y = make_pair(idx, p[a].second);
                        if (X.find(Y) == X.end()) //������
                        {
                            flag = false;
                            break;
                        }
                    }
                    else
                    {
                        int cnt = 0;
                        int Min_row = min(p[a].first, p[b].first);
                        int Max_row = max(p[a].first, p[b].first);
                        int Min_col = min(p[a].second, p[b].second);
                        int Max_col=  max(p[a].second, p[b].second);
                        for (int k = Min_row; k <= Max_row; k++)
                        {
                            for (int z = Min_col; z <=Max_col; z++)
                            {
                                if (str[k][z] == 'X')
                                {
                                    cnt++;
                                }
                            }
                        }
                        if (cnt != 2)
                            flag = false;
                        cnt = 0;
                    }
                }
            }
        }
        X.clear();
        p.resize(0);
        str.resize(0);
        if (flag == false)
            answer.push_back(0);
        else
            answer.push_back(1);
    }
    return answer;
}
// p �ߵ��� x�ߵ���
// cout<<X.size()<<endl;
