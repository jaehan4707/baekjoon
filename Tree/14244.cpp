/*
Ʈ�� �����
n���� ���� m���� ������带 ����� �ָ��.
�׷� m, n-m���� ������.
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