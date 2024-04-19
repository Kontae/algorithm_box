#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> Graph(n+1,vector<int>(n+1,0));
    for(auto x:results)
    {
        Graph[x[0]][x[1]]=1;
        //x[0]이 x[1]을 이김
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(Graph[j][i]&&Graph[i][k])
                {
                    Graph[j][k]=1;
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(Graph[i][j]||Graph[j][i])cnt++;
        }
        if(cnt==n-1) answer++;
    }
    return answer;
}