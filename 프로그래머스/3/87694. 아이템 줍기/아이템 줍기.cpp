#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int map[101][101];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    int maxX=0;
    int maxY=0;
    for(auto r : rectangle)
    {
        for(int i=r[1]*2;i<=r[3]*2;i++)
        {
            for(int j=r[0]*2;j<=r[2]*2;j++)
            {
                map[i][j]=1;
            }
        }
    }
    //사각형 안쪽까지 모두 1으로
    for(auto r: rectangle)
    {
        for(int i=r[1]*2+1;i<r[3]*2;i++)
        {
            for(int j=r[0]*2+1;j<r[2]*2;j++)
            {
                map[i][j]=0;
            }
        }
    }
    //사각형 테두리 제외한 안쪽 공간 0으로 => 테두리만 1으로
    
    int startX=2*characterX;
    int startY=2*characterY;
    int destX=2*itemX;
    int destY=2*itemY;
    //좌표 2배
    int cnt=-1;
    queue<pair<int,int>> q;
    q.push({startY,startX});
    while(!q.empty())
    {
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        if(y==destY&&x==destX) break;
        
        for(int i=0;i<4;i++)
        {
            int ny=y+dy[i];
            int nx=x+dx[i];
            
            if(map[ny][nx]==1)
            {
                q.push({ny,nx});
                map[ny][nx]=map[y][x]+1;
            }
        }
    }
    return map[destY][destX]/2;
}