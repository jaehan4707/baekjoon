#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int t,n,p,c,node1,node2;
map<int,int>m;
void search(vector<int>tree[],int first, int depth);
void second_search(vector<int>tree[],int first, int depth);
int main(){
    cin>>t;
    for(int test = 0; test<t; test++){
        cin>>n;
        vector<int>tree[n+1];
        for(int node= 0; node<n-1; node++){ //n-1개 까지 입력받음.
            cin>>p>>c; // 부모 -> 자식 순으로 입력받음.
            tree[c].push_back(p); 
        }
        cin>>node1>>node2; //node1과 node2의 공통조상을 찾아야함.
        m.insert(make_pair(node1,0));
        search(tree,node1,0);
        second_search(tree,node2,0);
        m.clear();
    }
}
void search(vector<int>tree[],int first, int depth)
{
    if(tree[first].size()==0) //만약 더이상 부모가 없다면 종료함.
        return;
    int parent = tree[first][0];
    m.insert(make_pair(parent,depth+1));
    if(m.find(node2)!=m.end()) //node2가 부모라면 가장 가까운 조상은 node2이기 때문에 출력하고 종료함.
        cout<<node2<<endl;
    else
        search(tree,parent,depth+1);
}
void second_search(vector<int>tree[],int first, int depth)
{
    if(tree[first].size()==0) //더이상 부모가 없음.
        return;
    int parent = tree[first][0];
    if(m.find(parent)!=m.end()){ //부모를 찾는 과정에서 map에 있는 원소를 만난다면 그 즉시 출력하고 종료.
    //거꾸로 올라가기에 만나면 그 부모가 가장 가까운 부모가 될 수 밖에 없음.
        cout<<parent<<endl;
        return;
    }
    second_search(tree,parent,depth+1);
}