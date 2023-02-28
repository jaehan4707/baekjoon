#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int n,m,c;
int DP[51][51][51][51];
map<pair<int,int>,int> M;
int mod = 1000007;
void funct(int num);
int main(){
    cin>>n>>m>>c;
    int trow,tcol;
    for(int i=1; i<=c; i++){
        cin>>trow>>tcol;
        M.insert(make_pair(make_pair(trow,tcol),i));
    
    }
    for(auto iter = M.begin(); iter!=M.end();iter++){
         cout<<iter->first.first<<" "<<iter->first.second<< " "<<iter->second<<endl;
     }
    for(int i=0; i<=c; i++){
        DP[1][1][0][0]=1;
        funct(i);
        int sum=0;
        for(int k=0; k<51; k++){
            sum+=DP[n][m][i][k];
        }
        cout<<"결과 "<<i<<" "<<sum<<endl;
        //memset(DP,0,sizeof(DP))
    }
    //탐색 시작

}
void funct(int num){

    int game=0,gnum=0;
    for(int i=1; i<=n;i++){ //DP[행][열][오락실수][오락실넘버]
        for(int j=1; j<=m;j++){
            
            if(i==1 && j == 1){ //출발점.
                continue;
            }
            if(i==n && j == m){
                cout<<"도착했습니다"<<game<<" "<<gnum<<endl;
            }
            if(M.find(make_pair(i,j))!=M.end()) //만약 이곳이 오락실이라면?
            { 
                //여기서 비교해야할건 오락실 수가 num을 넘엇느냐?
                //오락실넘버가 증가하는 순서대로 방문햇느냐 이다.
                if(gnum>M.find(make_pair(i,j))->second){ //현재 방문한 오락실의 최고 넘버가 지금 방문할려는 오락실넘버보다 크다면?
                    continue;
                }
                if(game>=num){ //방문한 오락실의 수가 제한숫자보다 높다면?
                    continue;
                }
                //i,j 방문.
                DP[i][j][game+1][M.find(make_pair(i,j))->second]=DP[i-1][j][game][gnum]+DP[i][j-1][game][gnum];
                game++, gnum = M.find(make_pair(i,j))->second;
            }
            else{ //오락실이 아니라면

                DP[i][j][num][gnum]=DP[i-1][j][num][gnum]+DP[i][j-1][num][gnum];
            }
            cout<<i<<" "<<j<<" "<<DP[i][j][num][gnum]<<endl;
        }
    }
}