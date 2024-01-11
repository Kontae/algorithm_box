#include <iostream>
#include <vector>
using namespace std;
int N,x,y,d,g,result;
int Map[101][101];
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
vector<int> v;

void Draw()
{
    for(int i=v.size()-1;i>=0;i--)
    {
        int nd=(v[i]+1)%4;
        x=x+dx[nd];
        y=y+dy[nd];
        Map[x][y]=1;
        v.push_back(nd);
    }
}

void Count()
{
    for(int i=0;i<101;i++)
    {
        for(int j=0;j<101;j++)
        {
            if(Map[i][j]==1&&Map[i][j+1]==1&&Map[i+1][j]==1&&Map[i+1][j+1]==1)
            {
                result++;
            }
        }
    }
    cout<<result<<'\n';
}

void inputSolve()
{
    cin>>N;
    while(N--)
    {
        cin>>x>>y>>d>>g;
        v.clear();
        Map[x][y]=1;
        x=x+dx[d];
        y=y+dy[d];
        Map[x][y]=1;
        v.push_back(d);
        while(g--)
        {
            Draw();
        }
    }
    Count();
}
int main()
{
    inputSolve();
}