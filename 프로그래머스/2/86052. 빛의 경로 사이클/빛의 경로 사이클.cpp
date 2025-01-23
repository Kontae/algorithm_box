#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 우 하 좌 상
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool visited[501][501][4] = {false,};
int N, M;

int dfs(int x, int y, int d, int cycleLength, vector<string> &grid){
    if(visited[x][y][d]) return cycleLength;
    
    visited[x][y][d]=true;
    int nd=d;
    // 빛의 방향 변경
    if(grid[x][y]=='L'){
        if(d==0) nd=3;
        if(d==1) nd=0;
        if(d==2) nd=1;
        if(d==3) nd=2;
        
    }
    if(grid[x][y]=='R'){
        if(d==0) nd=1;
        if(d==1) nd=2;
        if(d==2) nd=3;
        if(d==3) nd=0;
    }
    int nx = x + dx[nd];
    int ny = y + dy[nd];
    
    if(nx<0) nx= N-1;
    if(nx>N-1) nx=0;
    if(ny<0) ny=M-1;
    if(ny>M-1) ny=0;
    
    return dfs(nx,ny,nd, cycleLength+1,grid);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    N = grid.size();
    M = grid[0].size();
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<4;k++){
                int result = dfs(i,j,k,0,grid);
                if(result) answer.push_back(result);
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}