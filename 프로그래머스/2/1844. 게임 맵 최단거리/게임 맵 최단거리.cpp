#include<vector>
#include <string>
#include <queue>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int dist[101][101];
int solution(vector<vector<int>> maps)
{
    int n=maps.size();
    int m=maps[0].size();
    queue<pair<int,int>> q;
    dist[0][0]=1;
    q.push({0,0});
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&ny>=0&&nx<n&&ny<m&&maps[nx][ny]==1&&dist[nx][ny]==0)
            {
                dist[nx][ny]=dist[x][y]+1;
                q.push({nx,ny});
                
            }
        }
    }
    
    if(dist[n-1][m-1]==0) return -1;
    return dist[n-1][m-1];
}