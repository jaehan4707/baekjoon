#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int h, w; // h세로, w 가로
vector<int> rain;
int main()
{
    cin >> h >> w;
    rain.resize(w, 0);
    for (int i = 0; i < w; i++)
    {
        cin >> rain[i];
    }
    int total =0;
    for(int i=0;i<w; i++){ 
        int left = 0,right = 0;
        for(int j=0; j<i; j++){ //기준점의 왼쪽방햐엥서 가장 높은 기둥의 높이 구하기
            left =max(left,rain[j]);
        }
        for(int j=w-1; j>i; j--){ //기준점의 오른쪽방향에서 가장 높은 기둥의 높이 구하기
            right = max(right,rain[j]);
        }
        //다 돌면 기준점마다 왼쪽방향에서 가장 큰값, 오른쪽 방향에서 가장 큰 값을 뽑아냄.
        if(min(left,right)-rain[i]>=0){ //값이 0보다 크다면 담을수 있다는 뜻임..
            total+=min(left,right)-rain[i]; //왼쪽,오른쪽중 더 낮은 높이의 기둥만큼 물이 고임.
        }
    }
    cout<<total<<endl;
}