#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int leverMap[101][101];
int endMap[101][101];
bool leverVisit[101][101];
bool endVisit[101][101];

int solution(vector<string> maps) {
    int answer = 0;
    pair<int,int> start;
    pair<int,int> lever;
    pair<int,int> end;
    int n=maps.size();
    int m=maps[0].size();
    for(int i=0;i<maps.size();i++)
    {
        for(int j=0;j<maps[0].size();j++)
        {
            if(maps[i][j]=='S') start={i,j};
            else if(maps[i][j]=='L') lever = {i, j};
            else if(maps[i][j]=='E') end={i,j};
        }
    }
    
    queue<pair<int,int>> q;
    q.push({start.first,start.second});
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m||leverVisit[nx][ny]) continue;
            if(maps[nx][ny]=='X') continue;
            q.push({nx,ny});
            leverVisit[nx][ny]=true;
            leverMap[nx][ny]=leverMap[x][y]+1;
        }
    }
    
    q.push({lever.first,lever.second});
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m||endVisit[nx][ny]) continue;
            if(maps[nx][ny]=='X') continue;
            q.push({nx,ny});
            endVisit[nx][ny]=true;
            endMap[nx][ny]=endMap[x][y]+1;
        }
    }
    
    answer=leverMap[lever.first][lever.second]+endMap[end.first][end.second];
    if(leverMap[lever.first][lever.second]==0||endMap[end.first][end.second]==0) answer=-1;
    return answer;
}