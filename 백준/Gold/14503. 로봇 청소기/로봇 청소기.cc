#include <iostream>
using namespace std;
int N,M,R,C,D,Result;
int Map[51][51];
bool Select[51][51];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void Input()
{
    cin>>N>>M;
    cin>>R>>C>>D;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>Map[i][j];
        }
    }
    Select[R][C]=true;
}
void DFS(int x,int y,int d,int result)
{
    for(int i=0;i<4;i++)
    {
        int nd=(d+3-i)%4;
        int nx=x+dx[nd];
        int ny=y+dy[nd];
        if(nx<0||ny<0||nx>=N||ny>=M||Map[nx][ny]==1)
        {
            continue;
        }
        if(Map[nx][ny]==0&&!Select[nx][ny])
        {
            Select[nx][ny]=true;
            DFS(nx,ny,nd,result+1);
        }
    }
    int backd=d+2<4?d+2:d-2;
    int backx=x+dx[backd];
    int backy=y+dy[backd];
    if(backx>=0&&backy>=0&&backx<=N&&backy<=M)
    {
        if(Map[backx][backy]==0)
        {
            DFS(backx,backy,d,result);
        }
        else
        {
            cout<<result<<'\n';
            exit(0);
        }
    }
}
int main(void){
    
    Input();
    DFS(R,C,D,1);
}