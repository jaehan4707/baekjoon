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
        for (int j = 0; j < places.size(); j++) //한줄씩 뽑음
        {
            str.push_back(places[i][j]);
            // PoooP 뽑고 그다음줄 뽑고
        }

        /*
        for(int k=0; k<str.size();k++)
        {
            cout<<str[k]<<endl;
        }
        */
        // cout<<str.size()<<endl; str.size=5
        //첫 줄 다 받음. 여기서 한꺼번에 해결하자.
        for (int x = 0; x < str.size(); x++) //5*5 강의실을 넣고
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
        if(i==4) //p 잘들어감.
        {
            for(int k=0; k<p.size();k++)
            {
                cout<<p[k].first<<" "<<p[k].second<<endl;
            }
        }

        if(i==4) //X 잘들어감.
        {
            for(auto iter=X.begin(); iter!=X.end();iter++)
            {
                cout<<iter->first.first<<" "<<iter->first.second<<endl;
            }
        }
        */
        if (p.size() == 0) //사람이 없을 때
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
                if (abs(p[a].first - p[b].first) + abs(p[a].second - p[b].second) > 2) //2가 넘으면 비교할 필요가 없음.
                {
                    continue;
                }
                else if (abs(p[a].first - p[b].first) + abs(p[a].second - p[b].second) == 1) //1이면 파티션이 있을수가없음.
                {
                    flag = false; //거리 두기를 지키지 않음.
                }
                else if (abs(p[a].first - p[b].first) + abs(p[a].second - p[b].second) == 2) //2면 사이에 파티션이 있어야함.
                {
                    if (p[a].first == p[b].first) //같은 열일때는 행 사이에 있어야함.
                    {
                        int idx = (p[a].second + p[b].second) / 2;
                        //p[a].second = idx;
                        Y = make_pair(p[a].first, idx);
                        // map에서 파티션의 열 좌표가 size여야함.
                        if (X.find(Y) == X.end()) //파티션의 위치는 p[a].first와 idx가 되야함. 찾지못한경우  X.end()를 반환
                        {
                            flag = false; //파티션이 없다면 false반환
                            break;
                        }
                    }
                    else if (p[a].second == p[b].second) //같은 행일때는 열 사이에 있어야함.
                    {
                        int idx = (p[a].first + p[b].first) / 2;
                        //p[a].first = idx;
                        Y = make_pair(idx, p[a].second);
                        if (X.find(Y) == X.end()) //없으면
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
// p 잘들어갔고 x잘들어갔고
// cout<<X.size()<<endl;
