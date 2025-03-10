#include <string>
#include <vector>
#include <tuple>
#include <iostream>
using namespace std;
// 0: 기둥, 1: 보
int map[102][102][2];
bool installFrame(int x,int y,int type, int n)
{
    // 기둥
    if(!type)
    {
        if(y==0) return true;
        if(map[x-1][y][1]&&x>0) return true;
        if(map[x][y][1]) return true;
        if(map[x][y-1][0]&&y>0) return true;
    }
    // 보
    else
    {
        if(map[x][y-1][0]&&y>0) return true;
        if(map[x+1][y-1][0]&&x<n&&y>0) return true;
        if((x>0&&map[x-1][y][1])&&(x<n&&map[x+1][y][1])) return true;
    }
    return false;
}

bool removeFrame(int x,int y,int type, int n)
{
    map[x][y][type]=0;
    if(!type)
    {
        // 기둥 설치 불가
        if(map[x][y+1][0]&&!installFrame(x,y+1,0,n)&&y<n) return false;
        // 보 설치 불가
        if(map[x-1][y+1][1]&&!installFrame(x-1,y+1,1,n)&&x>0&&y<n) return false;
        if(map[x][y+1][1]&&!installFrame(x,y+1,1,n)&&y<n) return false;
    }
    else
    {
        if(map[x][y][0]&&!installFrame(x,y,0,n)) return false;
        if(map[x+1][y][0]&&!installFrame(x+1,y,0,n)&&x<n) return false;
        if(map[x-1][y][1]&&!installFrame(x-1,y,1,n)&&x>0) return false;
        if(map[x+1][y][1]&&!installFrame(x+1,y,1,n)&&x<n) return false;
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    for(auto& bf:build_frame)
    {
        int x,y,type,status;
        tie(x,y,type,status) = make_tuple(bf[0],bf[1],bf[2],bf[3]);
        
        // 설치
        if(status)
        {
            // 가능할 경우 설치
            if(installFrame(x,y,type,n)) map[x][y][type]=1;
        }
        // 삭제
        else
        {
            // install과는 다르게 안 될 경우 다시 돌려 놓음
            if(!removeFrame(x,y,type,n)) map[x][y][type]=1;
        }
    }
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            for(int k=0;k<2;k++)
            {
                if(map[i][j][k]) answer.push_back({i,j,k});
            }
        }
    }
    return answer;
}