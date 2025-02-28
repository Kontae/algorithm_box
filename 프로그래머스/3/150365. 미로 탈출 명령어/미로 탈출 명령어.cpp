#include <string>
#include <vector>
#include <cmath>
using namespace std;
int arr[51][51]={0,};
vector<string> answerV;
int dx[4]={1,0,0,-1};
int dy[4]={0,-1,1,0};
int desX,desY,N,M,R,C;
bool flag = false;
void FindWay(string s, int curX, int curY, int count, int k){
    if(count==k&&curX==desX&&curY==desY){
        answerV.push_back(s);
        flag=true;
        return;
    }
    if(flag){
        return;
    }
    if (k - count < abs(curX-(R-1)) + abs(curY-(C-1))){
        return;
    }
    
    for(int i=0;i<4;i++){
        int nextX=curX+dx[i];
        int nextY=curY+dy[i];
        if(nextX>=0&&nextX<N&&nextY>=0&&nextY<M){
            string dir;
            switch(i){
                case 0:
                    dir="d";
                    break;
                case 1:
                    dir="l";
                    break;
                case 2:
                    dir="r";
                    break;
                case 3:
                    dir="u";
                    break;
            }
            FindWay(s+dir,nextX,nextY,count+1,k);
        }
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    desX=r-1; desY=c-1;
    N=n; M=m;
    R=r; C=c;
    
    int minDistance = abs(x-r)+abs(y-c);
    if((k-minDistance)%2) return "impossible";
    
    FindWay("",x-1,y-1,0,k);
    
    
    return answerV.size()?answerV[0]:"impossible";
}