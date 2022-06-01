/*
M�̻� N������ �Ҽ��� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
void Eratos(int, int);

int main()
{

    int m, n;
    cin >> m >> n;

    Eratos(n, m);

    return 0;
}

void Eratos(int n, int m)
{

    bool* PrimeArray = new bool[n + 1];

    for (int i = 2; i <= n; i++)
        PrimeArray[i] = true; //ó���� ��� �Ҽ��� ��

    PrimeArray[1] = false;

    for (int i = 2; i * i <= n; i++)
    { // n�� ��Ʈ����� ������ ���� ��
      //�Ҽ��� �Ǻ��ص� ��
      //������� n�� 120�̸�
      // 11*11>120 �̹Ƿ�
      // 11���� ���� ���� ����鸸 ������ �ȴ�

        if (PrimeArray[i])
        { // PrimeArray[i]�� false�̸�
          // i�� �̹� �Ҽ��� �ƴϹǷ� i�� ��� ���� �Ҽ��� �ƴϰ� �ȴ�
          //�׷��Ƿ� �˻��� �ʿ䵵����
            for (int j = i * i; j <= n; j += i)
            { // i*k(k<i)������ �̹� �˻�Ǿ����Ƿ�
              // j�� ���۰��� i*2���� i*i�� ������ �� �ִ�
                PrimeArray[j] = false;
            }
        }
    }
    for (int i = m; i <= n; i++)
    {
        if (PrimeArray[i])
            cout << i << "\n";
    }
}