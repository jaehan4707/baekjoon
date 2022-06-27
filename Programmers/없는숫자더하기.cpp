#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -1;
    int sum = 0;
    for (int i = 0; i <= 9; i++)
    {
        sum += i;
    }
    //0���� 9������ ���� sum�� �����.
    int nsum = 0;
    for (auto m : numbers)
    {
        nsum += m;
    }
    //�־��� numbers �迭�� ���� nsum�� �����.
    //answer�� 0~9������ ���̰� nsum�� numbers �迭�� �� ���� �� ���� ���̰� ���� ������ ���ϰ��̴�.
    answer = sum - nsum;
    return answer;
}