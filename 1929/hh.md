저번 게시물에서는 외판원 순회 문제를 동적 계획법을 이용해서 풀어보았다.

이번에는 **Branch & Bound(분기한정법)**을 이용해서 풀 예정이다.

문제의 목표는 동일하게 출발점에서 모든 노드를 각 한 번씩 방문하고 다시 출발점으로 되돌아오는 최소한의 비용을 가지는 경로를 찾는 것이다.

> 최고 우선 검색을 사용하기 위해서 각 마디의 한계값을 구할 수 있어야 한다.

> 0-1 배낭 채우기 문제에서는 총무게가 W를 넘지 않도록 하면서 이익을 최대로 하는 게 목표였기 때문에, 주어진 마디에서부터 뻗어나가서 얻을 수 있는 이익의 상한을 계산하였다. 그리고 어떤 마디에서 당시 최대 이익보다 한계값이 큰 경우에 그 마디를 유망하다고 판단했다.

> 외판원 문제에서는 주어진 마디에서부터 뻗어나가서 얻을 수 있는 여행경로 길이의 하한을 구할 필요가 있다.  
> 그리고 당시 최소경로길이보다 한계값이 작은 경우에 그 마디를 유망하다고 한다.   
> 한계값은 다음과 같이 구한다.

**어떤 여행경로라도 그 정점에서 가장 짧은 이음선의 길이들을 선택한 합이 여행경로 길이의 하한일 것이다.**

1.  v1에서 자기 자신을 제외한 가장 짧은 가중치 --> 3
2.  v2에서 자기 자신을 제외한 가장 짧은 가중치 --> 7
3.  v3에서 자기 자신을 제외한 가장 짧은 가중치 --> 4
4.  v4에서 자기 자신을 제외한 가장 짧은 가중치 --> 2
5.  v5에서 자기 자신을 제외한 가장 짧은 가중치 --> 4

여행경로 길이의 하한값은 21이다.

**21인 여행경로가 무조건 있다는 뜻은 아니다. 하지만 이 21보다 더 짧은 경로는 있을 수 없다는 뜻이다.**

[##_Image|kage@uoEm2/btrDoUJeaw3/tm6hOJXqDhk00PdiZtkOg0/img.png|CDM|1.3|{"originWidth":387,"originHeight":323,"style":"alignLeft"}_##]

V1에서 출발해서 V2를 방문한 경우

1.  V1->V2의 가중치는 14이다.
2.  여기서 V2에서 갈 수 있는 선택지는 자기 자신과 V1을 제외한 모든 곳이다.
    1.  V2=\[14,0,7,8,7\] 중에서 가장 작은 값인 7을 선택할 것이다.
3.  V3, V4, V5는 V2와 자기 자신을 방문하지 못한다.  
    1.  V3=\[4,5,0,7,16\] 중에서 4를 가진다.
    2.  V4=\[11,7,9,0,2\] 중에서 2를 가진다.
    3.  V5=\[18,7,17,4,0\] 중에서 4를 가진다.
4.  이렇게 된다면 여행경로 길이의 하한은 14+7+4+2+4 = 31이다.

이런 식으로 각 방문한 정점들을 빼고 여행경로 길이의 하한을 구해줄 수 있을 것이다.

이제 이렇게 구해준 한계값으로 가지치기를 해 볼 것이다.

아래 그림은 각 방문한 정점마다 bound값을 구한 상태이다.

[##_Image|kage@beQ44i/btrDEjBGQ7c/LpPku21cD65Tu4SxNiUX1k/img.png|CDM|1.3|{"originWidth":1121,"originHeight":561,"style":"alignLeft"}_##]

1.  root를 방문한다.
    1.  bound값을 계산하면 21이 된다.
2.  root의 자식들을 방문한다.
    1.  \[1,2\] = 31
    2.  \[1,3\]=22
    3.  \[1,4\]=30
    4.  \[1,5\]=42
3.  그중에서 bound값이 가장 작고 확장하지 않은 마디인 \[1,3\]의 자식 노드들을 방문한다.  
    1.  \[1,3,2\]=22
    2.  \[1,3,4\]=27
    3.  \[1,3,5\]=39
4.  그 중에서 bound값이 가장 작고 확장하지 않은 마디인 \[1,3,2\]의 자식노드들을 방문한다.
    1.  여기서 만약 트리의 깊이가 n-1이라면 길이를 결정해준다.
    2.  \[1,3,2,4\]를 방문하면 마지막 경로는 자동으로 정해지기 때문에 그다음 깊이를 탐색할 필요 없이 \[1,3,2,4,5,1\]의 경로 길이를 구해준다.
        1.  \[1,3,2,4,5,1\]=37
        2.  \[1,3,2,5,4,1\]=31
    3.  여기서 구해준 경로의 길이 중에서 가장 작은 것을 minlength로 두고 트리의 bound값이 minlength보다 작은 곳들은 유망하지 않기 때문에 방문에서 제외된다.
5.  위 과정을 반복함.
6.  결과는 \[1,4,5,2,3,1\]이 최적 경로가 되고 그 길이의 합은 30이 된다.

> 외판원 문제를 분기 한정으로 풀면 방문 횟수에서 엄청난 효율성을 보인다.

구현

1.bound값이 작은 것부터 확장해야 하기 때문에 우선순위 큐를 사용해서 bound의 오름차순으로 정렬한다.

```
struct cmp
{
    bool operator()(node_pointer a, node_pointer b) // bound가 작은걸 top으로 두고싶음.
    {
        return a->bound > b->bound;
    }
};
priority_queue<node_pointer, vector<node_pointer>, cmp> pq; // path,bound값으로 나눠야함.
```

2\. 구조체 node 설정

```
typedef struct node *node_pointer;
typedef struct node
{
    int level;
    vector<int> path;
    int bound;
} nodetype;
```

3\. 여행경로 길이의 하한을 구하는 Bound함수

```
int Bound(node_pointer V)
{
    int lower = length(V->path);
    for (int i = 1; i <= G; i++)
    {
        if (hasOutgoing(i, V->path))
            continue;
        int min = INF;
        for (int j = 1; j <= G; j++)
        {
            if (i == j)
                continue;
            if (j == 1 & i == V->path[V->path.size() - 1])
                continue;
            if (hasIncoming(j, V->path))
                continue;
            if (min > graph[i][j])
                min = graph[i][j];
        }
        lower += min;
    }
    return lower;
}
```

4\. 여행경로의 실제 길이를 구하는 length함수

```
int length(vector<int> &path)
{
    vector<int>::iterator it;
    int len = 0;
    for (it = path.begin(); it != path.end(); it++)
    {
        if (it != path.end() - 1)
            len += graph[*it][*(it + 1)];
    }
    return len;
}
```

5\. 올 바른 경로인지 검사하는 correct path함수

```
bool correct_path(node_pointer a) // 1이면 경로가 있고 0이면 경로가 없다.
{
    bool flag;
    flag = true;
    for (int x = 1; x < a->path.size(); x++)
    {
        if (graph[a->path[x - 1]][a->path[x]] == INF) //경로가 없다면
        {
            flag = false;
        }
    }
    return flag;
}
```

6\. 마지막 경로는 자동으로 정해줘야 하기 때문에 방문 경로를 검사해주는 함수 inIn

```
bool isIn(int i, vector<int> &path) // path안에 i가 있냐 없냐를 따짐.
{
    vector<int>::iterator it;
    // cout<<1;
    bool opt = true;
    for (int j = 0; j <= path.size() - 1; j++)
    {
        if (i == path[j]) //같은게 있으면
            return false;
    }
    // cout<<"opt는" << opt<<endl;
    return true;
}
```

7\. 적절한 방문인지 검사하는 함수

```
bool hasOutgoing(int v, vector<int> &path)
{
    vector<int>::iterator it;
    for (it = path.begin(); it != path.end() - 1; it++)
        if (*it == v)
            return true;
    return false;
}

bool hasIncoming(int v, vector<int> &path)
{
    vector<int>::iterator it;
    for (it = path.begin() + 1; it != path.end(); it++)
        if (*it == v)
            return true;
    return false;
}
```

전체 코드

```
/*
각 정점에 대한 bound값이 있음. 그 값은 바로 그 정점에서 최소비용으로 갈 수있는 경로의 가중치
그렇게 정점마다 bound값을 뽑아서 다 더 하면 그 값이 여행경로 길이의 하한일것이다.
이 길이의 합과 같은 여행경로가 무조건 있다는 뜻은 아니고 이 보다 더 짧은 경로가 있을 수 없다는 뜻이다.
여행경로의 하한은 이미 뽑힌 값은 제외하고 그 출발지에 따른 bound값이다.
출발지에서 부터 하나씩 방문해서 bound값이 가장 작고 아래까지 탐색을 안한 것ㅂ ㅜ터 탐색함.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#define INF 999
using namespace std;
int G, v;
vector<vector<int>> graph;
vector<int> bound;
typedef vector<int> ordered_set;
typedef struct node *node_pointer;
typedef struct node
{
    int level;
    vector<int> path;
    int bound;
} nodetype;
int length(vector<int> &path);
int Bound(node_pointer V);
node_pointer create_node(int Level, vector<int> &path);
bool hasIncoming(int v, vector<int> &path);
bool hasOutgoing(int v, vector<int> &path);
void travel2(vector<int> &opttour, int &minlength);
bool isIn(int i, vector<int> &path);
bool correct_path(node_pointer a);
vector<int> seq;
int shortpath = INF;
int start = 1;
struct cmp
{
    bool operator()(node_pointer a, node_pointer b) // bound가 작은걸 top으로 두고싶음.
    {
        return a->bound > b->bound;
    }
};
int main()
{
    cin >> G >> v;
    graph.resize(G + 1, vector<int>(G + 1, INF));
    bound.resize(G + 1);
    for (int i = 0; i < v; i++)
    {
        int s, f, w;
        cin >> s >> f >> w;
        graph[s][f] = w;
    }
    for (int i = 1; i <= G; i++)
    {
        graph[i][i] = 0;
    }
    travel2(seq, shortpath);

    cout << shortpath << endl;
    for (int i = 0; i < seq.size(); i++)
    {
        if (i < seq.size() - 1)
            cout << seq[i] << " ";
        else
            cout << seq[i];
    }
}
int length(vector<int> &path)
{
    vector<int>::iterator it;
    int len = 0;
    for (it = path.begin(); it != path.end(); it++)
    {
        if (it != path.end() - 1)
            len += graph[*it][*(it + 1)];
    }
    return len;
}
int Bound(node_pointer V)
{
    int lower = length(V->path);
    for (int i = 1; i <= G; i++)
    {
        if (hasOutgoing(i, V->path))
            continue;
        int min = INF;
        for (int j = 1; j <= G; j++)
        {
            if (i == j)
                continue;
            if (j == 1 & i == V->path[V->path.size() - 1])
                continue;
            if (hasIncoming(j, V->path))
                continue;
            if (min > graph[i][j])
                min = graph[i][j];
        }
        lower += min;
    }
    return lower;
}
bool hasOutgoing(int v, vector<int> &path)
{
    vector<int>::iterator it;
    for (it = path.begin(); it != path.end() - 1; it++)
        if (*it == v)
            return true;
    return false;
}

bool hasIncoming(int v, vector<int> &path)
{
    vector<int>::iterator it;
    for (it = path.begin() + 1; it != path.end(); it++)
        if (*it == v)
            return true;
    return false;
}

void travel2(vector<int> &opttour, int &minlength)
{
    priority_queue<node_pointer, vector<node_pointer>, cmp> pq; // path,bound값으로 나눠야함.
    node_pointer a, b;
    a = (node_pointer)malloc(sizeof(nodetype));
    b = (node_pointer)malloc(sizeof(nodetype));

    minlength = INF;
    b->level = 0;

    b->path.push_back(1);
    b->bound = Bound(b);

    cout << b->level << " " << b->bound << " ";
    for (int i = 0; i < b->path.size(); i++)
    {
        if (i < b->path.size() - 1)
            cout << b->path[i] << " ";
        else
            cout << b->path[i];
    }
    cout << endl;
    pq.push(b);
    while (!pq.empty())
    {
        b = pq.top();
        pq.pop();
        if (b->bound < minlength)
        {
            // a->level = b->level + 1; // a를 b의 자식노드로 놓음.
            for (int i = 2; i <= G; i++)
            {
                if (isIn(i, b->path) == 0) // isIn값이 0이면 i가 경로에 이미 있다는 소리고 1이면 i가 경로에 없다는 소리다.
                {
                    continue; // 만약 i가 b의 경로에 있다ㅕㅁㄴ?
                }
                a = create_node(b->level + 1, b->path); //여가서 5일때 터짐.
                a->level = b->level + 1;
                a->path = b->path;
                a->bound = 0;
                a->path.push_back(i);
                if (a->level == G - 2) //마지막 정점일때 a의 레벨은 0부터 1,2,3,4 G=5 3개를 방문하면 나머지 하나는 정해짐
                {
                    for (int k = 2; k <= G; k++) // 1부터 k까지해서 간경로는 재끼고 안간경로를  당연히 가야하므로 푸쉬해줌.
                    {
                        if (isIn(k, a->path) == 0) // 0이면 경로 x 1이면 경로 o
                        {
                            continue;
                        }
                        else
                        {
                            a->path.push_back(k);
                        }
                    }
                    a->path.push_back(1); //마지막은 1로 돌아가야함.
                    if (length(a->path) < minlength)
                    {
                        minlength = length(a->path);
                        ;
                        opttour.assign(a->path.begin(), a->path.end());
                    }
                    a->bound = Bound(a);
                    if (correct_path(a)) //여기도 경로가 없는거였다면 구분해줘야함. 0이면 없고 1이면 잇음
                    {
                        cout << a->level << " " << a->bound << " ";
                        for (int x = 0; x < a->path.size(); x++)
                        {
                            if (x < a->path.size() - 1)
                                cout << a->path[x] << " ";
                            else
                                cout << a->path[x];
                        }
                        cout << endl;
                    }
                    else
                    {
                        a->bound = Bound(a);
                        cout << a->level << " "
                             << "INF"
                             << " ";
                        for (int x = 0; x < a->path.size(); x++)
                        {
                            if (x < a->path.size() - 1)
                                cout << a->path[x] << " ";
                            else
                                cout << a->path[x];
                        }
                        cout << endl;
                    }
                }
                else //탐색지가 자동으로 안정해지는경우
                {
                    bool flag = true;
                    if (correct_path(a)) //이상한 경로가 아니라면 그대로 bound값을 넣어줌.
                    {
                        a->bound = Bound(a);
                        cout << a->level << " " << a->bound << " ";
                        for (int x = 0; x < a->path.size(); x++)
                        {
                            if (x < a->path.size() - 1)
                                cout << a->path[x] << " ";
                            else
                                cout << a->path[x];
                        }
                        cout << endl;
                    }
                    else //이상한 경로라면 bound를 넣어줌.
                    {
                        a->bound = Bound(a);
                        cout << a->level << " "
                             << "INF"
                             << " ";
                        for (int x = 0; x < a->path.size(); x++)
                        {
                            if (x < a->path.size() - 1)
                                cout << a->path[x] << " ";
                            else
                                cout << a->path[x];
                        }
                        cout << endl;
                    }
                    // path가 있는지 없는지 확인 만약 path가 있다면 bound는 bound로 값을 구해주고 아니면 INF를 넣어줌.
                    if (a->bound < minlength) // bound가 초기화 된 minlength보다 작다면 넣어준다.
                        pq.push(a);
                }
            }
        }
    }
}
bool correct_path(node_pointer a) // 1이면 경로가 있고 0이면 경로가 없다.
{
    bool flag;
    flag = true;
    for (int x = 1; x < a->path.size(); x++)
    {
        if (graph[a->path[x - 1]][a->path[x]] == INF) //경로가 없다면
        {
            flag = false;
        }
    }
    return flag;
}
bool isIn(int i, vector<int> &path) // path안에 i가 있냐 없냐를 따짐.
{
    vector<int>::iterator it;
    // cout<<1;
    bool opt = true;
    for (int j = 0; j <= path.size() - 1; j++)
    {
        if (i == path[j]) //같은게 있으면
            return false;
    }
    // cout<<"opt는" << opt<<endl;
    return true;
}
node_pointer create_node(int Level, vector<int> &path)
{
    node_pointer temp = (node_pointer)malloc(sizeof(node) * G);
    //temp->level=Level+1;
    //temp->path=path;
   // temp->bound=0; 
    return temp;
}
```