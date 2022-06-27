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
    //0부터 9까지의 합은 sum에 저장됨.
    int nsum = 0;
    for (auto m : numbers)
    {
        nsum += m;
    }
    //주어진 numbers 배열의 합은 nsum에 저장됨.
    //answer은 0~9까지의 합이고 nsum은 numbers 배열의 합 따라서 두 값의 차이가 없는 원소의 합일것이다.
    answer = sum - nsum;
    return answer;
}