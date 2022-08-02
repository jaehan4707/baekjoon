#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string>orders;
vector<int>course;
vector<string>result;
vector<string> solution(vector<string> orders, vector<int> course);
int main()
{
    int n, cnum;
    cin >> n;
    orders.resize(n);
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        orders[i] = a;
    }
    cin >> cnum;
    for (int i = 0; i < cnum; i++)
    {
        int num;
        cin >> num;
        course.push_back(num);
    }
    result = solution(orders, course);
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}
vector<string> solution(vector<string> orders, vector<int> course)
{
    //  int size = course.size(); //course��� �ϴ� ���ڿ��� �ɰ�����.
    string a;
    vector<string> answer;
    //subset.resize(orders.size());//�κй��ڿ� ũ��
    for (int y = 0; y < course.size(); y++)
    {
        int idx = 0;
        vector<int>temp;// size ���� temp���� �ٲ������.
        vector<string>subset;
        vector<int>visit;
        temp.resize(20, 0);
        for (int j = 0; j < course[y]; j++)
        {
            temp[j] = 1;
        }
        for (int k = 0; k < orders.size(); k++)
        {
            do {
                for (int i = 0; i < orders[k].size(); i++)
                {
                    if (orders[k].size() < course[y])
                    {
                        continue;
                    }
                    if (temp[i] == 1)
                    {
                        a += orders[k][i];
                    }
                    //���⼭ ���ڿ��� �����������.
                    sort(a.begin(), a.end());
                }
                if (a.length() == course[y])
                    subset.push_back(a);
                a = "";
                //cout << endl;
            } while (prev_permutation(temp.begin(), temp.end())); //orders[0]�� size 2�� ��� ���� ����.
        }
        visit.resize(subset.size());
        if (subset.size() == 0)
            break;
        else
        {
            sort(subset.begin(), subset.end());
        }
        visit[0] = 1;
        string min = subset[0];
        vector<int>max_idx;
        int cnt = 0;
        for (int i = 0; i < subset.size(); i++) //�տ� ���ڶ� �ٸ��� �׶������� ī��Ʈ.�� i�� �����ؼ� �ϱ�
        {
            if (min == subset[i])
            {
                cnt++;
                visit[i] = cnt;
                //max_idx = i;
            }
            else
            {
                visit[i] = 1;
                min = subset[i];
                cnt = 1;
            }
        }
        int max = visit[0];
        for (int i = 0; i < visit.size(); i++)
        {
            if (max < visit[i])
            {
                max = visit[i]; //max�� visit�ּڰ� �̾���
                idx = i;
            }
        }
        if (max != 1) //max�� �� �޴��� ��Ų ��� ��
        {
            for (int i = 0; i < visit.size(); i++)
            {
                if (max == visit[i])
                {
                    max_idx.push_back(i);
                    answer.push_back(subset[i]);
                }
            }
        }
    }
    return answer;
}
