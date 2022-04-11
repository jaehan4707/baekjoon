/*
트리 만들기
n개의 노드와 m개의 리프노드를 만들어 주면됨.
그럼 m, n-m으로 나뉜다.
*/
#include <iostream>
#include <vector>

using namespace std;
typedef struct node* node_ptr;
struct node
{
    int key;
    node_ptr left;
    node_ptr right;
};
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m - 1; ++i)
        cout << i << ' ' << m - 1 << '\n';
    for (int i = m - 1; i < n - 1; ++i)
        cout << i << ' ' << i + 1 << '\n';
}