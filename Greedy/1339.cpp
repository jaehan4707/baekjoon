// ���� 1339 ���4 �ܾ����
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
using namespace std;
int n;
vector<string> voca;
vector<int> bulk;
vector<pair<int, char>> p;
map<char, int> m;
vector<string> math;
vector<string> ans_string;
bool comp(int a, int b)
{
    return a > b;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        voca.push_back(s);
        bulk.push_back(voca[i].size()); //�Է¹��� ������ ���̸� �迭�� ������.
    }
    for (int i = 0; i < n; i++) //���ڿ��� ũ����� ��� �迭�� ����.�̷��� �迭�� ù ���Ұ� ���� �� ���ڿ��ϰ���.
    {
        for (int j = i + 1; j < n; j++)
        {
            if (bulk[i] < bulk[j])
            {
                swap(bulk[i], bulk[j]);
                swap(voca[i], voca[j]);
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        string s = voca[i];
        voca[i].erase();
        int Size = bulk[0] - bulk[i]; //���� �� ���ڿ��� �������� �� ���ڿ����� ���̸�ŭ �� ������ �������.
        // cout<<Size<<endl;
        int idx = 0;
        while (idx != Size)
        {
            // cout<<1<<endl;
            voca[i] += "a"; //�ƹ����ڳ� ��������. ������ �Է¹��ڴ� �빮�ڶ� �ҹ��ڴ� �������!
            idx++;
        }
        voca[i] += s; //������ ������ ���ڿ� �ϼ�
    }
    int Max_size = voca[0].size(); //���� �� ���ڿ��� ���̸� ������ �����ص�. ��� �Է��ϱ� ������.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < Max_size; j++)
        {
            p.push_back(make_pair(pow(10, Max_size - j - 1), voca[i][j]));
            //�� ���ں��� ��ġ�� �ڸ��� 10�� ������ ��Ÿ��. ���� ��� ABCDE�� A�� 10�� 4��, B�� 10�� 3�� �̷���..
        }
    }
    sort(p.begin(), p.end());
    // pair �� first�� �ڸ���, second�¹���
    // map�� ù������ ����, second�� ����
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i].second == 'a') //���� �ӽ÷� ������� �����̸� �Ѿ.
        {
            continue;
        }
        else
        {
            if (m.find(p[i].second) == m.end()) //ó�� map�� �ִ´ٸ� �׳� �� ���ڰ� ������ ���ڸ� �־���.
            {
                m.insert(make_pair(p[i].second, p[i].first));
            }
            else
            { //ã�Ѵٸ�? ���� ������ ���ڿ� ������. EX) ABBCE �� B�� 1000�� 100�� ��Ÿ��. ���� map���� 1100�� ����Ǿ���.
                int value = m.find(p[i].second)->second;
                m[p[i].second] = value + p[i].first;
            }
        }
    }
    vector<pair<int, char>> result;
    // result�ȿ� �� ���ڿ� �� ���ڰ� ǥ���ϴ� ���� �־���. EX) A 10000, B 1010
    for (auto iter = m.begin(); iter != m.end(); iter++)
    {
        result.push_back(make_pair(iter->second, iter->first));
    }
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = i + 1; j < result.size(); j++)
        {
            if (result[i].first < result[j].first) //�ڸ����� ū ������� ������.
            {
                swap(result[i], result[j]);
            }
        }
    }
    m.clear();
    //���ڿ��� ���� ���ڷ� �����ؾ���.
    int answer = 9; //�� ���ĺ��� 0~9������ ���ڸ� ǥ���� �� ����. �켱������ ���� ������� 9,8,7 ... �̷��� �Ҵ���.
    for (int i = 0; i < result.size(); i++)
    {
        if (m.find(result[i].second) == m.end()) //�� ���ĺ��� ���ڸ� �־���. 9~0
        {
            m.insert(make_pair(result[i].second, answer));
            answer--; //�ѹ� �־��� ���ڴ� ���ֱ� ������ ���ҽ�����.
        }
    }
    for (int i = 0; i < n; i++)
    {
        string s;
        for (int j = 0; j < Max_size; j++)
        {
            int num = m.find(voca[i][j])->second;
            s += to_string(num);
        }
        ans_string.push_back(s);
    }
    int sum = 0;
    for (auto a : ans_string)
    {
        int num = stoi(a);
        sum += num;
    }
    cout << sum;
}