#include <string>
#include <vector>
#include <queue>

using namespace std;
bool visited[101][101]={false,};
int answer=1e9;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void find(vector<string>& board, int count,int x,int y)
{
    if(board[x][y]=='G')
    {
        answer=answer<count?answer:count;
        return;
    }
    for(int k=0;k<4;k++)
    {
        
        int nx=x+dx[k];
        int ny=y+dy[k];
        if(nx<0||ny<0||nx>=board.size()||ny>=board[0].size()||board[nx][ny]=='D') continue;
        while(true)
        {
            nx+=dx[k];
            ny+=dy[k];
            if(nx<0||ny<0||nx>=board.size()||ny>=board[0].size()||board[nx][ny]=='D')
            {
                nx-=dx[k];
                ny-=dy[k];
                break;
            }
        }
        if(visited[nx][ny]==true) continue;
        
        visited[nx][ny]=true;
        find(board,count+1,nx,ny);
        visited[nx][ny]=false;
    }
    
}
int solution(vector<string> board) {
    int answer=1e9;
    queue<pair<pair<int,int>,int>> q;
    
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++)
        {
            if(board[i][j]=='R')
            {
                q.push({{i,j},0});
                visited[i][j]=true;
                while(!q.empty())
                {
                    int x=q.front().first.first;
                    int y=q.front().first.second;
                    int count=q.front().second;
                    q.pop();
                    if(board[x][y]=='G')
                    {
                        answer=answer<count?answer:count;
                        break;
                    }
                    for(int k=0;k<4;k++)
                        {
                            int nx=x+dx[k];
                            int ny=y+dy[k];
                            if(nx<0||ny<0||nx>=board.size()||ny>=board[0].size()||board[nx][ny]=='D') continue;
                            while(true)
                            {
                                nx+=dx[k];
                                ny+=dy[k];
                                if(nx<0||ny<0||nx>=board.size()||ny>=board[0].size()||board[nx][ny]=='D')
                                {
                                    nx-=dx[k];
                                    ny-=dy[k];
                                    break;
                                }
                            }
                            if(visited[nx][ny]==true) continue;

                            visited[nx][ny]=true;
                            q.push({{nx,ny},count+1});
                        }
                }
            }
        }
    }
    return answer==1e9?-1:answer;
}