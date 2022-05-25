#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> solution(int rows, int columns, vector<vector<int>> queries);
int main()
{
    vector<vector<int>>a = { {2,2,5,4},{3,3,6,6},{5,1,6,3}};
    solution(6, 6, a);
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    pair<int, int>p;
    pair<int, int>q;
    vector<vector<int>>ary(rows + 1, vector<int>(columns + 1, 0));
    int cnt = 1;
    for (int i = 1; i < rows + 1; i++)
    {
        for (int j = 1; j < columns + 1; j++)
        {
            ary[i][j] = cnt;
            cnt++;

        }
    }
    for (int i = 0; i < queries.size(); i++)
    {
        p = make_pair(queries[i][0], queries[i][1]);
        q = make_pair(queries[i][2], queries[i][3]);
        //p,q 잘들어감.
        int max_row = max(p.first, q.first);
        int min_row = min(p.first, q.first);
        int max_col = max(p.second, q.second);
        int min_col = min(p.second, q.second);
        vector<int>temp;
        // map<int,pair<int,int>>m;
         //copy()
        int Temp1 = ary[min_row][min_col]; //왼 위
        int Temp2 = ary[min_row][max_col]; //오 위
        int Temp3 = ary[max_row][min_col]; //왼 아래
        int Temp4 = ary[max_row][max_col]; //오 아래
        temp.push_back(Temp1);
        temp.push_back(Temp2);
        temp.push_back(Temp3);
        temp.push_back(Temp4);
        // cout<<Temp1<<" "<<Temp2<<" "<<Temp3<<" "<<Temp4<<endl;

        int mini = ary[min_row][min_col];
        for (int a = min_row; a <max_row; a++) //왼쪽 세로
        {
            ary[a][min_col] = ary[a+1][min_col];
            if (mini > ary[a][min_col])
                mini = ary[a][min_col];
        }
        for (int a = max_col; a > min_col; a--)//위쪽 가로
        {
            ary[min_row][a] = ary[min_row][a - 1];
            if (mini > ary[min_row][a])
                mini = ary[min_row][a];
        }
        for (int a = max_row; a > min_row; a--)
        {
            ary[a][max_col] = ary[a - 1][max_col];
            if (mini > ary[a][max_col])
                mini = ary[a][max_col];
        }
        for (int a = min_col; a < max_col; a++)
        {
            ary[max_row][a] = ary[max_row][a + 1];
            if (mini > ary[max_row][a])
                mini = ary[max_row][a];
        }
        //각각 꼭짓점 넣어주기.
        ary[min_row][min_col + 1] = Temp1;
        ary[min_row + 1][max_col] = Temp2;
        ary[max_row - 1][min_col] = Temp3;
        ary[max_row][max_col - 1] = Temp4;
        for (int i = 0; i < temp.size(); i++)
        {
            if (mini > temp[i])
                mini = temp[i];
        }
        answer.push_back(mini);
        temp.resize(0);
        //cout<<mini<<endl;
    }
    return answer;
}